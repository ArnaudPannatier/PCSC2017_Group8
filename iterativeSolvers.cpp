//
// Created by Haziq on 12/1/17.
//

#include "iterativeSolvers.h"

//=================================================================================================
iterativeSolvers::iterativeSolvers(const Matrix &A, const Matrix &B) : A(A), b(B)  {

    if(A.size().lines == A.size().cols) {
        size = A.size().cols;
    }
    else {
        throw "Matrix is not square";
    }


}

//=================================================================================================
Matrix iterativeSolvers::conjugateGradientDescent(Matrix& x, int max_iterations, double tolerance) {

    //todo: assert nan, use tolerance

    Matrix r_old, r_new, p;
    double alpha, beta;

    //initialize residual r and search direction p
    r_old = b - A*x;
    p = r_old;

    int k = 0;
    while ( k < max_iterations)
    {
        // Compute alpha
        alpha = (r_old.T()*r_old)[0][0] / max( (p.T()*A*p)[0][0] , 1.0e-10 );

        // Next estimate of solution
        x = x + p*alpha;

        // Compute new residual
        r_new = r_old - A * p * alpha;

        // Compute next search direction
        beta = (r_new.T()*r_new)[0][0] / (r_old.T()*r_old)[0][0];
        p = r_new + p * beta;

        // Update residual for next iteration
        r_old = r_new;

        k++;
    }

    return x;
}

//=================================================================================================
Matrix iterativeSolvers::gaussSeidel(Matrix& x, int max_iterations, double tolerance) {

    // check for zero elements on the diagonals
    for (int i = 0; i < size; i++)
    {
        if(A[i][i] != 0) {
            continue;
        }
        else {
            throw "Matrix has zero on diagonal";
        }
    }

    int k = 0;
    while (k < max_iterations)
    {
        for (int i = 0; i < size; i++)
        {
            double y = (b[i][0] / A[i][i]);
            for (int j = 0; j < size; j++)
            {
                if (j == i) continue;

                y = y - ((A[i][j] / A[i][i]) * x[j][0]);
                x[i][0] = y;
            }
        }

        k++;
    }

    return x;
}
