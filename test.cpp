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
    // Test for read text

    inputOutput io;
    Matrix A = io.readFromText("A.txt");
    Vector b = Vector(io.readFromText("B.txt"));

    // ============================================================
    // Test for preconditioning
    // Jacobi
    Matrix M_Jacobi = A.Diagonal();

    // Gauss Seidel
    LU LUSolver(A, b);
    LUSolver.solve();
    Matrix M_GaussSeidel = LUSolver.getL() + A.Diagonal();

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
