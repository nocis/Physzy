//
// Created by jared on 9/15/20.
//
#include "UsefulMacro.h"
#include "engine/Physics/Solver/Particle/ParticleSystemSolver3.h"
namespace PHYSZY
{

    ParticleSystemSolver3::ParticleSystemSolver3()
            : ParticleSystemSolver3(1e-3, 1e-3)
    {

    }

    ParticleSystemSolver3::ParticleSystemSolver3(double radius, double mass)
            : _collider(nullptr), _emitter(nullptr)
    {
        /*m_particleSystemData = std::make_shared<ParticleSystemData3>();
        m_particleSystemData->SetRadius(radius);
        m_particleSystemData->SetMass(mass);
        m_wind = std::make_shared<ConstantVectorField3>(Vector3D());*/
    }


    ParticleSystemSolver3::~ParticleSystemSolver3()
    {
        SAFE_DELETE( _emitter );
        SAFE_DELETE( _collider );
    }

    void ParticleSystemSolver3::OnAdvanceTimeStep(double timeIntervalInSeconds)
    {
        LOG_INFO<<"ParticleSystemSolver3::OnAdvanceTimeStep";
    }


    void ParticleSystemSolver3::setEmitter(Emitter *pEmitter)
    {
        MY_ASSERT(pEmitter);
        SAFE_DELETE( _emitter );
        _emitter = pEmitter;
    }

    void ParticleSystemSolver3::setCollider(Collider *pCollider)
    {
        MY_ASSERT(pCollider);
        SAFE_DELETE( _collider );
        _collider = pCollider;
    }






    ParticleSystemSolver3::Builder ParticleSystemSolver3::GetBuilder()
    {
        // maybe Builder is just a meaningless shit?
        return {};
    }

    ParticleSystemSolver3 ParticleSystemSolver3::Builder::Build() const
    {
        return ParticleSystemSolver3(_radius, _mass);
    }

    ParticleSystemSolver3Ptr ParticleSystemSolver3::Builder::BuildMakeShared() const
    {
        return std::shared_ptr<ParticleSystemSolver3>(
                new ParticleSystemSolver3(_radius, _mass),
                [](ParticleSystemSolver3* obj) { delete obj; });
    }
}