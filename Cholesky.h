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

class Cholesky : public LU {
public:
    // Constructor
    Cholesky(const Matrix &A_, const Vector &B_, const Vector &X_ = Vector()) :LU(A_, B_, X_) {
        if(!A_.isSymmetric()){
            throw "A is not symmetric it can't therefore be symmetric definite positive";
        }
    };

    Matrix computeLTraditionnal();


};


#endif //PROJECT_CHOLESKY_H
