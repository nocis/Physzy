//
// Created by jared on 9/20/20.
//

#include "engine/Physics/Geometry/Plane3.h"
namespace PHYSZY
{

    Plane3::Builder Plane3::GetBuilder()
    {
        return {};
    }

    Plane3::Plane3(const Transform3 &transform, bool isNormalFlipped)
            : Surface3(transform, isNormalFlipped)
    {

    }

    Plane3::Plane3(const Vector3D &normal, const Vector3D &point, const Transform3 &transform, bool isNormalFlipped)
            : Surface3(transform, isNormalFlipped), _normal(normal), _point(point)
    {

    }

    Plane3::Builder &Plane3::Builder::WithNormal(Vector3D&& normal)
    {
        _normal = normal;
        return (*this);
    }

    Plane3::Builder &Plane3::Builder::WithPoint(Vector3D&& point)
    {
        _point = point;
        return (*this);
    }

    Plane3 Plane3::Builder::Build() const
    {
        // return a temporary object, and initialize the lvalue by calling copy construct.
        // should not return a reference because of temporary object!!!!!
        return {_normal, _point, _transform, _isNormalFlipped};
    }

    Plane3Ptr Plane3::Builder::BuildMakeShared() const
    {
        // SHARED PTR point to a lvalue object!!!!
        return std::shared_ptr<Plane3>(
                new Plane3(_normal, _point, _transform, _isNormalFlipped),
                [](Plane3* obj) { delete obj; });
    }
}