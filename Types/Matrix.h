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

/// @brief Dimension class to complement the Matrix class

struct Dimension {

    /// @brief Default constructor to initialize an empty dimensions
    Dimension();

    /// @brief Initializes the dimensions of the matrix with i rows and j columns
    Dimension(size_t i, size_t j);

    void transpose();

    /// @brief Returns true if the dimensions of the two matrices checked are equal
    bool operator==(const Dimension&) const ;

    /// @brief Returns false if the dimensions of the two matrices checked are equal
    bool operator!=(const Dimension&) const ;

    /// @brief Number of rows of the matrix
    size_t lines;

    /// @brief Number of columns of the matrix
    size_t cols;
};

/// @brief 2-dimensional matrix class

class Matrix {
public:

    /// @brief Default constructor to initialize an empty matrix
    Matrix();

    /// @brief Initializes a matrix from a vector of vectors
    explicit Matrix(vector< vector<double> > arr);

    Matrix(initializer_list<initializer_list<double> > list);

    /// @brief Initializes a zero matrix with i rows and j cols
    Matrix(size_t i, size_t j);

    // Public Methods
    void Transpose();

    /// @brief Transposes the matrix
    Matrix T() const;

    /// @brief Returns true if the matrix is multipliable
    bool multipliable(const Matrix& m) const;
    virtual Dimension size() const;

    /// @brief Returns the inverse of the matrix
    Matrix Inverse() const;

    /// @brief returns the diagonal elements of the matrix
    Matrix Diagonal() const;

    // Properties
    bool hasZeroOnDiag() const;

    /// @brief returns true if the matrix is square
    bool isSquare() const;

    /// @brief returns true if the matrix is symmetric
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

    /// @brief Overloaded operator for matrix-matrix addition
    Matrix operator+(const Matrix& m) const;

    /// @brief Overloaded operator for matrix-matrix subtraction
    Matrix operator-(const Matrix& m) const;

    /// @brief Overloaded operator for matrix-scalar multiplication
    Matrix operator*(const double& d) const;

    /// @brief Overloaded operator for matrix-matrix multiplcation
    Matrix operator*(const Matrix& m) const;

    /// @brief Overloaded operator for printing the elements of the matrix
    friend ostream& operator<<(ostream& output, const Matrix& m);
    friend istream& operator >>(std::istream &is, Matrix& m);

protected:

    /// @brief Dimensions of the matrix
    Dimension dim;

    /// @brief elements of the matrix
    vector2D values;
    double epsilonMatrix = 1e-12;
};

#endif //PCSC2017_GROUP8_MATRIX_H
