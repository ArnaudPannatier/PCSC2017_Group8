//
// Created by Arnaud Pannatier on 08.12.17.
//

#include "Solver.h"

Solver::Solver (const Matrix &A_, const Vector &B_, const Vector &X_) {
    A = A_;
    B = B_;
    if(X_.len() != 0){
        X = X_;
    }else{
        X = Vector(B.len());
    }
}
