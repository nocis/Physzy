//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_SURFACE3_H
#define PHYSZY_SURFACE3_H

#include <memory>
#include "MathUtil/Transform/Transform3.h"
namespace PHYSZY
{
    class Surface3
    {
    public:
        Surface3(const Transform3& transform = Transform3(),
                 bool isNormalFlipped = false);

        Transform3 _transform;
        bool _isNormalFlipped = false;

    };

    using Surface3Ptr = std::shared_ptr<Surface3>;


    // return the builder to make the chain invoke!!!!!
    template <typename DerivedBuilder>
    class SurfaceBuilderBase3
    {
    public:
        DerivedBuilder& WithIsNormalFlipped(bool isNormalFlipped);
        //DerivedBuilder& WithTranslation(const Vector3D& translation);
        //DerivedBuilder& WithOrientation(const QuaternionD& orientation);
        //DerivedBuilder& WithTransform(const Transform3& transform);

    protected:
        bool _isNormalFlipped = false;
        Transform3 _transform;
    };

    template<typename DerivedBuilder>
    DerivedBuilder &SurfaceBuilderBase3<DerivedBuilder>::WithIsNormalFlipped(bool isNormalFlipped)
    {
        _isNormalFlipped = isNormalFlipped;
        return static_cast<DerivedBuilder&>(*this);
    }

}
#endif //PHYSZY_SURFACE3_H
