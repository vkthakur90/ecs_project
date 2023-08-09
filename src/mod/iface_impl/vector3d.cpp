module;

#include <vector3d.h>

export module vector3d;

export {
    class Vector3D : public IfaceVector3D {
    public:
        inline double getX() override {return x;}
        inline double getY() override {return y;}
        inline double getZ() override {return z;}
    protected:
        inline void setX(double val) {x = val;}
        inline void setY(double val) {y = val;}
        inline void setZ(double val) {z = val;}
    private:
        double x{0};
        double y{0};
        double z{0};
    };
}

