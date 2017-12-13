//
// Created by pcsc on 12/7/17.
//

#include "Exceptions.h"

void Exceptions::LinearSystemsException(const Matrix &A, const Matrix &B) {
    throw std::length_error("Invalid system of equations. \n"
                                    "Size of A is [" + std::to_string(A.size().lines) + "," + std::to_string(A.size().cols) + "]\n"
                                    "Size of B is [" + std::to_string(B.size().lines) + "," + std::to_string(B.size().cols) + "]\n");
}

void Exceptions::DimensionsException(const Matrix &A, const Matrix &B) {
    throw std::runtime_error("Invalid dimensions. Input matrix sizes are [" + std::to_string(A.size().lines) + "," + std::to_string(A.size().cols) + "] "
                                     " and [" + std::to_string(B.size().lines) + "," + std::to_string(B.size().cols) + "]\n");
}

void Exceptions::SquareMatrixException() {
    throw std::runtime_error("Input matrix is not square");
}

void Exceptions::SymmetricMatrixException(const Matrix & A) {
    throw std::runtime_error("Input matrix is not symmetric");
}

void Exceptions::InvertibleException(const Matrix &A) {
    throw std::runtime_error("Input matrix is not invertible");
}