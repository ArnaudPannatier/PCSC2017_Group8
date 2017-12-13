//
// Created by Arnaud Pannatier on 08.12.17.
//

#include "Solver.h"


Solver::Solver (const Matrix &A_, const Vector &B_, const Vector &X_) {

    // throw an exception if the dimensions of the input matrices are invalid - isMultipliable
    try{
        if(A_.size().lines != B_.size().lines || A_.size().cols != B_.size().lines){
            Exceptions::LinearSystemsException(A_, B_);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        abort();
    }

    A = A_;
    B = B_;
    if(X_.len() != 0){
        X = X_;
    }else{
        X = Vector(B.len());
    }

}
