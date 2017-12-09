//
// Created by Arnaud Pannatier on 30.11.17.
//
#include <cmath>
#include "Cholesky.h"

Matrix Cholesky::computeLTraditionnal (){
    A[0][0] = sqrt(A[0][0]);
    size_t N = A.size().lines;
    for(size_t i=0; i<N; i++){
        A[i][1] = A[i][1]/A[0][0];
    }
    for(size_t k = 1; k<N-1; k++){
        for(size_t j=0; j<k-1;j++){
            A[k][k] -= A[k][j]*A[k][j];
        }
        A[k][k] = sqrt(A[k][k]);
        for(size_t i = k+1; i < N; i++){
            for(size_t j=0; j<k-1;j++) {
                A[i][k] -=A[i][j]*A[k][j];
            }
            A[i][k]/=A[k][k];
        }
    }
    for(size_t j=0; j<N-1;j++) {
        A[N-1][N-1] -= A[N-1][j]*A[N-1][j];
    }
    A[N-1][N-1] = sqrt(A[N-1][N-1]);
    return A;
}

