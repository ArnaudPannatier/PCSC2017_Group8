//
// Created by Arnaud Pannatier on 30.11.17.
//

#include <iostream>
#include <vector>

#include "Matrix.h"
#include "LU.h"
#include "inputOutput.h"
#include "ConjugateGradientDescent.h"
#include "GaussSeidel.h"

using namespace std;

int main(){

    // ============================================================
    // Test for exceptions

    // Invalid system of linear equations
    const Matrix A1({{1,1,1},{1,3,1}});
    const Vector B1({1,2,3});

    ConjugateGradientDescent test_conjSolver(A1, B1, B1);

    // Conjugate gradient method - A is not symmetric and positive definite

    // LU decomposition - division by zero



    // poorly formatted matrix

    // ============================================================
    // Test for solvers
    // todo: non square matrices, unequal row for A and b
    // todo: 1d matrix = always row

    // Test for LU factorization
    // todo: division by zero


    // ============================================================
    // Test for iterative solvers
    // todo: non symmetric, psd

    const Matrix A2({{4,1},{1,3}});
    const Vector B2({1,2});

    cout <<" Vector B: " << B2 << endl;
    Vector x_0({2,1});

    // initialize iterative solver
    ConjugateGradientDescent conjSolver(A2, B2, x_0);

    cout << "Start the test for conjugate gradient : " << endl;

    // Conjugate Gradient Descent
    Vector X = conjSolver.solve();
    cout << "x: " << X << endl;
    cout << "Ax-B"  << A2*X-B2 << endl;

    GaussSeidel gaussSolver(A2,B2,x_0);
    // Gauss Seidel
    cout << "x: " << gaussSolver.solve() << endl;

    return 0;

}
