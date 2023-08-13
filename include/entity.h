#ifndef __ENTITIES_H__
#define __ENTITIES_H__

#include <vector3d.h>
#include <vector>
#include <functional>

struct Entity{
    up_IfaceVector3D pos{nullptr};
    up_IfaceVector3D vel{nullptr};
    up_IfaceVector3D ang_vel{nullptr};
};

typedef std::unique_ptr<Entity> up_Entity;
typedef std::vector<up_Entity> EntityList;

typedef std::unique_ptr<bool[]> bool_arr;
typedef std::unique_ptr<double[]> double_arr;

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
    virtual void displayState() = 0;
    virtual void update() = 0;
};

typedef std::unique_ptr<IfaceGameRegister> up_IfaceGameRegister;


up_IfaceGameRegister get_GameRegister(EntityList & el, SystemList & sl);

#endif 

