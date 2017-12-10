//
// Created by pcsc on 12/7/17.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include "Matrix.h"
#include <iostream>
#include <exception>
#include "string.h"

using namespace std;

class Exceptions: public std::exception {

public:

    static void LinearSystemsException(const Matrix & A, const Matrix & B) {
        throw std::length_error("Invalid system of equations. \n"
              "Size of A is [" + std::to_string(A.size().lines) + "," + std::to_string(A.size().cols) + "]\n"
              "Size of B is [" + std::to_string(B.size().lines) + "," + std::to_string(B.size().cols) + "]\n");
    }

    static void DimensionsException(const Matrix & A, const Matrix & B) {
        throw std::runtime_error("Invalid Dimensions. \n"
                                         " Input matrix sizes are [" + std::to_string(A.size().lines) + "," + std::to_string(A.size().cols) + "] "
                                         " and [" + std::to_string(B.size().lines) + "," + std::to_string(B.size().cols) + "]\n");
    }

};


#endif //PROJECT_EXCEPTIONS_H
