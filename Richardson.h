//
// Created by Arnaud Pannatier on 05.12.17.
//

#ifndef PROJECT_RICHARDSON_H
#define PROJECT_RICHARDSON_H

#include "Matrix.h"
#include "IterativeSolvers.h"

class Richardson : public IterativeSolvers {
public:
    Richardson (const Matrix &A_, const Vector &B_, double omega_, const Vector &X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 100000);

    void step() final;

    //TODO : compute omega with the condition number \omega_opt = 2/(\lambda_min(A) +\lambda_max(A))


protected:
    double omega;
};


#endif //PROJECT_RICHARDSON_H
