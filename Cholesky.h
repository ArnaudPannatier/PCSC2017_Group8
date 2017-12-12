//
// Created by Arnaud Pannatier on 30.11.17.
//

#ifndef PROJECT_CHOLESKY_H
#define PROJECT_CHOLESKY_H

#include<iostream>
#include "Matrix.h"
#include "Vector.h"
#include "LU.h"

using namespace std;

/**
 * @brief Cholesky decomposition
 *
 * This class implements the cholesky decomposition of a matrix that returns a lower triangular
 * matrix and its conjugate transpose https://en.wikipedia.org/wiki/Cholesky_decomposition
 *
 */

class Cholesky : public LU {
public:

    /**
     * @param A_ Positive symmetric definite matrix where each row represents a single observation. An exception will be
     * thrown if A_ is not p.s.d.
     * @param B_ Column vector
     *
     */

    Cholesky(const Matrix &A_, const Vector &B_, const Vector &X_ = Vector()) :LU(A_, B_, X_) {
        if(!A_.isSymmetric()){
            throw "A is not symmetric it can't therefore be symmetric definite positive";
        }
    };

    Matrix computeLTraditionnal();


};


#endif //PROJECT_CHOLESKY_H
