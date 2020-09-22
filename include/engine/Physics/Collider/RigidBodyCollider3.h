//
// Created by jared on 9/22/20.
//

#ifndef PHYSZY_RIGIDBODYCOLLIDER3_H
#define PHYSZY_RIGIDBODYCOLLIDER3_H

#include "Physics/Collider/Collider3.h"
#include "MathUtil/Vector/Vector3.h"


namespace PHYSZY
{
    class RigidBodyCollider3 : public Collider3{
    public:
        class Builder;
        static Builder GetBuilder();

        RigidBodyCollider3(const Surface3Ptr& surface);

        RigidBodyCollider3(const Surface3Ptr& surface,
                           const Vector3D& linearVelocity,
                           const Vector3D& angularVelocity);


        Vector3D _linearVelocity;
        Vector3D _angularVelocity;

    };

    using RigidBodyCollider3Ptr = std::shared_ptr<RigidBodyCollider3>;

    class RigidBodyCollider3::Builder final : public ColliderBuilderBase<RigidBodyCollider3::Builder>
    {
    public:
        Builder& WithLinearVelocity(const Vector3D& linearVelocity);
        Builder& WithAngularVelocity(const Vector3D& angularVelocity);
        RigidBodyCollider3 Build() const;
        RigidBodyCollider3Ptr BuildMakeShared() const;

    private:
        Vector3D _linearVelocity{ 0, 0, 0 };
        Vector3D _angularVelocity{ 0, 0, 0 };
    };
}

#endif //PHYSZY_RIGIDBODYCOLLIDER3_H
