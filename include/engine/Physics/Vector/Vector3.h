//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_VECTOR3_H
#define PHYSZY_VECTOR3_H

#include "Physics/Vector/Vector.h"

namespace PHYSZY
{
    template<typename T>
    class Vector<T, 3> final
    {
    public:
        // constructor can be used in other constexpr!!!!!
        constexpr Vector() : _x(0), _y(0), _z(0) {}
        constexpr Vector(T x, T y, T z) : _x(x), _y(y), _z(z) {}


        T _x;
        T _y;
        T _z;
    };

    template <typename T>
    using Vector3 = Vector<T, 3>;

    using Vector3D = Vector3<double>;
}
#endif //PHYSZY_VECTOR3_H
