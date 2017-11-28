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

class Vector : public Matrix {
public:
    explicit Vector(valarray<double> arr);
};

#endif //PROJECT_VECTOR_H
