//
// Created by Arnaud Pannatier on 30.11.17.
//
#include <cmath>
#include "Cholesky.h"


Cholesky::Cholesky (const Matrix &A_, const Vector &B_, const Vector &X_) :LU(A_, B_, X_) {
    if(!A_.isSymmetric()){
        throw "A is not symmetric it can't therefore be symmetric definite positive";
    }
}
