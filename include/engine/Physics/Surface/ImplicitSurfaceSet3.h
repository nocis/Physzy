//
// Created by jared on 9/21/20.
//

#ifndef PHYSZY_IMPLICITSURFACESET3_H
#define PHYSZY_IMPLICITSURFACESET3_H

#include <vector>
#include "Physics/Surface/ImplicitSurface3.h"

namespace PHYSZY
{
    class ImplicitSurfaceSet3 final : public ImplicitSurface3{
    public:
        class Builder;
        static Builder GetBuilder();

        ImplicitSurfaceSet3();
        ImplicitSurfaceSet3(std::vector<ImplicitSurface3Ptr>  surfaces,
                            const Transform3& transform = Transform3(),
                            bool isNormalFlipped = false);

        ImplicitSurfaceSet3(const std::vector<Surface3Ptr>& surfaces,
                            const Transform3& transform = Transform3(),
                            bool isNormalFlipped = false);

        ImplicitSurfaceSet3(const ImplicitSurfaceSet3& other);

    private:
        std::vector<ImplicitSurface3Ptr> _surfaces;
        std::vector<ImplicitSurface3Ptr> _unboundedSurfaces;
        //mutable BVH3<ImplicitSurface3Ptr> _bvh;
        mutable bool _bvhInvalidated = true;


    };


    using ImplicitSurfaceSet3Ptr = std::shared_ptr<ImplicitSurfaceSet3>;

    class ImplicitSurfaceSet3::Builder final
            : public SurfaceBuilderBase3<ImplicitSurfaceSet3::Builder>
    {
    public:
        Builder& WithSurfaces(const std::vector<ImplicitSurface3Ptr>& surfaces);
        Builder& WithExplicitSurfaces(const std::vector<Surface3Ptr>& surfaces);
        ImplicitSurfaceSet3 Build() const;
        ImplicitSurfaceSet3Ptr BuildMakeShared() const;
    private:
        bool _isNormalFlipped = false;
        std::vector<ImplicitSurface3Ptr> _surfaces;
    };
}

#endif //PHYSZY_IMPLICITSURFACESET3_H
