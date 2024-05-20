//
// Created by luck3 on 5/18/2024.
//

#ifndef IDJ_ENGINE_STATE_H
#define IDJ_ENGINE_STATE_H

#include <set>
#include <memory>
#include "GameObject.h"

class State {
protected:
    class Compare {
    public:
        bool operator()(const std::shared_ptr<GameObject>& a,const std::shared_ptr<GameObject>& b) const;
    };
    bool _pop_requested;
    bool _quit_requested;
    bool _started;

    std::set<std::shared_ptr<GameObject>, Compare> _object_set;

    void start_array();
    virtual void update_array();
    virtual void render_array();
    virtual void check_collisions();
    virtual void delete_objects();

public:
    State();
    virtual ~State();

    virtual void load_assets() = 0;
    virtual void update();
    virtual void fixed_update();
    virtual void render();

    virtual void start();
    virtual void pause();
    virtual void resume();

    virtual std::weak_ptr<GameObject> add_object(GameObject *go);
    void remove_object(GameObject *go);
    virtual std::weak_ptr<GameObject> get_obj_ptr(GameObject *go);

    bool pop_requested() const;
    bool quit_requested() const;

};


#endif //IDJ_ENGINE_STATE_H
