//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#ifndef PCSC2017_GROUP8_MATRIX_H
#define PCSC2017_GROUP8_MATRIX_H

#include <iostream>
#include <valarray>

using namespace std;

struct Dimension {
    Dimension();
    Dimension(int i, int j);

    int lines;
    int cols;
};

class Matrix {
public:
    //Constructors
    Matrix();
    Matrix(valarray< valarray<double> > arr);
    Matrix(const Matrix& m);

    // Get Methods
    double Get(int i, int j) const;

    // Set Methods
    void Set(int i, int j, const double& value);

    //Public Methods
    void Transpose();

    // Operators
    Matrix& operator=(const Matrix& m);
    Matrix operator-() const;
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const double d) const;
    Matrix operator*(const Matrix& m) const;

private:
    Dimension dim;
    valarray < valarray<double> > values;
};

#endif //PCSC2017_GROUP8_MATRIX_H
