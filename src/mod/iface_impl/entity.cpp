module;

#include <entity.h>

export module entity;

export class ImplEntity : public IfaceEntity {
public:
    up_EntityData getEntityData() override final {
        up_EntityData data = std::make_unique<EntityData>();
        
        if(pos != nullptr){
            data->pos.x = pos->getX();
            data->pos.y = pos->getY();
            data->pos.z = pos->getZ();
            data->pos.has_comp = true;
        } else {
            data->pos.has_comp = false;
        }
        
        if(vel != nullptr){
            data->vel.x = vel->getX();
            data->vel.y = vel->getY();
            data->vel.z = vel->getZ();
            data->vel.has_comp = true;
        } else {
            data->vel.has_comp = false;
        }
        
        if(ang_vel != nullptr){
            data->ang_vel.x = ang_vel->getX();
            data->ang_vel.y = ang_vel->getY();
            data->ang_vel.z = ang_vel->getZ();
            data->ang_vel.has_comp = true;
        } else {
            data->ang_vel.has_comp = false;
        }
        
        return std::move(data);
    }
    
protected:
    void setPosition(up_IfaceVector3D & val){
        pos = std::move(val);
    }
    
    void setVelocity(up_IfaceVector3D & val){
        pos = std::move(val);
    }
    
    void setAngularVelocity(up_IfaceVector3D & val){
        pos = std::move(val);
    }
    
private:
    up_IfaceVector3D pos{nullptr};
    up_IfaceVector3D vel{nullptr};
    up_IfaceVector3D ang_vel{nullptr};
    

};
