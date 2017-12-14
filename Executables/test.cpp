//
// Created by Arnaud Pannatier on 30.11.17.
//

#include <iostream>
#include <vector>

#include "../Types/Matrix.h"
#include "../Solvers/LU.h"
#include "../Helpers/inputOutput.h"
#include "../Solvers/ConjugateGradientDescent.h"
#include "../Solvers/PCConjugateGradientDescent.h"

using namespace std;

int main(){

    //Matrix t({{0,0,0},{0,0,0},{0,0,0}});
    //cout << t.Inverse() << endl;

    const Matrix A = inputOutput::readFromText("../Examples/A10by10.txt");
    const Vector B = Vector(inputOutput::readFromText("../Examples/B10by10.txt"));

    PCConjugateGradientDescent PCconjSolver(A, B, Vector(), A.Diagonal());
    ConjugateGradientDescent conjSolver(A, B, Vector());

    cout << PCconjSolver.solve() << endl;
    cout << conjSolver.solve() << endl;

    //return 0;

}
