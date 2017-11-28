//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#include "Matrix.h"
Matrix::Matrix () {
    dim = Dimension(0,0);
    values = valarray< valarray<double> >();
}
Matrix::Matrix (valarray< valarray<double> > arr) {
    size_t x = arr.size();
    size_t y = arr[0].size();
    dim = Dimension(x,y);
    values = arr;

}
Matrix::Matrix(const Matrix &m) {
    values = m.values;
    dim = m.dim;
}
double Matrix::Get(const int i, const int j) const {
    return 0;
}

void Matrix::Set(const int i, const int j, const double &value) {

}

void Matrix::Transpose() {

}

Matrix &Matrix::operator=(const Matrix &m) {
    values = m.values;
    dim = m.dim;
    return *this;
}

Matrix Matrix::operator-() const {
    Matrix m;
    m.values = values;
    return m;
}

Matrix Matrix::operator+(const Matrix &m) const {
    return Matrix();
}

Matrix Matrix::operator-(const Matrix &m) const {
    return Matrix();
}

Matrix Matrix::operator*(const double d) const {
    return Matrix();
}

Matrix Matrix::operator*(const Matrix &m) const {
    return Matrix();
}

Dimension::Dimension() {
    lines = 0;
    cols = 0;
}
Dimension::Dimension(int lines_, int col_) {
    lines = lines_;
    cols = col_;
}

