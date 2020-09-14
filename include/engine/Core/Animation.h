//
// Created by jared on 9/10/20.
//

#ifndef PHYSZY_ANIMATION_H
#define PHYSZY_ANIMATION_H
#include <memory>
#include "UsefulMacro.h"
namespace PHYSZY
{
    class Frame final
    {
    public:
        Frame() {}
        Frame(int idx, double itv) :_idx(idx), _itv(itv){ }
        double ToSeconds() const { return _idx * _itv;}
        void advance() {_idx++;}
        void advance(int fn) {_idx += fn;}
        int _idx = 0;
        double _itv = 1.0 / 60.0;
    };

    class Animation
    {
    public:

        enum class state
        {
            UNINITIALIZED,
            RUNNING,
            PAUSED
        };

        Animation() {}
        virtual ~Animation() {}
        state getState() { return _state; }

    protected:
        Frame _frame;
        virtual void frame() = 0;
        state _state;                    // The game state.

    private:

    };
    typedef std::shared_ptr<Animation> AnimationPtr;
}
#endif //PHYSZY_ANIMATION_H
