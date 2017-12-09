//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_CONJUGATEGRADIENTDESCENT_H
#define PROJECT_CONJUGATEGRADIENTDESCENT_H

#include "IterativeSolvers.h"

class ConjugateGradientDescent : public IterativeSolvers {
public:

    ConjugateGradientDescent(const Matrix& A_, const Vector& B_, const Vector& X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 10000)
            :IterativeSolvers(A_,B_, X_, eps_,max_iter_)
    {
        residual = Vector(B - A*X);
        searchDirection = residual;
    };

    void step() final;

private:
    Vector residual;
    Vector searchDirection;

};


#endif //PROJECT_CONJUGATEGRADIENTDESCENT_H
