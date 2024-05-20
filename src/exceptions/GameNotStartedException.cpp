//
// Created by luck3 on 5/19/2024.
//

#include "GameNotStartedException.h"

GameNotStartedException::GameNotStartedException() = default;

const char *GameNotStartedException::what() const noexcept {
    return "Game not able to be constructed";
}