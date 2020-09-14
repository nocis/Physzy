//
// Created by jared on 9/14/20.
//


#include <thread>
#include <vector>
#include "PhyszyEngine.h"

using namespace std;
using namespace PHYSZY;

#define NUM_THREADS 5

int main(int argc, char** argv)
{
    PhysicsAnimation* game = PhysicsAnimation::getInstance();
    FluidEngine* fluidEngine = FluidEngine::create(game);
    MY_ASSERT(fluidEngine);
    int result = fluidEngine->enterMessagePump();
    delete fluidEngine;
    return result;
}

void say_hello(int i)
{
    LOG_DEBUG<<i<<i<<i<<i<<i<<i<<i;
    LOG_ERROR<<i<<i<<i<<i<<i<<i<<i;
    LOG_INFO<<i<<i<<i<<i<<i<<i<<i;

}

int test()
{
    std::vector<std::thread> pool;
    pool.reserve(NUM_THREADS);
    void (* hhh)(int i) = say_hello;
    auto func = [&hhh](int i) {
        hhh(i);
    };
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        pool.emplace_back(func, i);
    }

    for (std::thread &t : pool)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}