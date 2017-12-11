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
#include <cmath>

using namespace std;

typedef vector < vector<double> > vector2D;

struct Dimension {
    Dimension();
    Dimension(size_t i, size_t j);

    void transpose();

    bool operator==(const Dimension&) const ;
    bool operator!=(const Dimension&) const ;

    size_t lines;
    size_t cols;
};

class Matrix {
public:
    //Constructors
    Matrix();
    explicit Matrix(vector< vector<double> > arr);
    Matrix(initializer_list<initializer_list<double> > list);
    Matrix(size_t i, size_t j);

    //Public Methods
    void Transpose();
    Matrix T() const;
    bool multipliable(const Matrix& m) const;
    virtual Dimension size() const;

    // Properties
    bool hasZeroOnDiag() const;
    bool isSquare() const;
    bool isSymmetric() const;

    // Operators
    Matrix operator-() const;
    //Mutator
    vector<double>& operator[](size_t i);
    double& operator()(size_t i, size_t j);
    // Accessor
    const vector<double>& operator[](size_t i) const;
    const double& operator()(size_t i, size_t j) const;

    vector2D getValues() const { return values; };

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const double& d) const;
    Matrix operator*(const Matrix& m) const;

    friend ostream& operator<<(ostream& output, const Matrix& m);
protected:
    Dimension dim;
    vector2D values;
    double epsilonMatrix = 1e-12;
};

#endif //PCSC2017_GROUP8_MATRIX_H
