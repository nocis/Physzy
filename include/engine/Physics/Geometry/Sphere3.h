//
// Created by jared on 9/20/20.
//

#ifndef PHYSZY_SPHERE3_H
#define PHYSZY_SPHERE3_H

#include "MathUtil/Vector/Vector3.h"
#include "Physics/Surface/Surface3.h"

namespace PHYSZY
{
    class Sphere3 final : public Surface3{
    public:
        class Builder;
        static Builder GetBuilder();

        Sphere3(const Transform3& transform = Transform3(),
                bool isNormalFlipped = false);
        Sphere3(const Vector3D& center, double radius,
                const Transform3& transform = Transform3(),
                bool isNormalFlipped = false);
        Sphere3(const Sphere3& other);
        Sphere3& operator=(const Sphere3& other) = default;

        Vector3D _center;
        double _radius = 1.0;

    };

    using Sphere3Ptr = std::shared_ptr<Sphere3>;

    class Sphere3::Builder : public SurfaceBuilderBase3<Sphere3::Builder>
    {
    public:
        Builder& WithCenter(Vector3D&& center);
        Builder& WithRadius(double&& radius);
        Sphere3 Build() const;
        Sphere3Ptr BuildMakeShared() const;

    private:
        Vector3D _center = { 0, 0, 0 };
        double _radius = 0.0;
    };

}

#endif //PHYSZY_SPHERE3_H
