//
// Created by Haziq on 12/1/17.
//

#ifndef PROJECT_CG_H
#define PROJECT_CG_H

#include <iostream>
#include <assert.h>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

/** This class implements several iterative methods used to solve a linear system of equations.
  *
  */

class iterativeSolvers {
public:

    // Constructor
    iterativeSolvers(const Matrix& A, const Matrix& B);

    /** \brief Conjugate Gradient Descent
      * \param x_0 initial guess for the solution
      * \param iterations maximum number of iterations
      * \param tolerance convergence test
      * \return solution to the problem Ax = b
      *
      * This method implements the conjugate gradient descent for solving Ax = b, where A is a real, symmetric, and
      * positive-definite matrix https://en.wikipedia.org/wiki/Conjugate_gradient_method
      */

    Matrix conjugateGradientDescent(Matrix& x_0, int iterations = 20, double tolerance = 1e-10);

    /** \brief Gauss Seidel Method
      * \param x_0 initial guess for the solution
      * \param iterations maximum number of iterations
      * \param tolerance convergence test
      * \return solution to the problem Ax = b
      *
      * This method implements the equation version of the Gauss-Seidel method for solving Ax = b, where A is a square
      * matrix with non-zero entries on the diagonal https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method#An_example_for_the_equation_version
      */

    Matrix gaussSeidel(Matrix& x_0, int iterations = 20, double tolerance = 1e-10);

protected:

    Matrix A;
    Matrix b;

    int size = 0;
};

#endif //PROJECT_CG_H
