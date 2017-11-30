//
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
    explicit Vector(vector<double>);
    explicit Vector(size_t i): Matrix(1,i){};

    size_t size() const;
};

#endif //PROJECT_VECTOR_H
