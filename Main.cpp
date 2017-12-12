//
// Created by Arnaud Pannatier on 12.12.17.
//

#include <iostream>
#include <string>
#include "Solver.h"
#include "Cholesky.h"
#include "inputOutput.h"
#include "ConjugateGradientDescent.h"

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

SolverName translateSolverName(string solver){
    if(solver == "Cholesky") return eCholesky;
    else if(solver == "LU") return eLU;
    else if(solver == "ConjugateGradient") return eConjugateGradient;
    else if(solver == "GaussSeidel") return eGaussSeidel;
    else if(solver == "Jacobi") return eJacobi;
    else if(solver == "Richardson") return eRichardson;
    else return Invalid_solver;
};

template <typename T>
T stoClass(string Xs, T defaultValue){
    if(Xs != "" && Xs != "-"){
        T ret;
        stringstream(Xs) >> ret;
        return ret;
    }else {
        return defaultValue;
    }
}


Solver* SolverFactory(string Solvers, string As, string Bs, string Xs = "", string epss = "", string max_iters = "", string supps=""){
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
            res = new ConjugateGradientDescent (A, B,  stoClass (Xs, Vector ()), Matrix (), stoClass (epss, 1e-9), stoClass (max_iters, size_t (100000)));
            break;

        default:
            throw "Wrong Solver Exception";

    }
    return res;

};
void getStringForIterative(string &x, string &eps, string& max_iter){
    cout << "What is the path to your Matrix X_0 (start point of the iteration)(press ENTER if you don't want to provide one) : " << endl;
    cin >> x;
    cout << "What is the precised recursion (press ENTER for eps = 1e-6) : " << endl;
    cin >> eps;
    cout  << "What is the max number of iteration that you want to do (press ENTER for 100000) " << endl;
    cin >> max_iter;
}



void getStringFromCin(string& sol, string& a, string& b, string& x, string& eps, string& max_iter, string& supp){
    cout << "What solver do you want to use (LU, Cholesky, ConjugateGradient, GaussSeidel, Jacobi, Richardson) : " << endl;
    cin >> sol;
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



int main(int argc, char *argv[]){
    // Syntax expected                  : ./Main Solver A.txt B.txt [optionnal] X.txt eps max_iter preconditionner/omega
    // For direct solver (LU/Cholesky)  : ./Main Solver A.txt B.txt
    // For iterative solver             : ./Main Solver A.txt B.txt [optionnal] X.txt eps max_iter
    //      Special cases               :
    //      Conjugate Gradient          : ./Main Solver A.txt B.txt [optionnal] X.txt eps max_iter preconditionner
    //      Richardson                  : ./Main Solver A.txt B.txt [optionnal] X.txt eps max_iter omega

    cout << "Number of arguments : " << argc << endl;

    for(int i=0; i<argc; i++) {
        cout << "Argument " << i << " : " << argv[i] << endl;
    }

    string Solvers, As, Bs, Xs, epss, max_iters, supps;

    if(argc < 4){
        if(argc != 1){
            cout << "The number of arguments you provided does not corresponds to what is expected by the programm" << endl;
        }
        getStringFromCin(Solvers,As,Bs,Xs,epss, max_iters, supps);

    } else{

        Solvers     = argv[1];
        As          = argv[2];
        Bs          = argv[3];
        Xs          = (argc >=5 )? argv[4] : "";
        epss        = (argc >=6 )? argv[5] : "";
        max_iters   = (argc >=7 )? argv[6] : "";
        supps       = (argc <=8 )? argv[7] : "";
    }

    Solver * solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);

    Vector result = solver->solve();

    cout << "The vector that solves AX = B is :" << result << endl;

    delete solver;

    return 0;
}