//
// Created by Arnaud Pannatier on 30.11.17.
//

#include <iostream>
#include <vector>

#include "utils.h"
#include "LU.h"
#include "iterativeSolvers.h"

using namespace std;

typedef vector < vector<double> > vector2D;

int main(){

    cout << " It is working" << endl;
    vector2D test = vector2D(3,{1,2,3});
    cout << "Case 1,1 = " <<test[1][1] << endl;

    // ============================================================
    // Test for read text
    Matrix A = readFromText("A.txt");
    Matrix b = readFromText("b.txt");
    cout << "A: " << A << endl << "b: " << b << endl;

    // ============================================================
    // Test for LU factorization
    // todo: non square matrices, infinity

    directSolvers dSolvers(A, b);
    dSolvers.LU();

    Matrix L = dSolvers.getL();
    Matrix U = dSolvers.getU();
    //Matrix x = dSolvers.getX();

    cout << "L: " << L << endl;
    cout << "U: " << U << endl;
    cout << "LU: " << L*U << endl;

    // ============================================================
    // Test for conjugate gradient descent
    // todo: non symmetric, psd

    Matrix A2({{4,1},{1,3}});
    Matrix b2({{1,2}}), x_0({{2,1}});

    // todo: row vector default ?
    b2 = b2.T();
    x_0 = x_0.T();

    iterativeSolvers itSolvers(A2, b2);

    cout << "x: " << itSolvers.conjugateGradientDescent(x_0) << endl;
    cout << "x: " << itSolvers.gaussSeidel(x_0) << endl;

    return 0;
}
