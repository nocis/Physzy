//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_IMPLICITSURFACE3_H
#define PHYSZY_IMPLICITSURFACE3_H

#include "Physics/Surface/Surface3.h"
namespace PHYSZY
{
    class ImplicitSurface3 : public Surface3
    {
    public:
        //default
        ImplicitSurface3(const Transform3& transform = Transform3(),
                         bool isNormalFlipped = false);
    };

    using ImplicitSurface3Ptr = std::shared_ptr<ImplicitSurface3>;
}
#endif //PHYSZY_IMPLICITSURFACE3_H
