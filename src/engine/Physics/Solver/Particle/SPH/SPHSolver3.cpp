//
// Created by jared on 9/15/20.
//

#include "engine/Physics/Solver/Particle/SPH/SPHSolver3.h"
namespace PHYSZY
{

    SPHSolver3::SPHSolver3()
        :SPHSolver3(WATER_DENSITY, 0.1, 1.8)
    {

    }

    SPHSolver3::SPHSolver3(double targetDensity, double targetSpacing, double relativeKernelRadius)
    {

    }

    void SPHSolver3::OnAdvanceTimeStep(double timeIntervalInSeconds)
    {
        _pseudoViscosityCoefficient = 0.0;
        LOG_INFO<<"SPHSolver3::OnAdvanceTimeStep";
    }

    void SPHSolver3::SetPseudoViscosityCoefficient(
            double newViscosity)
    {
        _pseudoViscosityCoefficient = std::max(newViscosity, 0.0);
    }


    SPHSolver3::Builder SPHSolver3::GetBuilder()
    {
        return {};
    }

    SPHSolver3 SPHSolver3::Builder::Build() const
    {
        return SPHSolver3(_targetDensity, _targetSpacing, _relativeKernelRadius);
    }

    SPHSolver3Ptr SPHSolver3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<SPHSolver3>(
                new SPHSolver3(_targetDensity, _targetSpacing, _relativeKernelRadius),
                [](SPHSolver3* obj) { delete obj; }
        );
    }
}