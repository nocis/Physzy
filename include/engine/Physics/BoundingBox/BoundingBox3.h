//Physics
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_BOUNDINGBOX3_H
#define PHYSZY_BOUNDINGBOX3_H



#include "Physics/BoundingBox/BoundingBox.h"
#include "MathUtil/Vector/Vector3.h"

namespace PHYSZY
{
    template <typename T>
    class BoundingBox<T, 3>
    {
    public:
        BoundingBox(){}
        BoundingBox( Vector3<T>&& point1, Vector3<T>&& point2){}
        BoundingBox( const Vector3<T>& point1, const Vector3<T>& point2){}

        //constexpr can be passed as s rvalue
        void Expand(T&& delta)
        {
            // named lvalue using const T&
            _lowerCorner -= delta;
            _upperCorner += delta;
        }


        T GetWidth() const
        {
            return _upperCorner._x - _lowerCorner._x;
        }

        T GetHeight() const
        {
            return _upperCorner._y - _lowerCorner._y;
        }

        Vector3<T> MidPoint() const
        {
            return (_upperCorner + _lowerCorner) / static_cast<T>(2);
        }


        Vector3<T> _lowerCorner;
        Vector3<T> _upperCorner;
    };

    template <typename T>
    using BoundingBox3 = BoundingBox<T, 3>;
    using BoundingBox3D = BoundingBox3<double>;
}

#endif //PHYSZY_BOUNDINGBOX3_H