//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_GAUSSSEIDEL_H
#define PROJECT_GAUSSSEIDEL_H


#include "IterativeSolvers.h"

/**
 * @brief Gauss-Seidel Method
 *
 * This class implements the Gauss-Seidel method for solving a system of linear equations
 * https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method
 *
 * @code *
 * GaussSeidel gaussSolver(A, B, x_0);
 * Vector X = gaussSolver.solve(); *
 * @endcode
 *
 */

class GaussSeidel : public IterativeSolvers {
public:

    using IterativeSolvers::IterativeSolvers;

    /// @brief Computes X for a single iteration
    void step() final;
};


#endif //PROJECT_GAUSSSEIDEL_H
