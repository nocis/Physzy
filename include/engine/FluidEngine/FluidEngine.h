//
// Created by jared on 9/10/20.
//

#ifndef PHYSZY_FLUIDENGINE_H
#define PHYSZY_FLUIDENGINE_H

#include "UsefulMacro.h"

namespace PHYSZY
{
    class FluidEngine
    {
    public:
        FluidEngine();

        virtual ~FluidEngine();
        static FluidEngine* getInstance();
        // virtual destructor for base class makes sure polymorphism calling by base's pointer can invoke
        // derived's destructor correctly before the base's destructor !!!!!
    protected:
        virtual void initialize();
        virtual void finalize();
        virtual void update(float elapsedTime);
        virtual void render(float elapsedTime);

        static double _pausedTimeLast;
        static double _pausedTimeTotal;
    };
}
#endif //PHYSZY_FLUIDENGINE_H
