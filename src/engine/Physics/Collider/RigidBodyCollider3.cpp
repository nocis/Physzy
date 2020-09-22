//
// Created by jared on 9/22/20.
//

#include "engine/Physics/Collider/RigidBodyCollider3.h"
namespace PHYSZY
{

    RigidBodyCollider3::Builder RigidBodyCollider3::GetBuilder()
    {
        return {};
    }

    RigidBodyCollider3::RigidBodyCollider3(const Surface3Ptr &surface)
            :Collider3(surface)
    {

    }

    RigidBodyCollider3::RigidBodyCollider3(const Surface3Ptr &surface, const Vector3D &linearVelocity,
                                           const Vector3D &angularVelocity)
                                           :Collider3(surface),
                                           _linearVelocity(linearVelocity),
                                           _angularVelocity(angularVelocity)
    {

    }

    RigidBodyCollider3::Builder &RigidBodyCollider3::Builder::WithLinearVelocity(const Vector3D &linearVelocity)
    {
        _linearVelocity = linearVelocity;
        return *this;
    }

    RigidBodyCollider3::Builder &RigidBodyCollider3::Builder::WithAngularVelocity(const Vector3D &angularVelocity)
    {
        _angularVelocity = angularVelocity;
        return *this;
    }

    RigidBodyCollider3 RigidBodyCollider3::Builder::Build() const
    {
        return {_surface, _linearVelocity, _angularVelocity};
    }

    RigidBodyCollider3Ptr RigidBodyCollider3::Builder::BuildMakeShared() const
    {
        return RigidBodyCollider3Ptr(new RigidBodyCollider3(_surface, _linearVelocity, _angularVelocity)
                , [](RigidBodyCollider3* obj){delete obj;});
    }
}