#include <iostream>
#include <memory>
#include <cmath>
#include <vector3d.h>
#include <entity.h>
#include <game_register.h>

import cartvector3d;
import cylvector3d;
import sphvector3d;
import game_register;

    
up_IfaceVector3D get_CylVector3D(double r, double theta, double z){
    return std::make_unique<CylVector3D>(r, theta, z);
}

up_IfaceVector3D get_SphVector3D(double r, double theta, double phi){
    return std::make_unique<SphVector3D>(r, theta, phi);
}

up_IfaceVector3D get_CartVector3D(double x, double y, double z){
    return std::make_unique<CartVector3D>(x, y, z);
}

up_IfaceGameRegister get_GameRegister(EntityList & el, SystemList & sl){
    return std::make_unique<GameRegister>(el, sl); 
}
