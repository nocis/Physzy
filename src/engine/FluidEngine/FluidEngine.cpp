//
// Created by jared on 9/10/20.
//

#include "FluidEngine/FluidEngine.h"
namespace PHYSZY
{
    static FluidEngine* __engineInstance = nullptr;
    double FluidEngine::_pausedTimeLast = 0.0;
    double FluidEngine::_pausedTimeTotal = 0.0;

    FluidEngine::FluidEngine()
    {
        MY_ASSERT(__engineInstance == nullptr);
        __engineInstance = this;
    }

    FluidEngine::~FluidEngine()
    {

        __engineInstance = nullptr;
    }

    FluidEngine* FluidEngine::getInstance()
    {
        MY_ASSERT(__engineInstance);
        return __engineInstance;
    }

    void FluidEngine::initialize()
    {

    }

    void FluidEngine::finalize()
    {

    }

    void FluidEngine::update(float elapsedTime)
    {

    }

    void FluidEngine::render(float elapsedTime)
    {

    }


}
