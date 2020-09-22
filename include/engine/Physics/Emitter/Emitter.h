//
// Created by jared on 9/15/20.
//

#ifndef PHYSZY_EMITTER_H
#define PHYSZY_EMITTER_H

#include <memory>
#include <iostream>
namespace PHYSZY
{

    class Emitter
    {
    public:
        Emitter();

        virtual void test(){std::cout<<"Emitter"<<std::endl;}

    };

    using EmitterPtr = std::shared_ptr<Emitter>;
}
#endif //PHYSZY_EMITTER_H
