//
// Created by jared on 9/10/20.
//

#include "FluidEngine/FluidEngine.h"
#include "FluidEngine/PhysicsAnimation.h"
namespace PHYSZY
{
    static double __timeStart;
    static double __timeAbsolute;
    Timer* FluidEngine::_timer = nullptr;

    FluidEngine::FluidEngine()
    {

    }

    FluidEngine::FluidEngine(PhysicsAnimation *pAnimation)
        : _physicsAnimation(pAnimation)
    {
        _timer = new Timer();
    }

    FluidEngine::~FluidEngine()
    {
        delete _timer;
    }

    FluidEngine *FluidEngine::create(PhysicsAnimation *physicsAnimation)
    {
        MY_ASSERT(physicsAnimation);
        FluidEngine* fluidEngine = new FluidEngine(physicsAnimation);
        return fluidEngine;
    }

    double FluidEngine::getAbsoluteTime()
    {
        __timeAbsolute = _timer->getDuration();
        return __timeAbsolute - __timeStart;
    }

    int FluidEngine::enterMessagePump()
    {
        /*// Get the initial time.
        LARGE_INTEGER tps;
        QueryPerformanceFrequency(&tps);
        __timeTicksPerMillis = (double)(tps.QuadPart / 1000L);
        LARGE_INTEGER queryTime;
        QueryPerformanceCounter(&queryTime);
        GP_ASSERT(__timeTicksPerMillis);
        __timeStart = queryTime.QuadPart / __timeTicksPerMillis;

        SwapBuffers(__hdc);

        if (_game->getState() != Game::RUNNING)
            _game->run();

        // Enter event dispatch loop.
        MSG msg;
        while (true)
        {
            if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);

                if (msg.message == WM_QUIT)
                {
                    gameplay::Platform::shutdownInternal();
                    return msg.wParam;
                }
            }
            else
            {
#ifdef GP_USE_GAMEPAD
                // Check for connected XInput gamepads.
            for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
            {
                if (XInputGetState(i, &__xInputState) == NO_ERROR && !__connectedXInput[i])
                {
                    // Gamepad was just connected.
                    Platform::gamepadEventConnectedInternal(i, XINPUT_BUTTON_COUNT, XINPUT_JOYSTICK_COUNT, XINPUT_TRIGGER_COUNT, "Microsoft XBox360 Controller");
                    __connectedXInput[i] = true;
                }
                else if (XInputGetState(i, &__xInputState) != NO_ERROR && __connectedXInput[i])
                {
                    // Gamepad was just disconnected.
                    __connectedXInput[i] = false;
                    Platform::gamepadEventDisconnectedInternal(i);
                }
            }
#endif
                _game->frame();
                SwapBuffers(__hdc);
            }

            // If we are done, then exit.
            if (_game->getState() == Game::UNINITIALIZED)
                break;
        }
        return 0;*/



        MY_ASSERT(_physicsAnimation);
        __timeStart = _timer->reset();

        if (_physicsAnimation->getState() != PhysicsAnimation::Animation::state::RUNNING)
            _physicsAnimation->run();

        while (true)
        {
            _physicsAnimation->frame();
        }

        return 0;
    }



}
