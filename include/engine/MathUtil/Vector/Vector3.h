//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_VECTOR3_H
#define PHYSZY_VECTOR3_H

#include "Vector.h"

namespace PHYSZY
{
    template<typename T>
    class Vector<T, 3> final
    {
    public:
        // constructor can be used in other constexpr!!!!!
        constexpr Vector() : _x(0), _y(0), _z(0) {}
        constexpr Vector(T x, T y, T z) : _x(x), _y(y), _z(z) {}
        Vector Add(T v) const{return {_x + v, _y + v, _z + v};}
        Vector Add(const Vector& v) const{return {_x + v._x, _y + v._y, _z + v._z};}
        Vector Sub(T v) const{return {_x - v, _y - v, _z - v};}
        Vector Sub(const Vector& v) const{return {_x - v._x, _y - v._y, _z - v._z};}
        Vector Mul(T v) const{return {_x * v, _y * v, _z * v};}
        Vector Mul(const Vector& v) const{return {_x * v._x, _y * v._y, _z * v._z};}
        Vector Div(T v) const{return {_x / v, _y / v, _z / v};}
        Vector Div(const Vector& v) const{return {_x / v._x, _y / v._y, _z / v._z};}

        void IAdd(const T& v) {_x += v;_y += v;_z += v;}
        void IAdd(const Vector& v){ _x += v.x;_y += v.y;_z += v.z;}
        void ISub(const T& v){_x -= v;_y -= v;_z -= v;}
        void ISub(const Vector& v){_x -= v.x;_y -= v.y;_z -= v.z;}
        void IMul(const T& v){_x *= v;_y *= v;_z *= v;}
        void IMul(const Vector& v){_x *= v.x;_y *= v.y;_z *= v.z;}
        void IDiv(const T& v){MY_ASSERT(v); _x /= v;_y /= v;_z /= v;}
        void IDiv(const Vector& v){MY_ASSERT(v._x&&v._y&&v._z);_x /= v.x;_y /= v.y;_z /= v.z;}

        // operator using const T& lvalue
        // Also return lvalue for chain operations( want number1 still available )!!!
        // so we need to call copy constructor when return!
        // rvalue can work here just because default moveconstructor does not clean the old one's value

        // A number1(1);
        // A number2(2);
        // A result = number1 + number2;
        // what the value of number1 should be? (does not change!!!!)

        // do not return a ref (both l and r) when return a temporary object in funcs!!!!
        // ALSO: do not use ref to accept return is unnecessary
        //    Vector3D &rs = (domain._lowerCorner += 6) -= 9; // rs is just a ref of the returned ref,
        //                                                    // never call the copy constructor Vector3D(Vector3D&)!!!
        //    std::cout<<rs._x<<std::endl; // -3
        //    domain._lowerCorner-=10;
        //    std::cout<<rs._x<<std::endl; // 10


        // declared your operator as a non-member function.
        // A member function takes an implicit first parameter,
        // meaning your operator now takes three parameters.
        // You can fix this by making it a non-member function.

        Vector& operator+=(const T& v);
        Vector& operator+=(const Vector& v);
        Vector& operator-=(const T& v);
        Vector& operator-=(const Vector& v);
        Vector& operator*=(const T& v);
        Vector& operator*=(const Vector& v);
        Vector& operator/=(const T& v);
        Vector& operator/=(const Vector& v);


        T _x;
        T _y;
        T _z;
    };

    template <typename T>
    using Vector3 = Vector<T, 3>;
    using Vector3D = Vector3<double>;
}

#include "MathUtil/Vector/Vector3-Impl.h"



#endif //PHYSZY_VECTOR3_H
