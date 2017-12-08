//
// Created by pcsc on 12/8/17.
//

#include "solvers.h"

//=================================================================================================
solvers::solvers(Matrix A, Matrix B) : A(A), B(B) {

    // Todo: exception if dimensions are not compatible
    size = A.size().lines;

}

//=================================================================================================
Matrix iterativeSolvers::solve() {

    // Todo : STOP AFTER max_iter ITERATION
    size_t i = 1;
    error = eps+1;
    while(error > eps && i < 100000){
        cout << "Iteration : " << i << " Error : " << error <<  "\r";

        cout.flush();
        try{
            step();
        } catch( char const* str){
            cout << str << endl;
        }
        i++;
    }
    return X;

}

//=================================================================================================
//gaussSeidel::gaussSeidel(Matrix A, Matrix B, double eps, double error) : eps(eps), error(error)  {}

//=================================================================================================
//void gaussSeidel::step() {
//
//    //int k = 0;
//    //while (k < max_iterations)
//    //{
//    for (size_t i = 0; i < size; i++)
//    {
//        double y = (B[i][0] / A[i][i]);
//        for (size_t j = 0; j < size; j++)
//        {
//            if (j == i) continue;
//
//            y = y - ((A[i][j] / A[i][i]) * X[j][0]);
//            X[i][0] = y;
//        }
//    }
//
//    //    k++;
//    //}
//
//    error = Vector(A*X - B).norm();
//
//}