//
// Created by jared on 9/13/20.
//

#ifndef PHYSZY_PHYSICSCONTROLLER_H
#define PHYSZY_PHYSICSCONTROLLER_H

#include "Physics/Solver/Solver.h"

#include "UsefulMacro.h"
namespace PHYSZY
{
    class PhysicsController
    {
    public:
        PhysicsController();
        ~PhysicsController();
        void update(double elapsedTime);

        void setSolver(SolverPtr& pSolver);

    private:
        SolverPtr _solver;

    };
}



#endif //PHYSZY_PHYSICSCONTROLLER_H
