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

#endif 

