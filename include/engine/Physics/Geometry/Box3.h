//
// Created by jared on 9/22/20.
//

#ifndef PHYSZY_BOX3_H
#define PHYSZY_BOX3_H

#include <engine/MathUtil/Vector/Vector3.h>
#include <PhyszyEngine.h>
#include "Physics/Surface/Surface3.h"

namespace PHYSZY
{
    class Box3 final : public Surface3{
    public:
        class Builder;
        static Builder GetBuilder();
        Box3(const Transform3& transform = Transform3(),
               bool isNormalFlipped = false);

        Box3(const BoundingBox3D& boundingBox,
                      const Transform3& transform = Transform3(),
                      bool isNormalFlipped = false);

        BoundingBox3D _bbx = BoundingBox3D(Vector3D(), Vector3D(1.0, 1.0, 1.0));
    };

    using Box3Ptr = std::shared_ptr<Box3>;

    class Box3::Builder : public SurfaceBuilderBase3<Box3::Builder>
    {
    public:
        Builder& WithLowerCorner(const Vector3D& pt);
        Builder& WithUpperCorner(const Vector3D& pt);
        Builder& WithBoundingBox(const BoundingBox3D& bbox);
        Box3 Build() const;
        Box3Ptr BuildMakeShared() const;
    private:
        Vector3D _lowerCorner{ 0, 0, 0 };
        Vector3D _upperCorner{ 1, 1, 1 };
    };

}

#endif //PHYSZY_BOX3_H
