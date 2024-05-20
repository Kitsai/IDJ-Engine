//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_RESOURCES_H
#define IDJ_ENGINE_RESOURCES_H

#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include <unordered_map>
#include <memory>
#include <string>

class Resources {
private:
    struct SDLTextureDestroyer {
        void operator()(SDL_Texture *t) {
            SDL_DestroyTexture(t);
        }
    };

    struct SDLMusicDestroyer {
        void operator()(Mix_Music *m) {
            Mix_FreeMusic(m);
        }
    };

    struct SDLChunkDestroyer {
        void operator()(Mix_Chunk *c) {
            Mix_FreeChunk(c);
        }
    };

    struct SDLFontDestroyer {
        void operator()(TTF_Font *f) {
            TTF_CloseFont(f);
        }
    };

    static std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> image_table;
    static std::unordered_map<std::string, std::shared_ptr<Mix_Music>> music_table;
    static std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> sound_table;
    static std::unordered_map<std::string, std::shared_ptr<TTF_Font>> font_table;

public:
    static std::shared_ptr<SDL_Texture> get_image(std::string file);
    static std::shared_ptr<Mix_Music> get_music(std::string file);
    static std::shared_ptr<Mix_Chunk> get_sound(std::string file);
    static std::shared_ptr<TTF_Font> get_font(std::string file, int size);

    static void clear_images();
    static void clear_music();
    static void clear_sounds();
    static void clear_fonts();
};


#endif //IDJ_ENGINE_RESOURCES_H
