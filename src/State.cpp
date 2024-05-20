//
// Created by luck3 on 5/18/2024.
//

#include "State.h"
#include "components/Collider.h"

bool State::Compare::operator()(const std::shared_ptr<GameObject>& a, const std::shared_ptr<GameObject>& b) const {
    return a->box.z > b->box.z;
}

void State::start_array() {
    for (const auto &i: _object_set) {
        i->start();
    }
}

void State::update_array() {
    for (const auto &i: _object_set) {
        i->update();
    }
}

void State::render_array() {
    for (const auto &i: _object_set) {
        i->render();
    }
}

void State::check_collisions() {
    for (auto i = _object_set.begin();
    i != _object_set.end();
    i++) {
        auto collider_a = std::static_pointer_cast<Collider>((*i)->get_component("Collider").lock());
        if(collider_a && collider_a->active) {
            for(auto j = i; j != _object_set.end(); j++) {
                auto collider_b = std::static_pointer_cast<Collider>((*j)->get_component("Collider").lock());
                if(collider_b
                && collider_a != collider_b
                && collider_b -> active
                && collider_a->is_colliding(collider_b->box,(*j)->angle_deg)
                ) {
                    (*i)->notify_collision(**j);
                    (*j)->notify_collision(**i);
                }
            }
        }
    }
}

void State::delete_objects() {
    for(auto i = _object_set.begin(); i != _object_set.end(); i++)
        if((*i)->is_dead()) _object_set.erase(i);
}

State::State():
        _pop_requested(false),
        _quit_requested(false),
        _started(false)
{}

State::~State() {
    _object_set.clear();
}

void State::update() {
    update_array();
}

void State::fixed_update() {

}

void State::render() {
    render_array();
}

void State::start() {
    start_array();
}

void State::pause() {}

void State::resume() {}

std::weak_ptr<GameObject> State::add_object(GameObject *go) {
    std::shared_ptr<GameObject> ptr{go};
    _object_set.insert(ptr);
    if(_started) ptr->start();

    return ptr;
}

void State::remove_object(GameObject *go) {

    for(auto i = _object_set.begin(); i != _object_set.end(); i++)
        if((*i).get() == go) {
            _object_set.erase(i);
            break;
        }
}

std::weak_ptr<GameObject> State::get_obj_ptr(GameObject *go) {
    for(const auto& i: _object_set)
        if(i.get() == go)
            return i;
    return std::shared_ptr<GameObject>();
}

bool State::pop_requested() const {
    return _pop_requested;
}

bool State::quit_requested() const {
    return _quit_requested;
}