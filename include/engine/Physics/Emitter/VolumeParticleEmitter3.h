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



        VolumeParticleEmitter3(
                const ImplicitSurface3Ptr& implicitSurface,
                const BoundingBox3D& maxRegion, double spacing,
                const Vector3D& initialVel = Vector3D(),
                const Vector3D& linearVel = Vector3D(),
                const Vector3D& angularVel = Vector3D(),
                size_t maxNumberOfParticles = std::numeric_limits<size_t>::max(),
                double jitter = 0.0, bool isOneShot = true,
                bool allowOverlapping = false, uint32_t seed = 0);

    private:
        std::mt19937 m_rng;

        ImplicitSurface3Ptr m_implicitSurface;
        BoundingBox3D m_maxRegion;
        double m_spacing;
        Vector3D m_initialVel;
        Vector3D m_linearVel;
        Vector3D m_angularVel;
        PointGenerator3Ptr m_pointsGen;

        size_t m_maxNumberOfParticles = std::numeric_limits<size_t>::max();
        size_t m_numberOfEmittedParticles = 0;

        double m_jitter = 0.0;
        bool m_isOneShot = true;
        bool m_allowOverlapping = false;

    };
}



#endif //PHYSZY_VOLUMEPARTICLEEMITTER3_H
