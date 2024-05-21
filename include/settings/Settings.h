//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_SETTINGS_H
#define IDJ_ENGINE_SETTINGS_H

#include <string>

namespace fyrebird {
    constexpr int NUM_SETTINGS_LINES = 4;

    class Settings {
    public:
        static void load();

        static std::string title;
        static int screen_width;
        static int screen_height;
        static int frame_delay;
    };
}

#endif //IDJ_ENGINE_SETTINGS_H
