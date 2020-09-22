//
// Created by jared on 9/19/20.
//

#include "engine/Physics/Emitter/VolumeParticleEmitter3.h"

namespace PHYSZY
{

    VolumeParticleEmitter3::VolumeParticleEmitter3(const ImplicitSurface3Ptr &implicitSurface,
                                                   const BoundingBox3D &maxRegion, double spacing,
                                                   const Vector3D &initialVel, const Vector3D &linearVel,
                                                   const Vector3D &angularVel, size_t maxNumberOfParticles,
                                                   double jitter, bool isOneShot, bool allowOverlapping,
                                                   uint32_t seed)
            : _rng(seed),
              _implicitSurface(implicitSurface),
              _maxRegion(maxRegion),
              _spacing(spacing),
              _initialVel(initialVel),
              _linearVel(linearVel),
              _angularVel(angularVel),
              _maxNumberOfParticles(maxNumberOfParticles),
              _jitter(jitter),
              _isOneShot(isOneShot),
              _allowOverlapping(allowOverlapping)
    {

    }

    VolumeParticleEmitter3::Builder VolumeParticleEmitter3::GetBuilder()
    {
        return {};
    }

    VolumeParticleEmitter3::Builder &
    VolumeParticleEmitter3::Builder::WithImplicitSurface(const ImplicitSurface3Ptr &implicitSurface)
    {
        _implicitSurface = implicitSurface;
        return *this;
    }

    VolumeParticleEmitter3::Builder &VolumeParticleEmitter3::Builder::WithMaxRegion(const BoundingBox3D &maxRegion)
    {
        _maxRegion = maxRegion;
        return *this;
    }

    VolumeParticleEmitter3::Builder &VolumeParticleEmitter3::Builder::WithSpacing(double spacing)
    {
        _spacing = spacing;
        return *this;
    }

    VolumeParticleEmitter3::Builder &VolumeParticleEmitter3::Builder::WithIsOneShot(bool isOneShot)
    {
        _isOneShot = isOneShot;
        return *this;
    }

    VolumeParticleEmitter3::Builder&
    VolumeParticleEmitter3::Builder::WithRandomSeed(uint32_t seed)
    {
        _seed = seed;
        return *this;
    }

    VolumeParticleEmitter3 VolumeParticleEmitter3::Builder::Build() const
    {
        return { _implicitSurface, _maxRegion, _spacing,
                                      _initialVel, _linearVel, _angularVel,
                                      _maxNumberOfParticles, _jitter, _isOneShot,
                                      _allowOverlapping, _seed};
    }

    VolumeParticleEmitter3Ptr VolumeParticleEmitter3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<VolumeParticleEmitter3>(
                new VolumeParticleEmitter3(_implicitSurface, _maxRegion, _spacing,
                                           _initialVel, _linearVel, _angularVel,
                                           _maxNumberOfParticles, _jitter, _isOneShot,
                                           _allowOverlapping, _seed),
                [](VolumeParticleEmitter3* obj) { delete obj; });
    }
}