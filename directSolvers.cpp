//
// Created by Haziq on 12/1/17.
//

#include <cmath>
#include "directSolvers.h"

//=================================================================================================
directSolvers::directSolvers(const Matrix &A, const Matrix &b) : A(A), b(b) {

    if(A.size().lines == A.size().cols) {
        size = A.size().cols;
    }
    else {
        throw "Matrix is not square";
    }

}

//=================================================================================================
void directSolvers::LU() {

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
}

Matrix directSolvers::getL() { return L; }
Matrix directSolvers::getU() { return U; }

Matrix directSolvers::getX() {

    Matrix Y(size,1);
    Matrix X(size,1);

    // solve LY = b for Y
    for(size_t i = 0; i < size; i++)
    {
        double sum = 0;
        for(size_t p = 0; p <= i; p++)
            sum += L[i][p]*Y[p][0];
        Y[i][0]=(b[i][0] - sum) / L[i][i];
    }

    // solve UX = Z for X
    for(int i = size - 1; i >= 0; i--)
    {
        double sum=0;
        for(int p = size - 1; p >= i; p--)
            sum+=U[i][p]*X[p][0];
        X[i][0]=(Y[i][0]-sum) / U[i][i];
    }

    return X;

}