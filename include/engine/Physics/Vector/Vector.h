//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_VECTOR_H
#define PHYSZY_VECTOR_H

#include "Physics/Vector/VectorExpression.h"

namespace PHYSZY
{
    template<typename T, size_t N>
    class Vector final : public VectorExpression<T, Vector<T, N>> {

    };
}
#endif //PHYSZY_VECTOR_H
