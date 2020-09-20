//
// Created by jared on 9/13/20.
//

#include "engine/FluidEngine/PhysicsAnimation.h"
#include "FluidEngine/FluidEngine.h"
namespace PHYSZY
{
    static PhysicsAnimation* __animationInstance = nullptr;
    double PhysicsAnimation::_pausedTimeLast = 0.0;
    double PhysicsAnimation::_pausedTimeTotal = 0.0;

    double PhysicsAnimation::getGameTime()
    {
        return FluidEngine::getAbsoluteTime() - _pausedTimeTotal;
    }

    PhysicsAnimation::PhysicsAnimation()
    {
        MY_ASSERT(__animationInstance == nullptr);
        __animationInstance = this;
    }

    PhysicsAnimation::~PhysicsAnimation()
    {

        __animationInstance = nullptr;
    }

    PhysicsAnimation* PhysicsAnimation::getInstance()
    {
        MY_ASSERT(__animationInstance);
        return __animationInstance;
    }

    bool PhysicsAnimation::startup()
    {
        if (_state != Animation::state::UNINITIALIZED)
            return false;

        _physicsController = new PhysicsController();
        _state = Animation::state::RUNNING;

        return true;
    }


    void PhysicsAnimation::initialize()
    {

    }

    void PhysicsAnimation::finalize()
    {

    }

    void PhysicsAnimation::update(float elapsedTime)
    {

    }

    void PhysicsAnimation::render(float elapsedTime)
    {

    }

    int PhysicsAnimation::run()
    {
        if (_state != Animation::state::UNINITIALIZED)
            return -1;

        //loadConfig();

        // Start up game systems.
        if (!startup())
        {
            //shutdown();
            return -2;
        }

        return 0;
    }

    void PhysicsAnimation::pause()
    {

    }

    void PhysicsAnimation::resume()
    {

    }

    void PhysicsAnimation::exit()
    {

    }

    void PhysicsAnimation::frame()
    {
        /*if (!_initialized)
        {
            // Perform lazy first time initialization
            initialize();
            if (_scriptTarget)
                _scriptTarget->fireScriptEvent<void>(GP_GET_SCRIPT_EVENT(GameScriptTarget, initialize));
            _initialized = true;

            // Fire first game resize event(fullscreen etc.)
            Platform::resizeEventInternal(_width, _height);
        }

        static double lastFrameTime = Game::getGameTime();
        double frameTime = getGameTime();

        // Fire time events to scheduled TimeListeners
        fireTimeEvents(frameTime);

        if (_state == Game::RUNNING)
        {
            GP_ASSERT(_animationController);
            GP_ASSERT(_audioController);
            GP_ASSERT(_physicsController);
            GP_ASSERT(_aiController);

            // Update Time.
            float elapsedTime = (frameTime - lastFrameTime);
            lastFrameTime = frameTime;

            // Update the scheduled and running animations.
            _animationController->update(elapsedTime);

            // Update the physics.
            _physicsController->update(elapsedTime);

            // Update AI.
            _aiController->update(elapsedTime);

            // Update gamepads.
            Gamepad::updateInternal(elapsedTime);

            // Application Update.
            update(elapsedTime);

            // Update forms.
            Form::updateInternal(elapsedTime);

            // Run script update.
            if (_scriptTarget)
                _scriptTarget->fireScriptEvent<void>(GP_GET_SCRIPT_EVENT(GameScriptTarget, update), elapsedTime);

            // Audio Rendering.
            _audioController->update(elapsedTime);

            // Graphics Rendering.
            render(elapsedTime);

            // Run script render.
            if (_scriptTarget)
                _scriptTarget->fireScriptEvent<void>(GP_GET_SCRIPT_EVENT(GameScriptTarget, render), elapsedTime);

            // Update FPS.
            ++_frameCount;
            if ((Game::getGameTime() - _frameLastFPS) >= 1000)
            {
                _frameRate = _frameCount;
                _frameCount = 0;
                _frameLastFPS = getGameTime();
            }
        }
        else if (_state == Game::PAUSED)
        {
            // Update gamepads.
            Gamepad::updateInternal(0);

            // Application Update.
            update(0);

            // Update forms.
            Form::updateInternal(0);

            // Script update.
            if (_scriptTarget)
                _scriptTarget->fireScriptEvent<void>(GP_GET_SCRIPT_EVENT(GameScriptTarget, update), 0);

            // Graphics Rendering.
            render(0);

            // Script render.
            if (_scriptTarget)
                _scriptTarget->fireScriptEvent<void>(GP_GET_SCRIPT_EVENT(GameScriptTarget, render), 0);
        }
         */
        if (!_initialized)
        {
            initialize();
            _initialized = true;
        }

        // static var only be initialized once at first time
        static double lastFrameTime = getGameTime();
        double frameTime = getGameTime();

        if (_state == Animation::state::RUNNING)
        {
            MY_ASSERT(_physicsController);

            // Update Time.
            float elapsedTime = (frameTime - lastFrameTime);
            lastFrameTime = frameTime;

            LOG_INFO << " Begin updating frame: " << _frame._idx
                     << " timeIntervalInSeconds: " << _frame._itv
                     << " (1/" << 1.0 / _frame._itv
                     << ") seconds";

            // Update the physics.
            _physicsController->update(_frame._itv);

            // Application Update.
            update(_frame._itv);

            // Graphics Rendering.
            render(_frame._itv);

            LOG_INFO << " End updating frame (took " << elapsedTime
                     << " seconds)";

            // Update FPS.
            //++_frameCount;
            //if ((Game::getGameTime() - _frameLastFPS) >= 1000)
            //{
            //    _frameRate = _frameCount;
            //    _frameCount = 0;
            //    _frameLastFPS = getGameTime();
            //}
        }
        else if (_state == Animation::state::PAUSED)
        {
            // Application Update.
            //update(0);

            // Graphics Rendering.
            //render(0);
        }
    }

    void PhysicsAnimation::setSolver( SolverPtr&& pSolver )
    {
        // 1: sph1.cpp--sphsolver3ptr
        // 2: shared_from_this--solverptr
        _physicsController->setSolver(pSolver);
        // 3: controller--_solver
    }


    /*void PhysicsAnimation::runSolver()
    {
        auto particles = _solver->particleSystemData();

        for (Frame frame(0, 1.0 / _fps); frame.index < _numberOfFrames; ++frame)
        {
            _solver->update(frame);
            if (_Dataformat == "xyz") {
                saveParticleAsXyz(particles, _rootDir, frame.index);
            } else if (_Dataformat == "pos") {
                saveParticleAsPos(particles, _rootDir, frame.index);
            }
        }
    }*/
}