//
// Created by jared on 9/22/20.
//

#ifndef PHYSZY_VECTOR3_IMPL_H
#define PHYSZY_VECTOR3_IMPL_H

#include "Vector3.h"

namespace PHYSZY
{
    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator+=(const T &v) {
        IAdd(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator+=(const Vector &v) {
        IAdd(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator-=(const T &v) {
        ISub(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator-=(const Vector &v) {
        ISub(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator*=(const T &v) {
        IMul(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator*=(const Vector &v) {
        IMul(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> &Vector<T, 3>::operator/=(const T &v) {
        IDiv(v);
        return (*this);
    }

    template <typename T>
    Vector<T, 3>& Vector<T, 3>::operator/=(const Vector& v)
    {
        IDiv(v);
        return (*this);
    }

    template<typename T>
    Vector<T, 3> operator+(const Vector<T, 3> &a) { return a; }

    template<typename T>
    Vector<T, 3> operator-(const Vector<T, 3> &a) { return Vector<T, 3>(-a.x, -a.y, -a.z); }

    template<typename T>
    Vector<T, 3> operator+(const Vector<T, 3> &a, T b) { return a.Add(b); }

    template<typename T>
    Vector<T, 3> operator+(T a, const Vector<T, 3> &b) { return b.Add(a); }

    template<typename T>
    Vector<T, 3> operator+(const Vector<T, 3> &a, const Vector<T, 3> &b) { return a.Add(b); }

    template<typename T>
    Vector<T, 3> operator-(const Vector<T, 3> &a, T b) { return a.Sub(b); }

    template<typename T>
    Vector<T, 3> operator-(T a, const Vector<T, 3> &b) { return b.RSub(a); }

    template<typename T>
    Vector<T, 3> operator-(const Vector<T, 3> &a, const Vector<T, 3> &b) { return a.Sub(b); }

    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3> &a, T b) { return a.Mul(b); }

    template<typename T>
    Vector<T, 3> operator*(T a, const Vector<T, 3> &b) { return b.Mul(a); }

    template<typename T>
    Vector<T, 3> operator*(const Vector<T, 3> &a, const Vector<T, 3> &b) { return a.Mul(b); }

    template<typename T>
    Vector<T, 3> operator/(const Vector<T, 3> &a, T b) { return a.Div(b); }

    template<typename T>
    Vector<T, 3> operator/(T a, const Vector<T, 3> &b) { return b.RDiv(a); }

    template<typename T>
    Vector<T, 3> operator/(const Vector<T, 3> &a, const Vector<T, 3> &b) { return a.Div(b); }
}
#endif //PHYSZY_VECTOR3_IMPL_H
