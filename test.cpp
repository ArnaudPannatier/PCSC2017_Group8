//
// Created by Arnaud Pannatier on 30.11.17.
//

#include <iostream>
#include <vector>

#include "inputOutput.h"
#include "directSolvers.h"
#include "iterativeSolvers.h"

using namespace std;

typedef vector < vector<double> > vector2D;

int main(){

    cout << " It is working" << endl;
    vector2D test = vector2D(3,{1,2,3});
    cout << "Case 1,1 = " <<test[1][1] << endl;

    // ============================================================
    // Test for read text

    inputOutput io;
    Matrix A = io.readFromText("A.txt");
    Matrix b = io.readFromText("b.txt");
    cout << "A: " << A << endl << "b: " << b << endl;

    // ============================================================
    // Test for solvers
    // todo: non square matrices, unequal row for A and b
    // todo: matmul - return scalar when number of elements drop to 1
    // todo: 1d matrix = always row

    // Test for LU factorization
    // todo: division by zero

    directSolvers dSolvers(A, b);
    dSolvers.LU();

    Matrix L = dSolvers.getL();
    Matrix U = dSolvers.getU();
    Matrix x = dSolvers.getX();

    cout << "L: " << L << endl;
    cout << "U: " << U << endl;
    cout << "LU: " << L*U << endl;
    cout << "X: " << x << endl;

    // ============================================================
    // Test for iterative solvers
    // todo: non symmetric, psd

    Matrix A2({{4,1},{1,3}});
    Matrix b2({{1,2}}), x_0({{2,1}});

    // todo: row vector default ?
    b2 = b2.T();
    x_0 = x_0.T();

    // initialize iterative solver
    iterativeSolvers itSolvers(A2, b2);

    // conjugate gradient descent
    cout << "x: " << itSolvers.conjugateGradientDescent(x_0) << endl;

    // gauss seidel
    cout << "x: " << itSolvers.gaussSeidel(x_0) << endl;

    return 0;
}
