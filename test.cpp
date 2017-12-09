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

    cout << " It is working" << endl;
    vector2D test = vector2D(3,{1,2,3});
    cout << "Case 1,1 = " <<test[1][1] << endl;

    // ============================================================
    // Test for read text

    inputOutput io;
    Matrix A = io.readFromText("A.txt");
    Vector b = Vector(io.readFromText("b.txt"));
    cout << "A: " << A << endl << "b: " << b << endl;

    // ============================================================
    // Test for solvers
    // todo: non square matrices, unequal row for A and b
    // todo: matmul - return scalar when number of elements drop to 1
    // todo: 1d matrix = always row

    // Test for LU factorization
    // todo: division by zero

    LU LUSolvers(A, b);
    LUSolvers.solve();

    Matrix L = LUSolvers.getL();
    Matrix U = LUSolvers.getU();
    Matrix x = LUSolvers.solve();

    cout << "L: " << L << endl;
    cout << "U: " << U << endl;
    cout << "LU: " << L*U << endl;
    cout << "X: " << x << endl;

    // ============================================================
    // Test for iterative solvers
    // todo: non symmetric, psd

    Matrix A2({{4,1},{1,3}});
    Vector B2({1,2}), x_0({2,1});

    // initialize iterative solver
    ConjugateGradientDescent conjSolver(A2, B2, x_0);

    // Conjugate Gradient Descent
    cout << "x: " << conjSolver.solve() << endl;

    GaussSeidel gaussSolver(A2,B2,x_0);
    // Gauss Seidel
    cout << "x: " << gaussSolver.solve() << endl;

    return 0;

}
