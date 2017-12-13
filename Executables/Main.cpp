//
// Created by Arnaud Pannatier on 12.12.17.
//

#include <iostream>
#include "../Solvers/Solver.h"
#include "../Solvers/SolverFactory.h"

using namespace std;

int main(int argc, char *argv[]){

    // If you just want to solve the matrix
    // Synthax expected                 : ./Main A.txt B.txt

    // If the solver is known
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

    string Solvers, As, Bs, Xs = "", epss="", max_iters="", supps="";

    if(argc == 3) {
        Solvers     = "ConjugateGradient";
        As          = argv[1];
        Bs          = argv[2];

    }else if(argc < 4){
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
        supps       = (argc >=8 )? argv[7] : "";
    }

    Solver * solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);

    Vector result = solver->solve();

    cout << "The vector that solves AX = B is :" << result << endl;

    delete solver;

    return 0;
}