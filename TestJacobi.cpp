//
// Created by Arnaud Pannatier on 04.12.17.
//

#include <iostream>
#include "utils.h"
#include "Matrix.h"
#include "Vector.h"
#include "Jacobi.h"

using namespace std;

int main(){

    Matrix A = readFromText ("A.txt");
    cout << "Matrix A : " << A << endl;
    Vector B(readFromText ("B.txt"));
    cout << "Vector B :" << B << endl;

    cout << "--- Start Of Jacobi Test --------------- " << endl;
    Jacobi jacobi(A,B);
    Vector sol(jacobi.solve());
    cout << "solution : " << sol << endl;
    cout << " A * X = " << A*sol << endl;

    Matrix A2 = readFromText ("A2.txt");
    cout << "Matrix A2 : " << A2 << endl;
    Vector B2(readFromText ("B2.txt"));
    cout << "Vector B2 :" << B2 << endl;


    Jacobi jacobi2(A2,B2);
    Vector sol2(jacobi2.solve());
    cout << "solution : " << sol2 << endl;
    cout << " A2 * X = " << A2*sol2 << endl;

    return 0;
}
