//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_DEFINES_CPP
#define IDJ_ENGINE_DEFINES_CPP

#include "SDL2/SDL.h"

namespace fyrebird {
//COLORS
    constexpr SDL_Color COLOR_BLACK = {0, 0, 0, SDL_ALPHA_OPAQUE};
    constexpr SDL_Color COLOR_WHITE = {255, 255, 255, SDL_ALPHA_OPAQUE};
    constexpr SDL_Color COLOR_GRAY = {130, 130, 130, SDL_ALPHA_OPAQUE};
    constexpr SDL_Color COLOR_RED = {255, 0, 0, SDL_ALPHA_OPAQUE};
    constexpr SDL_Color COLOR_GREEN = {0, 255, 0, SDL_ALPHA_OPAQUE};
    constexpr SDL_Color COLOR_BLUE = {0, 0, 255, SDL_ALPHA_OPAQUE};

//KEYS
    constexpr SDL_KeyCode LEFT_ARROW_KEY = SDLK_LEFT;
    constexpr SDL_KeyCode RIGHT_ARROW_KEY = SDLK_RIGHT;
    constexpr SDL_KeyCode UP_ARROW_KY = SDLK_DOWN;

    constexpr SDL_KeyCode ESCAPE_KEY = SDLK_ESCAPE;
    constexpr SDL_KeyCode TAB_KEY = SDLK_TAB;
    constexpr SDL_KeyCode CAPS_KEY = SDLK_CAPSLOCK;
    constexpr SDL_KeyCode LSHIFT_KEY = SDLK_LSHIFT;
    constexpr SDL_KeyCode LCTRL_KEY = SDLK_LCTRL;
    constexpr SDL_KeyCode LALT_KEY = SDLK_LALT;
    constexpr SDL_KeyCode BACKSPACE_KEY = SDLK_BACKSPACE;
    constexpr SDL_KeyCode ENTER_KEY = SDLK_RETURN;
    constexpr SDL_KeyCode RSHIFT_KEY = SDLK_RSHIFT;
    constexpr SDL_KeyCode RCTRL_KEY = SDLK_RCTRL;
    constexpr SDL_KeyCode RALT_KEY = SDLK_RALT;

    constexpr SDL_KeyCode F1_KEY = SDLK_F1;
    constexpr SDL_KeyCode F2_KEY = SDLK_F2;
    constexpr SDL_KeyCode F3_KEY = SDLK_F3;
    constexpr SDL_KeyCode F4_KEY = SDLK_F4;
    constexpr SDL_KeyCode F5_KEY = SDLK_F5;
    constexpr SDL_KeyCode F6_KEY = SDLK_F6;
    constexpr SDL_KeyCode F7_KEY = SDLK_F7;
    constexpr SDL_KeyCode F8_KEY = SDLK_F8;
    constexpr SDL_KeyCode F9_KEY = SDLK_F9;
    constexpr SDL_KeyCode F10_KEY = SDLK_F10;
    constexpr SDL_KeyCode F11_KEY = SDLK_F11;
    constexpr SDL_KeyCode F12_KEY = SDLK_F12;

    constexpr SDL_KeyCode NUM_1_KEY = SDLK_1;
    constexpr SDL_KeyCode NUM_2_KEY = SDLK_2;
    constexpr SDL_KeyCode NUM_3_KEY = SDLK_3;
    constexpr SDL_KeyCode NUM_4_KEY = SDLK_4;
    constexpr SDL_KeyCode NUM_5_KEY = SDLK_5;
    constexpr SDL_KeyCode NUM_6_KEY = SDLK_6;
    constexpr SDL_KeyCode NUM_7_KEY = SDLK_7;
    constexpr SDL_KeyCode NUM_8_KEY = SDLK_8;
    constexpr SDL_KeyCode NUM_9_KEY = SDLK_9;

    constexpr SDL_KeyCode Q_KEY = SDLK_q;
    constexpr SDL_KeyCode W_KEY = SDLK_w;
    constexpr SDL_KeyCode E_KEY = SDLK_e;
    constexpr SDL_KeyCode R_KEY = SDLK_r;
    constexpr SDL_KeyCode T_KEY = SDLK_t;
    constexpr SDL_KeyCode Y_KEY = SDLK_y;
    constexpr SDL_KeyCode U_KEY = SDLK_u;
    constexpr SDL_KeyCode I_KEY = SDLK_i;
    constexpr SDL_KeyCode O_KEY = SDLK_o;
    constexpr SDL_KeyCode P_KEY = SDLK_p;
    constexpr SDL_KeyCode A_KEY = SDLK_a;
    constexpr SDL_KeyCode S_KEY = SDLK_s;
    constexpr SDL_KeyCode D_KEY = SDLK_d;
    constexpr SDL_KeyCode F_KEY = SDLK_f;
    constexpr SDL_KeyCode G_KEY = SDLK_g;
    constexpr SDL_KeyCode H_KEY = SDLK_h;
    constexpr SDL_KeyCode J_KEY = SDLK_j;
    constexpr SDL_KeyCode K_KEY = SDLK_k;
    constexpr SDL_KeyCode L_KEY = SDLK_l;
    constexpr SDL_KeyCode Z_KEY = SDLK_z;
    constexpr SDL_KeyCode X_KEY = SDLK_x;
    constexpr SDL_KeyCode C_KEY = SDLK_c;
    constexpr SDL_KeyCode V_KEY = SDLK_v;
    constexpr SDL_KeyCode B_KEY = SDLK_b;
    constexpr SDL_KeyCode N_KEY = SDLK_n;
    constexpr SDL_KeyCode M_KEY = SDLK_m;

//MOUSE BUTTONS
    constexpr int LEFT_MOUSE_BUTTON = SDL_BUTTON_LEFT;
    constexpr int MIDDLE_MOUSE_BUTTON = SDL_BUTTON_MIDDLE;
    constexpr int RIGHT_MOUSE_BUTTON = SDL_BUTTON_RIGHT;
    constexpr int X1_MOUSE_BUTTON = SDL_BUTTON_X1;
    constexpr int X2_MOUSE_BUTTON = SDL_BUTTON_X2;
}
#endif //IDJ_ENGINE_DEFINES_CPP
