#ifndef __SYSTEM_H__
#define __SYSTEM_H__ 

#include <entity.h>
#include <game_register.h>

class MoveSystem{
private:
    double delta_time;
public:
    MoveSystem(double dt);
    void operator()(up_EntityDataStructure & e) noexcept;
};


#endif