//
// Created by luck3 on 5/18/2024.
//

#include "GameObject.h"

GameObject::GameObject(): box(0,0,0,0) {
    angle_deg = 0;
    _is_dead = false;
    _started = false;
}

GameObject::~GameObject() {
    _component_array.clear();
}

void GameObject::start() {
    for (auto &component: _component_array) {
        component->start();
    }
    _started = true;
}

void GameObject::update(float dt) {
    for (int i = 0; i < _component_array.size(); i++) {
        _component_array[i]->update(dt);
    }
}

void GameObject::fixed_update() {
    for (int i = 0; i < _component_array.size(); i++) {
        _component_array[i]->fixed_update();
    }
}

void GameObject::render() {
    for (std::vector<int>::size_type i = 0; i < _component_array.size(); i++){
        _component_array[i]->render();
    }
}

bool GameObject::is_dead() {return _is_dead;}

void GameObject::request_delete() {_is_dead = true;}

Component &GameObject::add_component(Component *cpt) {
    _component_array.emplace_back(cpt);
    Component &item = *_component_array.back();
    if(_started) item.start();
    return item;
}

void GameObject::remove_component(Component &cpt) {
    for (int i = 0; i < _component_array.size(); i++) {
        if(_component_array[i].get() == &cpt) {
            _component_array.erase(_component_array.begin() + i);
            return;
        }
    }
}

Component &GameObject::get_component(std::string type) {
    for (int i = 0; i < _component_array.size(); i++) {
        if(_component_array[i]->is(type)) {
            return *_component_array[i];
        }
    }
}

void GameObject::notify_collision(GameObject &other) {
    for (int i = 0; i < _component_array.size(); i++) _component_array[i]->notify_collision();
}