//
// Created by Arnaud Pannatier on 08.12.17.
//

#include "ConjugateGradientDescent.h"


void ConjugateGradientDescent::step () {
    
    double alpha = (residual.dot(residual)) / max( (searchDirection.dot(Vector(A*searchDirection))) , 1.0e-10 );

    // Next estimate of solution
    X = Vector(X + searchDirection*alpha);

    // Compute new residual
    Vector new_residual = Vector(residual - A * searchDirection * alpha);

    // Compute next search direction
    double beta = new_residual.dot(new_residual) / (residual.dot(residual));
    searchDirection = Vector(new_residual + searchDirection * beta);

    // Update residual for next iteration
    residual = new_residual;

}

ConjugateGradientDescent::ConjugateGradientDescent (const Matrix &A_, const Vector &B_, const Vector &X_, double eps_, size_t max_iter_)
        :IterativeSolvers(A_,B_, X_, eps_,max_iter_)
{
    residual = Vector(B - A*X);
    searchDirection = residual;
}




