//
// Created by Arnaud Pannatier on 04.12.17.
//

#ifndef PROJECT_JACOBI_H
#define PROJECT_JACOBI_H

#include "Matrix.h"
#include "Vector.h"
#include "IterativeSolvers.h"

class Jacobi : public IterativeSolvers {
public:

    using IterativeSolvers::IterativeSolvers;
    void step() final;


    //TODO : verify that A is a diagonally dominant matrix
};


#endif //PROJECT_JACOBI_H
