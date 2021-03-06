//
// Created by Haziq on 12/7/17.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include "../Types/Matrix.h"
#include <iostream>
#include <exception>


using namespace std;

/// @brief Exceptions class for matrices

class Exceptions {

public:

    /// @brief Exception if the dimensions of A and B are invalid
    static void LinearSystemsException(const Matrix & A, const Matrix & B);

    /// @brief Exception of the operation involving two matrices are invalid
    static void DimensionsException(const Matrix & A, const Matrix & B);

    /// @brief Exception if matrix is not square
    static void SquareMatrixException();

    static void SymmetricMatrixException();

    /// @brief Exception if the matrix is invertible
    static void InvertibleException();

};


#endif //PROJECT_EXCEPTIONS_H
