//
// Created by luck3 on 5/19/2024.
//

#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#include "exceptions/GameNotStartedException.h"
#include <iostream>

std::unique_ptr<Game> Game::_instance{};

Game::Game(): _window(), _renderer() {
    if(_instance != nullptr) {
        std::cerr << "A Game instance is already running!" << std::endl;
        throw GameNotStartedException();
    }

    Settings::load();

    _instance = std::move(std::unique_ptr<Game>(this)) ;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    if(Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    Mix_AllocateChannels(32);

    if(TTF_Init() != 0) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    _window = std::move(
                std::unique_ptr<SDL_Window,SDLWindowDestroyer>(
                        SDL_CreateWindow(Settings::title.c_str(),
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         Settings::screen_width,
                                         Settings::screen_height,
                                         0
                            )
                        )
            );

    if(_window == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    _renderer = std::move(std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>(SDL_CreateRenderer(_window.get(), -1,SDL_RENDERER_ACCELERATED)));
    if(_renderer == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        throw GameNotStartedException();
    }

    _stored_state = {};
}

Game::~Game() {
    TTF_Quit();

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();

    SDL_Quit();
}

Game &Game::Instance() {
    if(!_instance) _instance = std::unique_ptr<Game>(new Game());
    return *_instance;
}

SDL_Renderer &Game::Renderer() {
    return *_renderer;
}

State &Game::current_state() {
    return *_state_stack.top();
}

void Game::push(State *state) {
    _stored_state = std::unique_ptr<State>(state);
}

void Game::run() {
    if(_stored_state == nullptr) return;
    _state_stack.push(std::move(_stored_state));
    current_state().start();

    while(!_state_stack.empty()) {
        Time::update();

        InputManager::Instance().update();

        if (current_state().pop_requested()) {
            _state_stack.pop();
            if (!_state_stack.empty()) current_state().resume();
            else break;
        }

        if (_stored_state != nullptr) {
            current_state().pause();
            _state_stack.push(std::move(_stored_state));
            current_state().start();
        }

        if (!_state_stack.empty()) {
            current_state().update();
            current_state().render();

            SDL_RenderPresent(_renderer.get());
            SDL_Delay(Settings::frame_delay);

            if (current_state().quit_requested()) while (!_state_stack.empty()) _state_stack.pop();
        }
        Resources::clear_images();
        Resources::clear_music();
        Resources::clear_sounds();
        Resources::clear_fonts();
    }
}