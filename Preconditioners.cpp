//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// PCSC 2017
//

#include "Preconditioners.h"
#include "LU.h"

Matrix Preconditioners::Jacobi(const Matrix &A) {
    return A.Diagonal();
}

Matrix Preconditioners::GaussSeidel(const Matrix &A) {
    LU LUSolver(A, Vector(A.size().lines));
    LUSolver.computeLU();

    return LUSolver.getL() + A.Diagonal();
}