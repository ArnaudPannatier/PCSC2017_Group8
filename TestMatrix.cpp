//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    cout << "--- Start of the Tests of the Matrix Class -----------" <<endl;
    cout << "-- Constructors and print : " << endl;
    Matrix m0;
    cout << "- Empty Matrix : " << m0;
    Matrix m1({{1,2,3},{1,2,3}});
    cout << "- Initializer list {{1,2,3},{1,2,3}} :" << m1;

    cout << "-- Accessing : " << endl;
    cout << "m1(1,2) = " << m1(1,2) << endl;
    cout << "m1[1][2] = " << m1[1][2] << endl;

    cout << "-- Mutating : " << endl;
    cout << "mutate : m1(1,2) = 5" << endl;
    m1(1,2) = 5;
    cout << "m1(1,2) = " << m1(1,2) << endl;
    cout << "mutate : m1[0][1] = 6" << endl;
    m1[0][1] = 6;
    cout << "mutate : m1[0][1] = " << m1[0][1] <<endl;


    return 0;
}
