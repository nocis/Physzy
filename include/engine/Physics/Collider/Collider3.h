//
// Created by jared on 9/22/20.
//

#ifndef PHYSZY_COLLIDER3_H
#define PHYSZY_COLLIDER3_H

#include "Physics/Collider/Collider.h"
#include "Physics/Surface/Surface3.h"
namespace PHYSZY
{

    class Collider3 : public Collider {
    public:
        class Builder;
        static Builder GetBuilder();

        Collider3(Surface3Ptr surface);
    private:
        Surface3Ptr _surface;
        double _frictionCoeffient = 0.0;
    };

    using Collider3Ptr = std::shared_ptr<Collider3>;

    template<typename DerivedBuilder>
    class ColliderBuilderBase
    {
    public:
        DerivedBuilder& WithSurface(const Surface3Ptr& surface);
    protected:
        Surface3Ptr _surface;
    };

    template<typename DerivedBuilder>
    DerivedBuilder &ColliderBuilderBase<DerivedBuilder>::WithSurface(const Surface3Ptr &surface)
    {
        _surface = surface;
        return static_cast<DerivedBuilder &>(*this);
    }

    class Collider3::Builder: ColliderBuilderBase<Collider3::Builder>
    {
        Collider3 Build() const;
        virtual Collider3Ptr BuildMakeShared() const;
    };


}
#endif //PHYSZY_COLLIDER3_H
