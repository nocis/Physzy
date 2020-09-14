//
// Created by jared on 9/9/20.
//

#ifndef PHYSZY_EULERFLUID1_H
#define PHYSZY_EULERFLUID1_H

#include "PhyszyEngine.h"
using namespace PHYSZY;

class Eulerfluid1 : PhysicsAnimation
{
public:
    Eulerfluid1() {}

    void saveAsLiquidXml(/*const Engine::ScalarGrid3Ptr & sdf,*/ const std::string & rootDir, int frameCnt);
    float smoothStep(float edge0, float edge1, float x);

protected:

    /**
     * @see Game::initialize
     */
    void initialize() override{}

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


#endif //PHYSZY_EULERFLUID1_H
