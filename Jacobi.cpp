//
// Created by Arnaud Pannatier on 04.12.17.
//

#include "Jacobi.h"

Jacobi::Jacobi (const Matrix &nA, const Vector&nB) {
    // TODO : inherit the constructor of solver;
    A = nA;
    B = nB;
    X = Vector(B.len());
}

Matrix Jacobi::solve () {
    // TODO : STOP AFTER max_iter ITERATION
    size_t i = 1;
    error = eps+1;
    while(error > eps && i < 100000){
        cout << "Iteration : " << i << " Error : " << error <<  "\r";

        cout.flush();
        try{
            step();
        }catch( char const* str){
            cout << str << endl;
        }
        i++;
    }
    return X;
}
void Jacobi::step () {
    double sigma;
    for(size_t i=0; i<X.size().lines; i++){
        sigma = 0.0;
        for(size_t j=0; j<X.size().lines; j++){
            if(j != i){
                // TODO : implement a vector notation
                sigma += A[i][j]*X[j][0];
            }
        }
        // TODO : implement Vector notation
        X[i][0] = 1/A[i][i]*(B[i][0]-sigma);
    }

    // TODO : simplify the notation
    error = Vector(A*X - B).norm();
}
