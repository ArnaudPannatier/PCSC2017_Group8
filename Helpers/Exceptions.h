//
// Created by Haziq on 12/7/17.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include "../Types/Matrix.h"
#include <iostream>
#include <exception>


using namespace std;

class Exceptions {

public:

    static void LinearSystemsException(const Matrix & A, const Matrix & B);

    static void DimensionsException(const Matrix & A, const Matrix & B);

    static void SquareMatrixException();

    static void SymmetricMatrixException();

    static void InvertibleException();

};


#endif //PROJECT_EXCEPTIONS_H
