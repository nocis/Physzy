//
// Created by jared on 9/19/20.
//

#include "engine/Physics/Surface/Surface3.h"
namespace PHYSZY
{

    Surface3::Surface3(const Transform3 &transform, bool isNormalFlipped)
            : _transform(transform), _isNormalFlipped(isNormalFlipped)
    {

    }
}