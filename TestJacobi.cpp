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

    return 0;
}
