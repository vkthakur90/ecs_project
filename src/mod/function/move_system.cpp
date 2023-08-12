#include <iostream>
#include <entity.h>
#include <system.h>

void move_system(up_EntityDataStructure & e, double delta_time){
    
    auto N = e->num_entities;
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(e->pos.has_comp[i] && e->vel.has_comp){
            e->pos.x[i] += e->vel.x[i] * delta_time;
        }
    }
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(e->pos.has_comp[i] && e->vel.has_comp){
            e->pos.y[i] += e->vel.y[i] * delta_time;
        }
    }
    
    #pragma omp parallel for
    for(int i = 0; i < N; i++){
        if(e->pos.has_comp[i] && e->vel.has_comp){
            e->pos.z[i] += e->vel.z[i] * delta_time;
        }
    }
}
