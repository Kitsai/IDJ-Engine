//
// Created by luck3 on 5/19/2024.
//

#include "Resources.h"
#include "Game.h"

#include <iostream>

std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Resources::image_table = {};
std::unordered_map<std::string, std::shared_ptr<Mix_Music>> Resources::music_table = {};
std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> Resources::sound_table = {};
std::unordered_map<std::string, std::shared_ptr<TTF_Font>> Resources::font_table = {};

std::shared_ptr<SDL_Texture> Resources::get_image(std::string file) {
    if(image_table.find(file) != image_table.end()) return image_table[file];

    std::shared_ptr<SDL_Texture> image = std::shared_ptr<SDL_Texture>(
            IMG_LoadTexture(&Game::Instance().Renderer(), file.data()),
            SDLTextureDestroyer()
            );
    if(image == nullptr) {
        std::cerr << "Error trying to load image: " << file <<std::endl;
        return nullptr;
    }

    image_table[file] = image;
    return image;
}

std::shared_ptr<Mix_Music> Resources::get_music(std::string file) {
    if(music_table.find(file) != music_table.end()) return music_table[file];

    std::shared_ptr<Mix_Music> music = std::shared_ptr<Mix_Music> (
            Mix_LoadMUS(file.data()),
            SDLMusicDestroyer()
            );

    if(music == nullptr) {
        std::cerr << "Error trying to load music: " << file<< std::endl;
        return nullptr;
    }

    music_table[file] = music;
    return music;
}

std::shared_ptr<Mix_Chunk> Resources::get_sound(std::string file) {
    if(sound_table.find(file) != sound_table.end()) return sound_table[file];

    std::shared_ptr<Mix_Chunk> sound = std::shared_ptr<Mix_Chunk> (
            Mix_LoadWAV(file.data()),
            SDLChunkDestroyer()
    );

    if(sound == nullptr) {
        std::cerr << "Error trying to load sound: " << file <<std::endl;
        return nullptr;
    }

    sound_table[file] = sound;
    return sound;
}

std::shared_ptr<TTF_Font> Resources::get_font(std::string file, int size) {
    std::string key = file + std::to_string(size);
    if(font_table.find(key) != font_table.end()) return font_table[key];

    std::shared_ptr<TTF_Font> font = std::shared_ptr<TTF_Font> (
            TTF_OpenFont(file.data(),size),
            SDLFontDestroyer()
            );

    if(font == nullptr) {
        std::cerr << "Error trying to load font: " << file <<std::endl;
        return nullptr;
    }

    font_table[key] = font;
    return font;
}

void Resources::clear_images() {
    for(const auto& i: image_table)
        if(i.second.unique())
            image_table.erase(i.first);
}

void Resources::clear_music() {
    for(const auto& i: music_table)
        if(i.second.unique())
            image_table.erase(i.first);
}

void Resources::clear_sounds() {
    for(const auto& i: sound_table)
        if(i.second.unique())
            sound_table.erase(i.first);
}

void Resources::clear_fonts() {
    for(const auto& i: font_table) {
        if(i.second.unique())
            font_table.erase(i.first);
    }
}