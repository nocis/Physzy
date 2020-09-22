//
// Created by jared on 9/20/20.
//

#ifndef PHYSZY_PLANE3_H
#define PHYSZY_PLANE3_H

#include "MathUtil/Vector/Vector3.h"
#include "MathUtil/Transform/Transform3.h"
#include "Physics/Surface/Surface3.h"

namespace PHYSZY
{
    class Plane3 final : public Surface3{

    public:
        class Builder;
        // need to return a temporary object, so no reference
        static Builder GetBuilder();

        Plane3(const Transform3& transform = Transform3(),
               bool isNormalFlipped = false);

        Plane3(const Vector3D& normal, const Vector3D& point,
               const Transform3& transform = Transform3(),
               bool isNormalFlipped = false);

        Vector3D _normal = Vector3D(0, 1, 0);
        Vector3D _point;
    };

    using Plane3Ptr = std::shared_ptr<Plane3>;

    class Plane3::Builder final : public SurfaceBuilderBase3<Plane3::Builder>
    {
    public:
        Builder& WithNormal(Vector3D&& normal);
        Builder& WithPoint(Vector3D&& point);
        Plane3 Build() const;
        Plane3Ptr BuildMakeShared() const;

    private:
        Vector3D _normal{ 0, 1, 0 };
        Vector3D _point{ 0, 0, 0 };
    };

}
#endif //PHYSZY_PLANE3_H
