//
// Created by pcsc on 12/1/17.
//

#include <cmath>
#include "directSolvers.h"

//=================================================================================================
directSolvers::directSolvers(const Matrix &A, const Matrix &b) : A(A), b(b) {}

//=================================================================================================
void directSolvers::LU() {

    // todo: assert if not square
    int size = A.size().cols;

    // Initialize size of LU matrices
    L = Matrix(size,size);
    U = Matrix(size,size);

    // Set the diagonal elements of U to 1
    for (int i = 0; i < size; i++) {
        U[i][i] = 1;
    }

    // j moves along the diagonal of the square matrix
    for (int j = 0; j < size; j++) {

        // move along the column to compute L
        // L[0][j], L[1][j], ..., L[i][j]
        for (int i = j; i < size; i++) {

            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * U[k][j];
            }
            L[i][j] = A[i][j] - sum;
            //cout << "L[" << i << "][" << j << "] = " << L[i][j] << endl;
        }

        // move along the row to compute U
        // U[j][0], U[j][1], ..., L[j][i]
        for (int i = j; i < size; i++) {

            double sum = 0;
            for(int k = 0; k < j; k++) {
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

    int size = b.size().lines;

    // Initialize x matrix
    Matrix x = Matrix(size, 1);

    // Compute z for Lz = b
    Matrix z = Matrix(size,1);
    for(int i=1;i<=size;i++)
    {
        double sum=0;
        for(int p=1;p<i;p++)
            sum+=L[i][p]*z[p][0];
        z[i][0]=(b[i][0]-sum)/L[i][i];
    }

    for(int i=size;i>0;i--)
    {
        double sum=0;
        for(int p= size;p>i;p--)
            sum+=U[i][p]*x[p][0];
        x[i][0]=(z[i][0]-sum)/U[i][i];
    }

    cout << x << endl;
    return x;

}