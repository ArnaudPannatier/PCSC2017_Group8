//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_CONJUGATEGRADIENTDESCENT_H
#define PROJECT_CONJUGATEGRADIENTDESCENT_H

#include "IterativeSolvers.h"
#include "Cholesky.h"

/**
 * @brief Conjugate Gradient Method
 *
 * This class implements the Conjugate Gradient Method for solving a system of linear equations, namely those whose
 * matrix is symmetric and positive-definite. https://en.wikipedia.org/wiki/Conjugate_gradient_method
 *
 * @code
 * #include "ConjugateGradientDescent.h"
 *
 * ConjugateGradientDescent conjSolver(A, B, x_0);
 * Vector X = conjSolver.solve();
 * @endcode
 *
 */

class ConjugateGradientDescent : public IterativeSolvers {
public:

    /**
     * @param A_ Positive symmetric definite matrix where each row represents a single observation. An exception will be
     * raised if A_ is not p.s.d.
     * @param B_ Column vector
     * @param X_ Initial guess to the solution
     * @param eps_ Stopping criteria i.e. the algorithm terminates if the norm of the error is below eps_
     * @param max_iter_ Maximum number of iterations
     *
     */

    ConjugateGradientDescent(const Matrix& A_, const Vector& B_, const Vector& X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 100000);

    /// @brief Computes X for a single iteration
    void step() final;


private:

    /// @brief residual vector given current solution: B - AX
    Vector residual;
    Vector searchDirection;

};

#endif //PROJECT_CONJUGATEGRADIENTDESCENT_H
