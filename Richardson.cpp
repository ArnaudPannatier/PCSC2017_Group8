//
// Created by Arnaud Pannatier on 05.12.17.
//

#include "Richardson.h"
#include "Vector.h"


//=================================================================================================
void Richardson::step () {
    Vector errVec =  Vector(A*X - B);
    X = Vector(X - errVec*omega);
}

//=================================================================================================
Richardson::Richardson (const Matrix &A_, const Vector &B_, double omega_, const Vector &X_, double eps_, size_t max_iter_)
        : IterativeSolvers (A_, B_, X_, eps_, max_iter_)
{
    omega = omega_;
}
