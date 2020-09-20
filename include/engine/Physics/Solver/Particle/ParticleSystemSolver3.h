//
// Created by jared on 9/15/20.
//

#ifndef PHYSZY_PARTICLESYSTEMSOLVER3_H
#define PHYSZY_PARTICLESYSTEMSOLVER3_H

#include "Physics/Emitter/Emitter.h"
#include "Physics/Collider/Collider.h"
#include "Physics/Solver/Solver.h"
namespace PHYSZY
{
    class ParticleSystemSolver3 : public Solver
    {
    public:
        // derive from builderbase
        class Builder;

        ParticleSystemSolver3();
        ParticleSystemSolver3(double radius, double mass);
        virtual ~ParticleSystemSolver3();
        void OnAdvanceTimeStep( double timeIntervalInSeconds ) override;
        void setEmitter( Emitter *pEmitter );
        void setCollider( Collider *pCollider );


        static Builder GetBuilder();
    private:
        Emitter* _emitter;
        Collider* _collider;
    };

    using ParticleSystemSolver3Ptr = std::shared_ptr<ParticleSystemSolver3>;

    template <typename DerivedBuilder>
    class ParticleSystemSolverBuilderBase3
    {
    public:
        DerivedBuilder& WithRadius(double radius);
        DerivedBuilder& WithMass(double mass);

    protected:
        double _radius = 1e-3;
        double _mass = 1e-3;
    };

    template <typename T>
    T& ParticleSystemSolverBuilderBase3<T>::WithRadius(double radius)
    {
        _radius = radius;
        return static_cast<T&>(*this);
    }

    template <typename T>
    T& ParticleSystemSolverBuilderBase3<T>::WithMass(double mass)
    {
        _mass = mass;
        return static_cast<T&>(*this);
    }

    class ParticleSystemSolver3::Builder final
            : public ParticleSystemSolverBuilderBase3<ParticleSystemSolver3::Builder>
    {
    public:
        ParticleSystemSolver3 Build() const;
        ParticleSystemSolver3Ptr BuildMakeShared() const;
    };
}

#endif //PHYSZY_PARTICLESYSTEMSOLVER3_H
