//
// Created by Haziq on 12/8/17.
//

#ifndef PROJECT_SOLVERS_H
#define PROJECT_SOLVERS_H

#include "Matrix.h"
#include "Vector.h"

//=================================================================================================
class solvers {

public:
    // constructor
    solvers();
    solvers(Matrix A, Matrix B);

    virtual Matrix solve() = 0;

protected:

    Matrix A, B, X;
    int size = 0;

};

//=================================================================================================
class iterativeSolvers : public solvers {

public:

    Matrix solve();
    virtual void step() = 0;

protected:

    double eps = 1e-12;
    double error = 0.0;

};

//=================================================================================================
class gaussSeidel : public iterativeSolvers {

public:

    gaussSeidel(Matrix A, Matrix B, double eps = 1e-12, double error = 0.0);
    void step();

private:

    double eps = 1e-12;
    double error = 0.0;

};

#endif //PROJECT_SOLVERS_H
