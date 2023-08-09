module;

#include <memory>
#include <cmath>

export module cartvector3d;

import vector3d;

export {
    class CartVector3D : public Vector3D {
    public:
        CartVector3D(double x, double y, double z){
            setX(x);
            setY(y);
            setZ(z);
        }
    };
}