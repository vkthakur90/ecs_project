#include <iostream>
#include <entity.h>
#include <system.h>

void move_system(up_EntityDataStructure & e, double delta_time){
    
    auto N = e->num_entities;
    
    auto & has_pos = e->pos.has_comp;
    auto & has_vel = e->vel.has_comp;
    
    auto & pos_x = e->pos.x;
    auto & vel_x = e->vel.x;
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(has_pos[i] && has_vel[i]){
            pos_x[i] += vel_x[i] * delta_time;
        }
    }
    
    auto & pos_y = e->pos.y;
    auto & vel_y = e->vel.y;
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(has_pos[i] && has_vel[i]){
            pos_y[i] += vel_y[i] * delta_time;
        }
    }
    
    auto & pos_z = e->pos.z;
    auto & vel_z = e->vel.z;
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(has_pos[i] && has_vel[i]){
            pos_z[i] += vel_z[i] * delta_time;
        }
    }
}
