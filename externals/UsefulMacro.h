//
// Created by jared on 9/10/20.
// FROM gameplay3d
//

#ifndef PHYSZY_USEFULMACRO_H
#define PHYSZY_USEFULMACRO_H

#include <assert.h>


/*
template <typename T>
class is_pointer_type
{
    typedef struct { char array[1]; } yes;
    typedef struct { char array[2]; } no;

    template <typename C> static yes test_g(decltype(&C::get));
    template <typename C> static no  test_g(...);

    template <typename C> static yes test_e(typename C::element_type*);
    template <typename C> static no  test_e(...);

    enum {
        has_get          = sizeof(test_g<T>(0)) == sizeof(yes),
        has_element_type = sizeof(test_e<T>(0)) == sizeof(yes)
    };

    template <typename Q, bool OK = false>
    struct get { struct type {}; };

    template <typename Q>
    struct get<Q, true>
    {
        typedef decltype(((Q*)nullptr)->get()) type;
    };

    template <typename Q, bool OK = false>
    struct ptr { struct type {}; };

    template <typename Q>
    struct ptr<Q, true>
    {
        typedef typename Q::element_type* type;
    };

public:
    enum {
        types_ok = std::is_same<
                typename get<T, has_get>::type,
                typename ptr<T, has_element_type>::type
        >::value,
        value    = std::is_convertible<T, void*>::value || types_ok
    };
};
*/


// Assert macros.
#ifdef NDEBUG
#define MY_ASSERT(expression)
#else
#define MY_ASSERT(expression) assert(expression)
#endif
#define SAFE_DELETE(x) \
    { \
    }

// Array deletion macro
#define SAFE_DELETE_ARRAY(x) \
    { \
        delete[] x; \
        x = NULL; \
    }

// Ref cleanup macro
#define SAFE_RELEASE(x) \
    if (x) \
    { \
        (x)->release(); \
        x = NULL; \
    }

// Math
#define MATH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
#define MATH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
#define MATH_RANDOM_MINUS1_1()      ((2.0f*((float)rand()/RAND_MAX))-1.0f)      // Returns a random float between -1 and 1.
#define MATH_RANDOM_0_1()           ((float)rand()/RAND_MAX)                    // Returns a random float between 0 and 1.
#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_E                      2.71828182845904523536f
#define MATH_LOG10E                 0.4342944819032518f
#define MATH_LOG2E                  1.442695040888963387f
#define MATH_PI                     3.14159265358979323846f
#define MATH_PIOVER2                1.57079632679489661923f
#define MATH_PIOVER4                0.785398163397448309616f
#define MATH_PIX2                   6.28318530717958647693f
#define MATH_EPSILON                0.000001f
#define MATH_CLAMP(x, lo, hi)       ((x < lo) ? lo : ((x > hi) ? hi : x))
#ifndef M_1_PI
#define M_1_PI                      0.31830988618379067154
#endif


#endif //PHYSZY_USEFULMACRO_H
