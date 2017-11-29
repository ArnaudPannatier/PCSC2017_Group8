//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#ifndef PCSC2017_GROUP8_MATRIX_H
#define PCSC2017_GROUP8_MATRIX_H

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

typedef vector < vector<double> > vector2D;

struct Dimension {
    Dimension();
    Dimension(size_t i, size_t j);

    void transpose();

    size_t lines;
    size_t cols;
};

class Matrix {
public:
    //Constructors
    Matrix();
    explicit Matrix(vector< vector<double> > arr);
    explicit Matrix(initializer_list<initializer_list<double> > list);
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

    friend std::ostream& operator<<(std::ostream& output, const Matrix& m);
private:
    Dimension dim;
    vector2D values;
};

#endif //PCSC2017_GROUP8_MATRIX_H
