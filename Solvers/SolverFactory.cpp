//
// Created by Arnaud Pannatier on 12.12.17.
//

#include "SolverFactory.h"

SolverName translateSolverName (string solver) {
    if(solver == "Cholesky") return eCholesky;
    else if(solver == "LU") return eLU;
    else if(solver == "ConjugateGradient") return eConjugateGradient;
    else if(solver == "GaussSeidel") return eGaussSeidel;
    else if(solver == "Jacobi") return eJacobi;
    else if(solver == "Richardson") return eRichardson;
    else return Invalid_solver;
}

template<typename T>
T stoClass (string Xs, T defaultValue) {
    if(Xs != "" && Xs != "-"){
        T ret;
        stringstream(Xs) >> ret;
        return ret;

    }else {
        return defaultValue;
    }
}

Solver *SolverFactory (string Solvers, string As, string Bs, string Xs, string epss, string max_iters, string supps) {
    Matrix A = inputOutput::readFromText(As);
    Vector B = Vector(inputOutput::readFromText(Bs));

    Solver * res = NULL;
    switch(translateSolverName(Solvers)){
        case eLU :
            res = new LU(A,B);
            break;

        case eCholesky :
            res = new Cholesky(A,B);
            break;

        case eConjugateGradient:
            res = new ConjugateGradientDescent (A, B,  stoClass (Xs, Vector ()), stoClass(supps,Matrix ()), stoClass (epss, 1e-6), stoClass (max_iters, size_t (100000)));
            break;
        case eGaussSeidel :
            res = new GaussSeidel(A,B, stoClass(Xs,Vector()), stoClass(epss, 1e-6), stoClass (max_iters,size_t (100000)));
            break;

        case eJacobi :
            res = new Jacobi(A,B, stoClass(Xs,Vector()), stoClass(epss,1e-6), stoClass (max_iters, size_t(100000)));
            break;

        case eRichardson:
            cout << supps << endl;
            res = new Richardson(A,B,stoClass(supps, 0.1), stoClass(Xs,Vector()) , stoClass(epss, 1e-6), stoClass(max_iters, size_t(100000)));
            break;
        default:
            throw "Wrong Solver Exception";

    }
    return res;

}

void getStringForIterative (string &x, string &eps, string &max_iter) {
    cout << "What is the path to your Matrix X_0 (start point of the iteration)(press ENTER if you don't want to provide one) : " << endl;
    cin >> x;
    cout << "What is the precised recursion (press ENTER for eps = 1e-6) : " << endl;
    cin >> eps;
    cout  << "What is the max number of iteration that you want to do (press ENTER for 100000) " << endl;
    cin >> max_iter;
}

void getStringFromCin (string &sol, string &a, string &b, string &x, string &eps, string &max_iter, string &supp) {
    while(translateSolverName(sol) == Invalid_solver) {
        cout << "What solver do you want to use (LU, Cholesky, ConjugateGradient, GaussSeidel, Jacobi, Richardson) : " << endl;
        cin >> sol;
    }
    cout << "What is the path to your Matrix A (A.txt) : " << endl;
    cin >> a;
    cout << "What is the path to your Matrix B (B.txt) : " << endl;
    cin >> b;

    switch(translateSolverName(sol)){
        case eCholesky:
        case eLU:
            x = ""; eps = ""; max_iter = ""; supp ="";
            break;
        case eGaussSeidel:
        case eJacobi:
            getStringForIterative (x,eps,max_iter);
            break;
        case eConjugateGradient:
            getStringForIterative (x,eps,max_iter);
            // TODO : ADD preconditionners
            cout << "Do you want to use a preconditionner : (press ENTER for no, )" << endl;
            supp = "";
            break;
        case eRichardson:
            getStringForIterative (x,eps,max_iter);
            cout << "What is your omega for Richardson Iteration (press ENTER for 0.1)" << endl;
            cin >> supp;
            break;
        default:
            throw "Wrong Solver Exception";
    }
    // Special cases

}
