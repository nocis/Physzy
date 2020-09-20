//
// Created by jared on 9/15/20.
//

#ifndef PHYSZY_SPH1_H
#define PHYSZY_SPH1_H

#include "PhyszyEngine.h"
using namespace PHYSZY;

class SPH1 : public PhysicsAnimation
{
protected:

    /**
     * @see Game::initialize
     */
    void initialize() override;

    /**
     * @see Game::finalize
     */
    void finalize() override{}

    /**
     * @see Game::update
     */
    void update(float elapsedTime) override;

    /**
     * @see Game::render
     */
    void render(float elapsedTime) override{}
};


#endif //PHYSZY_SPH1_H
