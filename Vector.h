//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#include "Matrix.h"
using namespace std;

class Vector : public Matrix {
public:
    Vector(): Matrix(){};
    explicit Vector(vector<double>);
    explicit Vector(const Matrix&);
    explicit Vector(size_t i): Matrix(i,1){};

    const double& operator()(size_t i) const;

    double norm() const;
    size_t len() const;

};

#endif //PROJECT_VECTOR_H
