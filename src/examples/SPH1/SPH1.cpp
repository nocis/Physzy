//
// Created by jared on 9/15/20.
//

#include <engine/Physics/Solver/Particle/SPH/SPHSolver3.h>
#include <engine/Physics/Geometry/Plane3.h>
#include <engine/Physics/Surface/ImplicitSurfaceSet3.h>
#include <engine/Physics/Geometry/Box3.h>
#include <engine/Physics/Collider/RigidBodyCollider3.h>
#include "SPH1.h"

SPH1 sph1;

void SPH1::initialize()
{
    BoundingBox3D domain({}, {1, 2, 1});
    constexpr double targetspc = 0.02;
    auto solver = SPHSolver3::GetBuilder()
            .WithTargetDensity(1000.0)
            .WithTargetSpacing(targetspc)
            .BuildMakeShared();

    solver->SetPseudoViscosityCoefficient(0.0);

    BoundingBox3D sourceBound(domain);
    sourceBound.Expand(-targetspc);

    auto plane = Plane3::GetBuilder()
            .WithNormal({ 0, 1, 0 })
            .WithPoint({ 0, 0.25 * domain.GetHeight(), 0 })
            .BuildMakeShared();

    auto sphere = Sphere3::GetBuilder()
            .WithCenter(domain.MidPoint())
            .WithRadius(0.15 * domain.GetWidth())
            .BuildMakeShared();

    auto surfaceSet = ImplicitSurfaceSet3::GetBuilder()
            .WithExplicitSurfaces({ plane, sphere })
            .BuildMakeShared();

    auto emitter = VolumeParticleEmitter3::GetBuilder()
            .WithImplicitSurface(surfaceSet)
            .WithSpacing(targetspc)
            .WithMaxRegion(sourceBound)
            .WithIsOneShot(true)
            .BuildMakeShared();

    solver->setEmitter(static_cast<EmitterPtr>(emitter));


    auto box = Box3::GetBuilder()
            .WithIsNormalFlipped(true)
            .WithBoundingBox(domain)
            .BuildMakeShared();


    auto collider = RigidBodyCollider3::GetBuilder()
            .WithSurface(box)
            .BuildMakeShared();

    solver->setCollider(static_cast<ColliderPtr>(collider));
    // a temporary can not bind to a non-const reference.

    //// SolverPtr &&fuck = solver;
    //// smartpointer has moveconstructor?!?!
    //// no ! old value does not clean
    //// possible reason is because :
    ////      1. auto cast VolumeParticleEmitter3Ptr to SolverPtr
    ////      2. pass temporary SolverPtr object to copy constructor
    ////      3. copy construct

    std::cout<<solver.use_count()<<std::endl;
    // setSolver(solver); works but unclear!!!
    setSolver(static_cast<SolverPtr>(solver));
    // shared_from_this solverptr's life is end now! so total count is two!
}

void SPH1::update(float elapsedTime)
{

}


