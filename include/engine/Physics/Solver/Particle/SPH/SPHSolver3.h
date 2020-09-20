//
// Created by jared on 9/15/20.
//

#ifndef PHYSZY_SPHSOLVER3_H
#define PHYSZY_SPHSOLVER3_H

#include "Physics/Solver/Particle/ParticleSystemSolver3.h"
constexpr double WATER_DENSITY = 1000.0;


namespace PHYSZY
{
    class SPHSolver3 : public ParticleSystemSolver3
    {
    public:
        SPHSolver3();
        SPHSolver3(double d, double d1, double d2);

        class Builder;
        static Builder GetBuilder();

        void SetPseudoViscosityCoefficient(double newViscosity);

        void OnAdvanceTimeStep(double timeIntervalInSeconds) override;

        double _pseudoViscosityCoefficient = 10.0;
    };

    using SPHSolver3Ptr = std::shared_ptr<SPHSolver3>;




    template <typename DerivedBuilder>
    class SPHSolverBuilderBase3
    {
    public:
        DerivedBuilder& WithTargetDensity(double targetDensity);
        DerivedBuilder& WithTargetSpacing(double targetSpacing);
        DerivedBuilder& WithRelativeKernelRadius(double relativeKernelRadius);
    protected:
        double _targetDensity = WATER_DENSITY;
        double _targetSpacing = 0.1;
        double _relativeKernelRadius = 1.8;
    };

    template <typename T>
    T& SPHSolverBuilderBase3<T>::WithTargetDensity(double targetDensity)
    {
        _targetDensity = targetDensity;
        return static_cast<T&>(*this);
    }

    template <typename T>
    T& SPHSolverBuilderBase3<T>::WithTargetSpacing(double targetSpacing)
    {
        _targetSpacing = targetSpacing;
        return static_cast<T&>(*this);
    }

    template <typename T>
    T& SPHSolverBuilderBase3<T>::WithRelativeKernelRadius(double relativeKernelRadius)
    {
        _relativeKernelRadius = relativeKernelRadius;
        return static_cast<T&>(*this);
    }




    class SPHSolver3::Builder final
            : public SPHSolverBuilderBase3<SPHSolver3::Builder>
    {
    public:
        SPHSolver3 Build() const;
        SPHSolver3Ptr BuildMakeShared() const;
    };
}
#endif //PHYSZY_SPHSOLVER3_H
