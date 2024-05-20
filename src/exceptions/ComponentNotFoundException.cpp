//
// Created by luck3 on 5/18/2024.
//

#include "ComponentNotFoundException.h"

ComponentNotFoundException::ComponentNotFoundException(const std::string& type):
message(std::string("Component ") + type + std::string (" not found in game object"))
{}

const char *ComponentNotFoundException::what() const noexcept {
    return message.c_str();
}