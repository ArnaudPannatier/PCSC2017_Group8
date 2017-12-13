//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#include "Matrix.h"
#include <initializer_list>
using namespace std;

/// @brief 1-dimensional Vector class

class Vector : public Matrix {
public:

    Vector(): Matrix(){};

    /// @brief Initializes the vector from an STL vector
    explicit Vector(vector<double>);


    Vector(initializer_list<double> list);

    /// @brief Initializes the vector from a 1-dimensional matrix
    explicit Vector(const Matrix&);


    explicit Vector(size_t i): Matrix(i,1){};

    // Accessor
    const double& operator()(size_t i) const;

    // Mutator
    double& operator()(size_t i);

    /// @brief Computes the dot product of 2 vectors
    double dot(const Vector& v) const;

    /// @brief Computes the norm of the matrix
    double norm() const;

    /// @brief Returns the length of the matrix
    size_t len() const;

};

#endif //PROJECT_VECTOR_H
