//
// Created by jared on 9/14/20.
//

#ifndef PHYSZY_GRIDFLUIDSOLVER3_H
#define PHYSZY_GRIDFLUIDSOLVER3_H

#include "Physics/Solver/Solver.h"
namespace PHYSZY
{
    // cannot case to private base class
    class GridFluidSolver3 : public Solver
    {
    public:
        void OnAdvanceTimeStep(double timeIntervalInSeconds) override;
    };
}

#endif //PHYSZY_GRIDFLUIDSOLVER3_H
