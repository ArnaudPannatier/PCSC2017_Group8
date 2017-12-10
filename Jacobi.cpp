//
// Created by Arnaud Pannatier on 04.12.17.
//

#include "Jacobi.h"


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


}

