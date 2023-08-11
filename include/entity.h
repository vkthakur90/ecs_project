#ifndef __ENTITIES_H__
#define __ENTITIES_H__

#include <vector3d.h>
#include <vector>
#include <functional>

struct EntityData{
    VecData pos;
    VecData vel;
    VecData ang_vel;
};

typedef std::unique_ptr<EntityData> up_EntityData;

struct IfaceEntity{
    virtual up_EntityData getEntityData() = 0;
    virtual void setPosition(up_IfaceVector3D & val) = 0;
    virtual void setVelocity(up_IfaceVector3D & val) = 0;
    virtual void setAngularVelocity(up_IfaceVector3D & val) = 0;
};

typedef std::unique_ptr<IfaceEntity> up_IfaceEntity;

typedef std::vector<up_IfaceEntity> EntityList;

typedef std::unique_ptr<bool[]> bool_arr;
typedef std::unique_ptr<double[]> double_arr;

struct EntityDataStructure{
    bool is_closed{false};
    unsigned int num_entities{0};
    bool_arr is_active{nullptr};
    double_arr accum_add{nullptr};
    double_arr accum_mul{nullptr};
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

