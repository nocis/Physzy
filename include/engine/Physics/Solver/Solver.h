//
// Created by jared on 9/14/20.
//

#ifndef PHYSZY_SOLVER_H
#define PHYSZY_SOLVER_H

#include <memory>
#include "Core/mylogger.h"
namespace PHYSZY
{
    // Base class
    class Solver : public std::enable_shared_from_this<Solver>
    {
    public:
        virtual ~Solver();

        std::shared_ptr<Solver> getBasePtr();
        virtual void update(double elapsedTime);
        virtual void OnAdvanceTimeStep(double timeIntervalInSeconds)=0;
        virtual void OnBeginAdvanceTimeStep(double timeIntervalInSeconds) {}
        virtual void OnEndAdvanceTimeStep(double timeIntervalInSeconds) {}
    };

    using SolverPtr = std::shared_ptr<Solver>;
}

#endif //PHYSZY_SOLVER_H
