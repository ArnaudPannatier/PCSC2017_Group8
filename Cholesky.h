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
    Cholesky(const Matrix& nA, const Vector& nB);

    Matrix getL();


protected:
    Matrix A;
    Vector B;
    Vector X;
};


#endif //PROJECT_CHOLESKY_H
