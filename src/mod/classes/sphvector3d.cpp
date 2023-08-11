module;

#include <memory>
#include <cmath>

export module sphvector3d;

import vector3d;

export class SphVector3D : public ImplVector3D {
public:
    SphVector3D(double r, double theta, double phi){
        double this_r, this_theta, this_phi;
        
        this_r = (r > 0) ? r : 0;
        
        if(theta >= 0 && theta <= 180){
            double PI = std::atan2(0, -1);
            this_theta = theta * PI / 180.0;
        }else{
            this_theta = 0;
        }
        
        if(phi > -180 && phi <= 180){
            double PI = std::atan2(0, -1);
            this_phi = phi * PI / 180.0;
        }else{
            this_phi = 0;
        }
        
        setX(this_r * std::sin(this_theta) * std::cos(this_phi));
        setY(this_r * std::sin(this_theta) * std::sin(this_phi));
        setZ(this_r * std::cos(this_theta));
    }
};
