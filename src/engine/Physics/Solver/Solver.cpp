//
// Created by jared on 9/14/20.
//

#include "engine/Physics/Solver/Solver.h"
namespace PHYSZY
{

    Solver::~Solver()
    {

    }

    void Solver::update(double elapsedTime)
    {
        OnAdvanceTimeStep(elapsedTime);
    }

    std::shared_ptr<Solver> Solver::getBasePtr()
    {
        return shared_from_this();
    }
}