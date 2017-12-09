//
// Created by Arnaud Pannatier on 05.12.17.
//

#include <iostream>
#include "inputOutput.h"
#include "Richardson.h"


using namespace std;

int main(){

    inputOutput io;

    Matrix A = io.readFromText ("A.txt");
    cout << "Matrix A : " << A << endl;
    Vector B(io.readFromText ("B.txt"));
    cout << "Vector B :" << B << endl;

    cout << "--- Start Of Richardson Test --------------- " << endl;
    Richardson richardson(A,B, 0.1);
    Vector sol(richardson.solve());
    cout << "solution : " << sol << endl;
    cout << " A * X = " << A*sol << endl;

    return 0;
}