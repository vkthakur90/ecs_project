module;

#include <entity.h>
#include <vector3d.h>

export module entity;

export class ImplEntity : public IfaceEntity {
public:
    ImplEntity(){
        ed.pos.has_comp = false;
        ed.vel.has_comp = false;
        ed.ang_vel.has_comp = false;
    }

    up_EntityData getEntityData() override final {
        up_EntityData data = std::make_unique<EntityData>();
        
        data->pos.x = ed.pos.x;
        data->pos.y = ed.pos.y;
        data->pos.z = ed.pos.z;
        data->pos.has_comp = ed.pos.has_comp;
        
        data->vel.x = ed.vel.x;
        data->vel.y = ed.vel.y;
        data->vel.z = ed.vel.z;
        data->vel.has_comp = ed.vel.has_comp;
        
        data->ang_vel.x = ed.ang_vel.x;
        data->ang_vel.y = ed.ang_vel.y;
        data->ang_vel.z = ed.ang_vel.z;
        data->ang_vel.has_comp = ed.ang_vel.has_comp;
            
        return std::move(data);
    }
    
    void setPosition(up_IfaceVector3D & val) override final{
        ed.pos.x = val->getX();
        ed.pos.y = val->getY();
        ed.pos.z = val->getZ();
        ed.pos.has_comp = true;
    }
    
    void setVelocity(up_IfaceVector3D & val) override final {
        ed.vel.x = val->getX();
        ed.vel.y = val->getY();
        ed.vel.z = val->getZ();
        ed.vel.has_comp = true;
    }
    
    void setAngularVelocity(up_IfaceVector3D & val) override final{
        ed.ang_vel.x = val->getX();
        ed.ang_vel.y = val->getY();
        ed.ang_vel.z = val->getZ();
        ed.ang_vel.has_comp = true;
    }

private:
    EntityData ed;
    
};
