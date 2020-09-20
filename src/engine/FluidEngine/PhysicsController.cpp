//
// Created by jared on 9/13/20.
//
#include "Physics/Solver/Grid/GridFluidSolver3.h"
#include "engine/FluidEngine/PhysicsController.h"
namespace PHYSZY
{
    PhysicsController::PhysicsController()
        :_solver(nullptr)
    {

    }

    PhysicsController::~PhysicsController()
    {
        SAFE_DELETE( _solver );
    }

    void PhysicsController::update(double elapsedTime)
    {
        MY_ASSERT(_solver);
        _solver->update(elapsedTime);
    }

    void PhysicsController::setSolver(SolverPtr& pSolver)
    {
        // 1: sph1.cpp--sphsolver3ptr
        // 2: shared_from_this--solverptr
        // 2&: pSolver
        MY_ASSERT(pSolver);
        SAFE_DELETE( _solver );
        _solver = pSolver;
        // 3: _solver
    }
}