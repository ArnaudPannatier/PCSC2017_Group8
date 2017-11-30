//
// Created by Arnaud Pannatier on 30.11.17.
//

#ifndef PROJECT_CHOLESKY_H
#define PROJECT_CHOLESKY_H

#include<iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

class Cholesky {
public:
    // Constructor
    Cholesky(const Matrix& nA, const Matrix& nB);

    Matrix getL();

protected:
    Matrix A;
    Matrix B;
    Matrix X;
};


#endif //PROJECT_CHOLESKY_H
