//
// Created by pcsc on 12/1/17.
//

#ifndef PROJECT_LU_H
#define PROJECT_LU_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

class LU : public Solver {
public:

    // Constructor
    using Solver::Solver;

    Vector solve() final;

    void computeLU();
    void computeX();

    Matrix getL();
    Matrix getU();

protected:

    Matrix L;
    Matrix U;
    size_t size;
};

#endif //PROJECT_LU_H
