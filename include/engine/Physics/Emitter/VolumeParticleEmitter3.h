//
// Created by jared on 9/19/20.
//

#ifndef PHYSZY_VOLUMEPARTICLEEMITTER3_H
#define PHYSZY_VOLUMEPARTICLEEMITTER3_H

#include "Physics/Emitter/ParticleEmitter3.h"
#include "Physics/PointGenerator/PointGenerator3.h"
#include "Physics/Surface/ImplicitSurface3.h"
#include <random>

namespace PHYSZY
{
    class VolumeParticleEmitter3 final : public ParticleEmitter3
    {
    public:
        class Builder;
        static Builder GetBuilder();

        VolumeParticleEmitter3(
                const ImplicitSurface3Ptr& implicitSurface,
                const BoundingBox3D& maxRegion, double spacing,
                const Vector3D& initialVel = Vector3D(),
                const Vector3D& linearVel = Vector3D(),
                const Vector3D& angularVel = Vector3D(),
                size_t maxNumberOfParticles = std::numeric_limits<size_t>::max(),
                double jitter = 0.0, bool isOneShot = true,
                bool allowOverlapping = false, uint32_t seed = 0);

        virtual void test(){std::cout<<"VolumeParticleEmitter3"<<std::endl;}

    private:
        std::mt19937 _rng;

        ImplicitSurface3Ptr _implicitSurface;
        BoundingBox3D _maxRegion;
        double _spacing;
        Vector3D _initialVel;
        Vector3D _linearVel;
        Vector3D _angularVel;
        PointGenerator3Ptr _pointsGen;

        size_t _maxNumberOfParticles = std::numeric_limits<size_t>::max();
        size_t _numberOfEmittedParticles = 0;

        double _jitter = 0.0;
        bool _isOneShot = true;
        bool _allowOverlapping = false;

    };

    using VolumeParticleEmitter3Ptr = std::shared_ptr<VolumeParticleEmitter3>;

    class VolumeParticleEmitter3::Builder final
    {
    public:
        Builder& WithImplicitSurface(const ImplicitSurface3Ptr& implicitSurface);
        //Builder& WithSurface(const Surface3Ptr& surface);
        Builder& WithMaxRegion(const BoundingBox3D& maxRegion);
        Builder& WithSpacing(double spacing);
        //Builder& WithInitialVelocity(const Vector3D& initialVel);
        //Builder& WithLinearVelocity(const Vector3D& linearVel);
        //Builder& WithAngularVelocity(const Vector3D& angularVel);
        //Builder& WithMaxNumberOfParticles(size_t maxNumberOfParticles);
        //Builder& WithJitter(double jitter);
        Builder& WithIsOneShot(bool isOneShot);
        //Builder& WithAllowOverlapping(bool allowOverlapping);
        Builder& WithRandomSeed(uint32_t seed);
        VolumeParticleEmitter3 Build() const;
        VolumeParticleEmitter3Ptr BuildMakeShared() const;

    private:
        ImplicitSurface3Ptr _implicitSurface;
        bool _isBoundSet = false;
        BoundingBox3D _maxRegion;
        double _spacing = 0.1;
        Vector3D _initialVel;
        Vector3D _linearVel;
        Vector3D _angularVel;
        size_t _maxNumberOfParticles = std::numeric_limits<size_t>::max();
        double _jitter = 0.0;
        bool _isOneShot = true;
        bool _allowOverlapping = false;
        uint32_t _seed = 0;
    };

}



#endif //PHYSZY_VOLUMEPARTICLEEMITTER3_H
