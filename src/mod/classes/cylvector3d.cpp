module;

#include <memory>
#include <cmath>
#include <stdexcept>

export module cylvector3d;

import vector3d;
   
export class CylVector3D : public ImplVector3D {
public:
    CylVector3D(double r, double theta, double z){
        double theta_rad;
        
        if(r < 0){
            throw std::logic_error("Radius cannor be negative");
        }
        
        if(theta < 0 || theta > 360){
            throw std::logic_error("Invalid theta");
        }
        
        constexpr double PI = std::atan2(0, -1);
        theta_rad = theta * PI / 180.0;
         
        setX(r * std::cos(theta_rad));
        setY(r * std::sin(theta_rad));
        setZ(z);
    }
};
