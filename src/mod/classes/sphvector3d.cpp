module;

#include <memory>
#include <cmath>
#include <stdexcept>

export module sphvector3d;

import vector3d;

export class SphVector3D : public ImplVector3D {
public:
    SphVector3D(double r, double theta, double phi){
        double theta_rad, phi_rad;
        constexpr double PI = std::atan2(0, -1);
        
        if(r < 0){
            throw std::logic_error("Radius cannor be negative");
        }
        
        if(theta < 0 || theta > 180){
            throw std::logic_error("Invalid theta");
        }
        
        if(phi < 0 || phi > 360){
            throw std::logic_error("Invalid phi");
        }
           
        theta_rad = theta * PI / 180.0;
        phi_rad = phi * PI / 180.0;
       
        
        setX(r * std::sin(theta_rad) * std::cos(phi_rad));
        setY(r * std::sin(theta_rad) * std::sin(phi_rad));
        setZ(r * std::cos(theta_rad));
    }
};
