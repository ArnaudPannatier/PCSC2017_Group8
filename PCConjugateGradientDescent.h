//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_PCCONJUGATEGRADIENTDESCENT_H
#define PROJECT_PCCONJUGATEGRADIENTDESCENT_H

#include "IterativeSolvers.h"

/**
 * @brief Preconditioned Conjugate Gradient Method
 *
 * This class implements the Preconditioned Conjugate Gradient Method for solving a system of linear equations,
 * namely those whose matrix is symmetric and positive-definite.
 * https://en.wikipedia.org/wiki/Conjugate_gradient_method#The_preconditioned_conjugate_gradient_method
 *
 *
 *
 * @code
 * #include "PCConjugateGradientDescent.h"
 *
 * PCConjugateGradientDescent PCconjSolver(A, B, x_0, M);
 * Vector X = PCconjSolver.solve();
 * @endcode
 *
 */

class PCConjugateGradientDescent : public IterativeSolvers {
public:

    /**
     * @param A_ Positive symmetric definite matrix where each row represents a single observation. An exception will be
     * raised if A_ is not p.s.d.
     * @param B_ Column vector
     * @param X_ Initial guess to the solution
     * @param Preconditioner_ Preconditioning matrix
     * @param eps_ Stopping criteria i.e. the algorithm terminates if the norm of the error is below eps_
     * @param max_iter_ Maximum number of iterations
     *
     */

    PCConjugateGradientDescent(const Matrix& A_, const Vector& B_, const Vector& X_ = Vector(), const Matrix& Preconditioner_ = Matrix(), double eps_ = 1e-6, size_t max_iter_ = 100000)
            :IterativeSolvers(A_,B_, X_, eps_,max_iter_)
    {
        Preconditioner = Preconditioner_.Inverse();

        residual = Vector(B - A*X);
        z = Vector(Preconditioner*residual);
        searchDirection = z;
    };

    /// @brief Computes X for a single iteration
    void step() final;

private:

    /// @brief residual vector given current solution: B - AX
    Vector residual;
    Vector searchDirection;
    Vector z;
    Matrix Preconditioner;

};

#endif //PROJECT_PCCONJUGATEGRADIENTDESCENT_H
