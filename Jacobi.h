//
// Created by Arnaud Pannatier on 04.12.17.
//

#ifndef PROJECT_JACOBI_H
#define PROJECT_JACOBI_H

#include "Matrix.h"
#include "Vector.h"
#include "IterativeSolvers.h"

/**
 * @brief Jacobi method
 *
 * This class implements the Jacobi method for solving a system of linear equations
 * https://en.wikipedia.org/wiki/Jacobi_method
 *
 * @code
 * #include "Jacobi.h"
 *
 * Jacobi jacobi(A,B);
 * Vector X =jacobi.solve();
 * @endcode
 *
 */

class Jacobi : public IterativeSolvers {
public:

    using IterativeSolvers::IterativeSolvers;

    /// @brief computes X for a single iteration
    void step() final;

    //TODO : verify that A is a diagonally dominant matrix
};

#endif //PROJECT_JACOBI_H
