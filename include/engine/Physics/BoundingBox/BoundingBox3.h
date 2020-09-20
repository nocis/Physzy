//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_BOUNDINGBOX3_H
#define PHYSZY_BOUNDINGBOX3_H



#include "Physics/BoundingBox/BoundingBox.h"
#include "Physics/Vector/Vector3.h"

namespace PHYSZY
{
    template <typename T>
    class BoundingBox<T, 3>
    {
    public:
        BoundingBox(){}
        BoundingBox( Vector3<T>&& point1, Vector3<T>&& point2){}

    };

    template <typename T>
    using BoundingBox3 = BoundingBox<T, 3>;
    using BoundingBox3D = BoundingBox3<double>;
}

#endif //PHYSZY_BOUNDINGBOX3_H