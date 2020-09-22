//
// Created by jared on 9/20/20.
//

#include "engine/Physics/Geometry/Sphere3.h"
namespace PHYSZY
{
    Sphere3::Builder Sphere3::GetBuilder()
    {
        return {};
    }

    Sphere3::Sphere3(const Transform3 &transform, bool isNormalFlipped)
           : Surface3(transform, isNormalFlipped)
    {

    }

    Sphere3::Sphere3(const Vector3D &center, double radius, const Transform3 &transform, bool isNormalFlipped)
            : Surface3(transform, isNormalFlipped), _radius(radius), _center(center)
    {

    }

    Sphere3::Sphere3(const Sphere3 &other)
            : Surface3(other._transform, other._isNormalFlipped), _center(other._center),
              _radius(other._radius)
    {

    }

    Sphere3::Builder &Sphere3::Builder::WithCenter(Vector3D&& center)
    {
        _center = center;
        return *this;
    }

    Sphere3::Builder &Sphere3::Builder::WithRadius(double&& radius)
    {
        _radius = radius;
        return *this;
    }

    Sphere3 Sphere3::Builder::Build() const
    {
        // return a temporary object, and initialize the lvalue by calling copy construct.
        // should not return a reference because of temporary object!!!!!
        return {_center, _radius, _transform, _isNormalFlipped};
    }

    Sphere3Ptr Sphere3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<Sphere3>(
                new Sphere3(_center, _radius, _transform, _isNormalFlipped)
                , [](Sphere3 *obj){delete obj; });
    }
}