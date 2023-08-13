module;

#include <iostream>
#include <vector>
#include <game_register.h>

export module game_register;

export class GameRegister final : public IfaceGameRegister {
private:
    up_EntityDataStructure e_data{nullptr}; 
    SystemList system_list;
protected:
    void allocate_vector_component(VecComp & vc, unsigned int num_entities){
        vc.has_comp = std::make_unique<bool[]>(num_entities);
        vc.x = std::make_unique<double[]>(num_entities);
        vc.y = std::make_unique<double[]>(num_entities);
        vc.z = std::make_unique<double[]>(num_entities);
    }

    up_EntityDataStructure allocate(unsigned int num_entities){
        up_EntityDataStructure ed = std::make_unique<EntityDataStructure>();
        
        ed->num_entities = num_entities;
        ed->is_closed = false; 

        ed->is_active = std::make_unique<bool[]>(num_entities);
        
        ed->accum.add = std::make_unique<double[]>(num_entities);
        ed->accum.mul = std::make_unique<double[]>(num_entities);
        
        allocate_vector_component(ed->pos, num_entities);
        allocate_vector_component(ed->vel, num_entities);
        allocate_vector_component(ed->ang_vel, num_entities);
                                                                                                                    
        return std::move(ed);
    }
    
    void initialize_vector_component(unsigned int i, VecComp & vc, up_IfaceVector3D & vec){
        if(vec != nullptr){
            vc.has_comp[i] = true;
            vc.x[i] = vec->getX();
            vc.y[i] = vec->getY();
            vc.z[i] = vec->getZ();
        }else{
            vc.has_comp[i] = false;
        }
    }
    
    void initialize_entities(EntityList & entity_list){
        for(unsigned int i = 0; i < e_data->num_entities; i++){
            e_data->is_active[i] = true;
            e_data->pos.has_comp[i] = false;
            e_data->vel.has_comp[i] = false;
            e_data->ang_vel.has_comp[i] = false;
            
            initialize_vector_component(i, e_data->pos, entity_list[i]->pos);
            initialize_vector_component(i, e_data->vel, entity_list[i]->vel);
            initialize_vector_component(i, e_data->ang_vel, entity_list[i]->ang_vel);
        }
    }
    
    
public:
    GameRegister(EntityList & entity_list, SystemList & sl){
        unsigned int N = entity_list.size();
        
        e_data = allocate(N);
        initialize_entities(entity_list);
        
        for(auto & s : sl){
            system_list.push_back(s);
        }
    }

    void update() override {
        for(auto & sys : system_list){
            sys(e_data);
        }
    }    
    
    void displayState() override {
        std::cout << '\n' << "ENTITIES : " << e_data->num_entities << "\n\n";
        for(unsigned int i = 0; i < e_data->num_entities; i++){
            std::cout << '\n' << "Entity ID : " << i << '\n';
            
            if(e_data->pos.has_comp[i]){
                std::cout << "Position : " << e_data->pos.x[i] << ' ' << e_data->pos.y[i] << ' ' << e_data->pos.z[i] << '\n'; 
            }
            
            if(e_data->vel.has_comp[i]){
                std::cout << "Velocity : " << e_data->vel.x[i] << ' ' << e_data->vel.y[i] << ' ' << e_data->vel.z[i] << '\n'; 
            }
            
            if(e_data->ang_vel.has_comp[i]){
                std::cout << "Angular Velocity : " << e_data->ang_vel.x[i] << ' ' << e_data->ang_vel.y[i] << ' ' << e_data->ang_vel.z[i] << '\n'; 
            }
        }
    }
};

