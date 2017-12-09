//
// Created by Haziq on 12/1/17.
//

#ifndef PROJECT_CG_H
#define PROJECT_CG_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

/** This class implements several iterative methods used to solve a linear system of equations.
  *
  */

class IterativeSolvers: public Solver  {
public:

    // Constructor
    IterativeSolvers(const Matrix& A_, const Vector& B_, const Vector& X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 10000): Solver(A_,B_, X_) {
        eps = eps_;
        error = 0.0;
        max_iter = max_iter_;
    };


    Vector solve() final;
    virtual void step() = 0;

protected:

    double eps;
    double error;
    size_t max_iter;
};

#endif //PROJECT_CG_H
