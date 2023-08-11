module;

#include <memory>
#include <cmath>

export module cylvector3d;

import vector3d;
   
export class CylVector3D : public ImplVector3D {
public:
    CylVector3D(double r, double theta, double z){
        double this_r, this_theta;
        
        this_r = (r > 0) ? r : 0;
        
        double PI = std::atan2(0, -1);
        this_theta = theta * PI / 180.0;
        
        
        setX(this_r * std::cos(this_theta));
        setY(this_r * std::sin(this_theta));
        setZ(z);
    }
};
