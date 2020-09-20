//
// Created by jared on 9/15/20.
//

#include <engine/Physics/Solver/Particle/SPH/SPHSolver3.h>
#include "SPH1.h"

SPH1 sph1;

void SPH1::initialize()
{
    BoundingBox3D domain({}, {1, 2, 1});

    auto solver = SPHSolver3::GetBuilder()
            .WithTargetDensity(1000.0)
            .WithTargetSpacing(0.02)
            .BuildMakeShared();

    solver->SetPseudoViscosityCoefficient(0.0);

    auto collider = new Collider();


    BoundingBox3D sourceBound(domain);

    /*

    sourceBound.Expand(-targetSpacing);

    const auto plane = Plane3::GetBuilder()
                           .WithNormal({ 0, 1, 0 })
                           .WithPoint({ 0, 0.25 * domain.GetHeight(), 0 })
                           .MakeShared();

    const auto sphere = Sphere3::GetBuilder()
                            .WithCenter(domain.MidPoint())
                            .WithRadius(0.15 * domain.GetWidth())
                            .MakeShared();

    const auto surfaceSet = ImplicitSurfaceSet3::GetBuilder()
                                .WithExplicitSurfaces({ plane, sphere })
                                .MakeShared();

     auto emitter = VolumeParticleEmitter3::GetBuilder()
            .WithImplicitSurface(surfaceSet)
            .WithSpacing(targetSpacing)
            .WithMaxRegion(sourceBound)
            .WithIsOneShot(true)
            .MakeShared();

    solver->SetEmitter(emitter);*/
    solver->setCollider(collider);

    // a temporary can not bind to a non-const reference.
    setSolver(solver->getBasePtr());
    // shared_from_this solverptr's life is end now! so total count is two!
}

void SPH1::update(float elapsedTime)
{

}


