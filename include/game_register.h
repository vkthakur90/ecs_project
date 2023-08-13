#ifndef __GAME_REGISTER_H__
#define __GAME_REGISTER_H__ 

#include <entity.h>
#include <iostream>
#include <functional>

struct EntityDataStructure{
    bool is_closed{false};
    unsigned int num_entities{0};
    bool_arr is_active{nullptr};
    struct {
        double_arr add{nullptr};
        double_arr mul{nullptr};
    } accum;
    VecComp pos{nullptr};
    VecComp vel{nullptr};
    VecComp ang_vel{nullptr};
};

typedef std::unique_ptr<EntityDataStructure> up_EntityDataStructure;

typedef std::function<void(up_EntityDataStructure &)> system_fn;

typedef std::vector<system_fn> SystemList;

struct IfaceGameRegister{
    virtual void displayState(std::ostream & out) = 0;
    virtual void update() = 0;
};

typedef std::unique_ptr<IfaceGameRegister> up_IfaceGameRegister;

up_IfaceGameRegister get_GameRegister(EntityList & el, SystemList & sl);

#endif