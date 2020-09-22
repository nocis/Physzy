//
// Created by jared on 9/21/20.
//

#include "engine/Physics/Surface/ImplicitSurfaceSet3.h"

#include <utility>
namespace PHYSZY
{
    ImplicitSurfaceSet3::Builder ImplicitSurfaceSet3::GetBuilder()
    {
        return {};
    }

    ImplicitSurfaceSet3::ImplicitSurfaceSet3()
    {

    }

    ImplicitSurfaceSet3::ImplicitSurfaceSet3(std::vector<ImplicitSurface3Ptr> surfaces,
                                             const Transform3 &transform, bool isNormalFlipped)
            : ImplicitSurface3(transform, isNormalFlipped), _surfaces(std::move(surfaces))
    {

    }

    ImplicitSurfaceSet3::ImplicitSurfaceSet3(const std::vector<Surface3Ptr> &surfaces, const Transform3 &transform,
                                             bool isNormalFlipped)
            : ImplicitSurface3(transform, isNormalFlipped)
    {

    }

    ImplicitSurfaceSet3::ImplicitSurfaceSet3(const ImplicitSurfaceSet3 &other)
            : ImplicitSurface3(other),
              _surfaces(other._surfaces),
              _unboundedSurfaces(other._unboundedSurfaces)
    {

    }


    ImplicitSurfaceSet3::Builder &
    ImplicitSurfaceSet3::Builder::WithSurfaces(const std::vector<ImplicitSurface3Ptr> &surfaces)
    {
        _surfaces = surfaces;
        return *this;;
    }

    ImplicitSurfaceSet3::Builder &
    ImplicitSurfaceSet3::Builder::WithExplicitSurfaces(const std::vector<Surface3Ptr> &surfaces)
    {
        _surfaces.clear();

        for (const auto& surface : surfaces)
        {
            //_surfaces.push_back(std::make_shared<SurfaceToImplicit3>(surface));
        }

        return *this;
    }

    ImplicitSurfaceSet3 ImplicitSurfaceSet3::Builder::Build() const
    {
        return {_surfaces, _transform, _isNormalFlipped };
    }

    ImplicitSurfaceSet3Ptr ImplicitSurfaceSet3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<ImplicitSurfaceSet3>(
                new ImplicitSurfaceSet3(_surfaces, _transform, _isNormalFlipped),
                [](ImplicitSurfaceSet3* obj) { delete obj; });
    }
}