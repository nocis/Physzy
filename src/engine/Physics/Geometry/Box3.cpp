//
// Created by jared on 9/22/20.
//

#include "engine/Physics/Geometry/Box3.h"
namespace PHYSZY
{

    Box3::Box3(const Transform3 &transform, bool isNormalFlipped)
            :Surface3(transform, isNormalFlipped)
    {

    }


    Box3::Box3(const BoundingBox3D &boundingBox, const Transform3 &transform, bool isNormalFlipped)
            :Surface3(transform, isNormalFlipped), _bbx(boundingBox)
    {

    }

    Box3::Builder Box3::GetBuilder()
    {
        return {};
    }

    Box3::Builder &Box3::Builder::WithLowerCorner(const Vector3D &pt)
    {
        _lowerCorner = pt;
        return *this;
    }

    Box3::Builder &Box3::Builder::WithUpperCorner(const Vector3D &pt)
    {
        _upperCorner = pt;
        return *this;
    }

    Box3::Builder &Box3::Builder::WithBoundingBox(const BoundingBox3D &bbox)
    {
        _lowerCorner = bbox._lowerCorner;
        _upperCorner = bbox._upperCorner;
        return *this;
    }

    Box3 Box3::Builder::Build() const
    {
        return {{_lowerCorner,_upperCorner},_transform, _isNormalFlipped};
    }

    Box3Ptr Box3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<Box3>(new Box3({_lowerCorner,_upperCorner}, _transform, _isNormalFlipped) ,
                [](Box3* obj){delete obj;});
    }
}