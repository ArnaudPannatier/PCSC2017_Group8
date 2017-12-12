//
// Created by Haziq on 12/7/17.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include "Matrix.h"
#include <iostream>
#include <exception>
#include "string.h"

using namespace std;

class Exceptions {

public:

    static void LinearSystemsException(const Matrix & A, const Matrix & B);

    static void DimensionsException(const Matrix & A, const Matrix & B);

    static void SquareMatrixException();

    static void SymmetricMatrixException(const Matrix & A);

    static void InvertibleException(const Matrix &A);

};


#endif //PROJECT_EXCEPTIONS_H
