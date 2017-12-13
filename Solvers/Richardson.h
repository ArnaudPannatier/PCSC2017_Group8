//
// Created by Arnaud Pannatier on 05.12.17.
//

#ifndef PROJECT_RICHARDSON_H
#define PROJECT_RICHARDSON_H

#include "IterativeSolvers.h"

/**
 * @brief Richardson method
 *
 * This class implements the Richardson Method for solving a system of linear equations
 * https://en.wikipedia.org/wiki/Modified_Richardson_iteration
 *
 * @code
 * #include "Richardson.h"
 *
 * Richardson richardson(A,B, 0.1);
 * Vector X = richardson.solve();
 * @endcode
 *
 */

class Richardson : public IterativeSolvers {
public:

    /**
     * @param A_ Square matrix where each row represents a single observation
     * @param B_ Column vector
     * @param X_ Initial guess to the solution
     * @param eps_ Stopping criteria i.e. the algorithm terminates if the norm of the error is below eps_
     * @param max_iter_ Maximum number of iterations
     *
     */

    Richardson (const Matrix &A_, const Vector &B_, double omega_, const Vector &X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 100000);

    /// @brief computes X for a single iteration
    void step() final;

    //TODO : compute omega with the condition number \omega_opt = 2/(\lambda_min(A) +\lambda_max(A))


protected:
    double omega;
};


#endif //PROJECT_RICHARDSON_H
