//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_GAUSSSEIDEL_H
#define PROJECT_GAUSSSEIDEL_H


#include "IterativeSolvers.h"

class GaussSeidel : public IterativeSolvers {
public:
    using IterativeSolvers::IterativeSolvers;
    void step() final;


};


#endif //PROJECT_GAUSSSEIDEL_H
