#ifndef __SYSTEM_H__
#define __SYSTEM_H__ 

#include <entity.h>

class MoveSystem{
private:
    double delta_time;
public:
    MoveSystem(double dt) : delta_time{dt} {}
    
    void operator()(up_EntityData & e);
};

#endif