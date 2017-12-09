//
// Created by Haziq on 12/1/17.
//

#include <cmath>
#include "LU.h"


Vector LU::solve(){

  //cout << "Start Solving with LU " << endl;
  size = B.len();
  computeLU();
  computeX ();
  return X;
}

//=================================================================================================
void LU::computeLU(){
    //cout << "Start Computing LU" << endl;
    // Initialize size of LU matrices
    L = Matrix(size,size);
    U = Matrix(size,size);

    // Set the diagonal elements of U to 1
    for (size_t i = 0; i < size; i++) {
        U[i][i] = 1;
    }

    // j moves along the diagonal of the square matrix
    for (size_t j = 0; j < size; j++) {

        // move along the column to compute L
        // L[0][j], L[1][j], ..., L[i][j]
        for (size_t i = j; i < size; i++) {

            double sum = 0;
            for (size_t k = 0; k < j; k++) {
                sum += L[i][k] * U[k][j];
            }
            L[i][j] = A[i][j] - sum;
            //cout << "L[" << i << "][" << j << "] = " << L[i][j] << endl;
        }

        // move along the row to compute U
        // U[j][0], U[j][1], ..., L[j][i]
        for (size_t i = j; i < size; i++) {

            double sum = 0;
            for(size_t k = 0; k < j; k++) {
                sum += L[j][k] * U[k][i];
            }

            // assert
            if (L[j][j] == 0) {
                printf("det(L) close to 0!\n Can't divide by 0...\n");
            }

            U[j][i] = (A[j][i] - sum) / L[j][j];
            //cout << "U[" << j << "][" << i << "] = " << U[j][i] << endl;
        }
    }
    //cout << "L : " << L << endl;
    //cout << "U : " << U << endl;

}

Matrix LU::getL() { return L; }
Matrix LU::getU() { return U; }

void LU::computeX() {
    //cout << "Computing X " << endl;
    Vector Y(size);

    // solve LY = b for Y
    for(size_t i = 0; i < size; i++)
    {
        double sum = 0;
        for(size_t p = 0; p <= i; p++) {
            sum += L[i][p] * Y[p][0];
        }
        Y[i][0]=(B[i][0] - sum) / L[i][i];
    }

    // solve UX = Z for X
    for(int i = size - 1; i >= 0; i--)
    {
        double sum=0;
        for(int p = size - 1; p >= i; p--) {
            sum += U[i][p] * X[p][0];
        }
        X[i][0]=(Y[i][0]-sum) / U[i][i];
    }

    //cout << "X : " << X  << endl;
}