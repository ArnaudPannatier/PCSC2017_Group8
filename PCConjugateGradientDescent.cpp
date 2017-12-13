//
// Created by Arnaud Pannatier on 08.12.17.
//

#include "PCConjugateGradientDescent.h"
#include "Cholesky.h"

void PCConjugateGradientDescent::step () {

    double alpha = (residual.dot(z)) / max( (searchDirection.dot(Vector(A*searchDirection))) , 1.0e-10 );

    // Next estimate of solution
    X = Vector(X + searchDirection*alpha);

    // Compute new residual
    Vector new_residual = Vector(residual - A * searchDirection * alpha);

    Vector z_new = Vector(Preconditioner*new_residual);

    // Compute next search direction
    double beta = z_new.dot(new_residual) / (z.dot(residual));
    searchDirection = Vector(z_new + searchDirection * beta); // z not beta

    // Update residual for next iteration
    residual = new_residual;
    z = z_new;
}

