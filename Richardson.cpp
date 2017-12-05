//
// Created by Arnaud Pannatier on 05.12.17.
//

#include "Richardson.h"
#include "Vector.h"

Richardson::Richardson (const Matrix &nA, const Matrix &nB, double omega_) {
    // TODO : inherit the constructor of solver;
    A = nA;
    B = nB;
    X = Matrix(B.size().lines, 1);
    omega = omega_;
}

Matrix Richardson::solve () {
    size_t i = 1;
    error = eps+1;
    cout << endl;
    while(error > eps && i < max_iter){
        cout << "\r" << "Iteration : " << i << " Error : " << error;

        cout.flush();
        step();
        i++;
    }
    cout << endl;
    return X;
}

void Richardson::step () {
    Vector errVec =  Vector(A*X - B);
    error = errVec.norm();
    X = X - errVec*omega;
}
