//
// Created by luck3 on 5/18/2024.
//

#include "Component.h"

Component::Component(GameObject &assoc): _associated(assoc) {}
Component::~Component() = default;

void Component::update() {}

void Component::fixed_update() {}

void Component::render() {}

void Component::start() {}

void Component::notify_collision(GameObject &other) {}