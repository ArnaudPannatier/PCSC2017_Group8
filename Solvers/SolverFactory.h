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

enum SolverName {
    eCholesky,
    eLU,
    eConjugateGradient,
    ePCConjugateGradient,
    eGaussSeidel,
    eJacobi,
    eRichardson,
    Invalid_solver
};

/// @brief parses user input for solver method
SolverName translateSolverName(string solver);

/// @brief templated function that returns either the parsed string or a default value
template <typename T>
T stoClass(string Xs, T defaultValue);

/// @brief
Solver* SolverFactory(string Solvers, string As, string Bs, string Xs = "", string epss = "", string max_iters = "", string supps="");

/// @brief parses user input for iterative options
void getStringForIterative(string &x, string &eps, string& max_iter);

/// @brief parses user input
void getStringFromCin(string& sol, string& a, string& b, string& x, string& eps, string& max_iter, string& supp);



#endif //PROJECT_SOLVERFACTORY_H
