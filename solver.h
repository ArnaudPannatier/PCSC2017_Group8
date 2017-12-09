//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_SOLVER_H
#define PROJECT_SOLVER_H

#include "Matrix.h"
#include "Vector.h"

class Solver {
public :
    Solver(const Matrix &A_, const Vector &B_, const Vector &X_ = Vector());

    virtual Vector solve() = 0;
protected:
    Matrix A;
    Vector B;
    Vector X;
};


#endif //PROJECT_SOLVER_H
