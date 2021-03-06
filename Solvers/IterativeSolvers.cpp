//
// Created by Haziq on 12/1/17.
//

#include "IterativeSolvers.h"

Vector IterativeSolvers::solve () {
    size_t i = 0;
    error = eps + 1;
    cout << endl;
    while ( error > eps && i < max_iter ) {

        cout.flush ();
        step ();
        error = Vector(A*X - B).norm();
        i++;
        cout << "\r" << "Iteration : " << i << " Error : " << error;
    }
    cout << endl;
    return X;
}
