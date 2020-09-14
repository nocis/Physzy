//
// Created by jared on 9/10/20.
//

#ifndef PHYSZY_FLUIDENGINE_H
#define PHYSZY_FLUIDENGINE_H
#include "Core/Timer.h"
#include "Core/mylogger.h"
#include "UsefulMacro.h"

// shuould like a runing framework instead of on listening interfaces(game class)
namespace PHYSZY
{
    // forward declaration only can be used for pointer and reference
    // forward declaration does not have definition
    // forward declaration + friend can be useful when header files are circle referenced.
    // included friended circle referenced class in cpp files for definition of functions!!!.
    class PhysicsAnimation;

    class FluidEngine
    {
        friend class PhysicsAnimation;

    public:
        FluidEngine();

        virtual ~FluidEngine();
        // virtual destructor for base class makes sure polymorphism calling by base's pointer can invoke
        // derived's destructor correctly before calling the base's destructor !!!!!

        static double getAbsoluteTime();
        static FluidEngine* create(PhysicsAnimation* physicsAnimation);


        int enterMessagePump();

    protected:
        static Timer* _timer;
        PhysicsAnimation* _physicsAnimation;



    private:
        explicit FluidEngine(PhysicsAnimation *pAnimation);

    };
}
#endif //PHYSZY_FLUIDENGINE_H
