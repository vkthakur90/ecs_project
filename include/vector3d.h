#ifndef __IFACE_VECTOR_3D__
#define __IFACE_VECTOR_3D__

#include <iostream>
#include <memory>
#include <cstdint>

struct VecComp {
    std::unique_ptr<bool[]> has_comp{nullptr};
    std::unique_ptr<double[]> x{nullptr};
    std::unique_ptr<double[]> y{nullptr};
    std::unique_ptr<double[]> z{nullptr};
};

struct VecData {
    bool has_comp;
    double x;
    double y;
    double z;
};

struct IfaceVector3D{
    virtual inline double getX() = 0;
    virtual inline double getY() = 0;
    virtual inline double getZ() = 0; 
};

typedef std::unique_ptr<IfaceVector3D> up_IfaceVector3D; 

up_IfaceVector3D get_CartVector3D(double x, double y, double z);  
up_IfaceVector3D get_CylVector3D(double r, double theta, double z);
up_IfaceVector3D get_SphVector3D(double r, double theta, double phi);

#endif 


