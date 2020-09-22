//
// Created by jared on 9/22/20.
//

#include "engine/Physics/Collider/Collider3.h"
namespace PHYSZY
{
    Collider3::Builder Collider3::GetBuilder()
    {
        return {};
    }

    Collider3::Collider3(Surface3Ptr surface)
            :_surface(surface)
    {

    }

    Collider3 Collider3::Builder::Build() const
    {
        return {_surface};
    }

    Collider3Ptr Collider3::Builder::BuildMakeShared() const
    {
        return PHYSZY::Collider3Ptr();
    }
}