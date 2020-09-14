//
// Created by jared on 9/13/20.
//

#ifndef PHYSZY_PHYSICSANIMATION_H
#define PHYSZY_PHYSICSANIMATION_H

#include "engine/Core/Animation.h"
#include "PhysicsController.h"

// on listening interface(game)
namespace PHYSZY
{
    class PhysicsAnimation : public Animation
    {
    public:

        PhysicsAnimation();
        virtual ~PhysicsAnimation();
        static PhysicsAnimation* getInstance();
        static double getGameTime();
        bool startup();

        int run();
        void pause();
        void resume();
        void exit();
        void frame() override;

    private:
        Frame _currentFrame;
        //bool _isUsingFixedSubTimeSteps = true;
        //unsigned int _numberOfFixedSubTimeSteps = 1;
        double _currentTime = 0.0;
        static double _pausedTimeLast;
        static double _pausedTimeTotal;

        virtual void initialize();
        virtual void finalize();
        virtual void update(float elapsedTime);
        virtual void render(float elapsedTime);



        //void onUpdate(const Frame& frame) final;
        //void advanceTimeStep(double timeIntervalInSeconds);

        bool _initialized;                          // If Animation has initialized yet.
        PhysicsController* _physicsController;      // Controls the simulation of a physics scene and entities.


    };
    typedef std::shared_ptr<PhysicsAnimation> PhysicsAnimationPtr;
}

#endif //PHYSZY_PHYSICSANIMATION_H
