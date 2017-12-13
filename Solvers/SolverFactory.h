//
// Created by Arnaud Pannatier on 12.12.17.
//

#ifndef PROJECT_SOLVERFACTORY_H
#define PROJECT_SOLVERFACTORY_H

#include <iostream>
#include <string>
#include "Solver.h"
#include "../Helpers/inputOutput.h"
#include "LU.h"
#include "Cholesky.h"
#include "ConjugateGradientDescent.h"
#include "GaussSeidel.h"
#include "Jacobi.h"
#include "Richardson.h"
#include "Preconditioners.h"
#include "PCConjugateGradientDescent.h"

using namespace std;


// TODO : TEST FOR SOLVER FACTORY !!

enum SolverName {
    eCholesky,
    eLU,
    eConjugateGradient,
    eGaussSeidel,
    eJacobi,
    eRichardson,
    Invalid_solver
};

SolverName translateSolverName(string solver);

template <typename T>
T stoClass(string Xs, T defaultValue);

Solver* SolverFactory(string Solvers, string As, string Bs, string Xs = "", string epss = "", string max_iters = "", string supps="");

void getStringForIterative(string &x, string &eps, string& max_iter);
void getStringFromCin(string& sol, string& a, string& b, string& x, string& eps, string& max_iter, string& supp);



#endif //PROJECT_SOLVERFACTORY_H
