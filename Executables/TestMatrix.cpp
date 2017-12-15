//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//
#include <iostream>
#include "gtest/gtest.h"
#include "../Solvers/Solver.h"
#include "../Solvers/SolverFactory.h"


using namespace std;

// MATRIX TESTS // -------------------------------------------------------------------------------
TEST(MatrixTest, Constructors){
    Matrix m0;
    EXPECT_EQ(0, m0.size().lines);
    EXPECT_EQ(0, m0.size().cols);
    EXPECT_EQ(0, m0.getValues().size());
    Matrix m1({{1,2,3},{1,2,3}});
    EXPECT_EQ(2, m1.size().lines);
    EXPECT_EQ(3, m1.size().cols);
    EXPECT_EQ(2, m1.getValues().size());
    EXPECT_EQ(3, m1.getValues()[0].size());
    EXPECT_EQ(3, m1.getValues()[1][2]);
    Matrix m2(2,3);
    EXPECT_EQ(2, m2.size().lines);
    EXPECT_EQ(3, m2.size().cols);
    EXPECT_EQ(2, m2.getValues().size());
    EXPECT_EQ(3, m2.getValues()[0].size());
    EXPECT_EQ(0, m2.getValues()[1][2]);
    Matrix m3(m2);
    EXPECT_EQ(2, m3.size().lines);
    EXPECT_EQ(3, m3.size().cols);
    EXPECT_EQ(2, m3.getValues().size());
    EXPECT_EQ(3, m3.getValues()[0].size());
    EXPECT_EQ(0, m3.getValues()[1][2]);
}
TEST(MatrixTest, AccessorMutator){
    Matrix m0(2,3);
    Matrix m1 = m0;
    EXPECT_EQ(m0.getValues(), m1.getValues());
    m1[1][2] = 3;
    EXPECT_EQ(3, m1[1][2]);
    EXPECT_EQ(0, m0[1][2]);
    // ACCESSOR
    EXPECT_EQ(3, m1[1][2]);
    EXPECT_EQ(3, m1(1,2));
    // MUTATOR
    m1(1,2) = 10;
    EXPECT_EQ(10, m1(1,2));
}

// VECTOR TEST // -------------------------------------------------------------------------------
TEST(VectorTest, Constructor){
    Vector v0;
    EXPECT_EQ(0, v0.size().lines);
    EXPECT_EQ(0, v0.size().cols);
    EXPECT_EQ(0, v0.getValues().size());
    auto vec1 = vector<double>({1,2,3});
    Vector v1 = Vector(vec1);
    EXPECT_EQ(3, v1.size().lines);
    EXPECT_EQ(1, v1.size().cols);
    EXPECT_EQ(3, v1.getValues().size());
    EXPECT_EQ(1, v1.getValues()[0].size());


}

// INPUT TEST // ----------------------------------------------------------------------------------

TEST(InputTest, BaseCase){
    Matrix A = Matrix({{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}});
    Vector B = Vector({6,25,-11,15});
    inputOutput io;
    Matrix Atxt = io.readFromText("../Examples/A.txt");
    Vector Btxt = Vector(io.readFromText("../Examples/B.txt"));

    EXPECT_EQ(A.size(), Atxt.size());
    EXPECT_EQ(B.size(), Btxt.size());
    EXPECT_EQ(A.getValues(), Atxt.getValues ());
    EXPECT_EQ(B.getValues (), Btxt.getValues ());

}
// LU TEST // -------------------------------------------------------------------------------------
TEST (LUdecomposition, BaseCase){
    Matrix A = Matrix({{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}});
    Vector B = Vector({6,25,-11,15});
    LU LUSolvers(A, B);
    Vector x = LUSolvers.solve();
    EXPECT_LT(Vector(A*x-B).norm(), 1e-6);
}
// CHOLESKY SOLVER // -----------------------------------------------------------------------------
TEST (Cholesky, BaseCase){
    Matrix A = Matrix({{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}});
    Vector B = Vector({6,25,-11,15});
    Cholesky ChoSolvers(A, B);
    Vector x = ChoSolvers.solve();
    EXPECT_LT(Vector(A*x-B).norm(), 1e-6);
}

// Conjugate Gradient Descent Test // -------------------------------------------------------------
TEST(ConjugateGradient, BaseCase){
    const Matrix A = inputOutput::readFromText ("../Examples/A10by10.txt");
    const Vector B = Vector(inputOutput::readFromText ("../Examples/B10by10.txt"));


    // initialize iterative solver
    ConjugateGradientDescent conjSolver(A, B);
    Vector X = conjSolver.solve();
    EXPECT_LT(Vector(A*X-B).norm(), 1e-6);

}

// Preconditionnate Gradient Descent // -----------------------------------------------------------
/*
TEST(PreconditionnateConjugateGradient, BaseCase){
    const Matrix A = inputOutput::readFromText ("../Examples/A10by10.txt");
    const Vector B = Vector(inputOutput::readFromText ("../Examples/B10by10.txt"));
    Matrix P = Preconditioners::Jacobi(A);

    // initialize iterative solver
    PCConjugateGradientDescent conjSolver(A, B, Vector(), P);
    Vector X = conjSolver.solve();
    EXPECT_LT(Vector(A*X-B).norm(), 1e-6);


    P = Preconditioners::GaussSeidel(A);

    PCConjugateGradientDescent conjSolver2(A, B, Vector(), P);
    X = conjSolver2.solve();
    EXPECT_LT(Vector(A*X-B).norm(), 1e-6);

}
*/

// Gauss Seidel Test // ---------------------------------------------------------------------------
TEST(GaussSeidel, BaseCase) {
    const Matrix A({{4,1},{1,3}});
    const Vector B({1,2});
    Vector x_0({2,1});
    GaussSeidel gaussSolver (A, B, x_0);
    Vector X = gaussSolver.solve ();
    EXPECT_LT(Vector (A * X - B).norm (), 1e-6);
}
// JACOBI TEST // ---------------------------------------------------------------------------------
TEST(Jacobi, BaseCase){
    Matrix A = Matrix({{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}});
    Vector B = Vector({6,25,-11,15});
    Jacobi jacobi(A,B);
    Vector sol(jacobi.solve());
    EXPECT_LT(Vector(A*sol-B).norm(), 1e-6);
    Jacobi jacobi2(A,B, Vector(), 1e-9);
    sol = (jacobi2.solve());
    EXPECT_LT(Vector(A*sol-B).norm(), 1e-9);

    A = Matrix({{2,1},{5,7}});
    B = Vector({11,13});

    jacobi = Jacobi(A,B);
    sol = (jacobi.solve());
    EXPECT_LT(Vector(A*sol-B).norm(), 1e-6);
    jacobi2= Jacobi(A,B, Vector(), 1e-9);
    sol = (jacobi2.solve());
    EXPECT_LT(Vector(A*sol-B).norm(), 1e-9);

}

// RICHARDSON TEST // ------------------------------------------------------------------------------
TEST(Richardson, BaseCase){
    Matrix A = Matrix({{10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}});
    Vector B = Vector({6,25,-11,15});
    Richardson richardson(A,B, 0.1);
    Vector sol(richardson.solve());

    EXPECT_LT(Vector(A*sol-B).norm(), 1e-6);
    Richardson richardson2(A,B, 0.1, Vector(), 1e-9);
    sol = (richardson2.solve());
    EXPECT_LT(Vector(A*sol-B).norm(), 1e-9);
}

// SOlVER FACTORY TEST // --------------------------------------------------------------------------

TEST(SolverFactory, stoClass){
    Vector B(stoClass("-", Vector()));
    EXPECT_EQ(B.len(), 0);

    // NOTE : Disable this test if you remove B10x10.txt

    B = stoClass("B10by10.txt", Vector());
    EXPECT_EQ(B.len(), 10);

    double eps(stoClass("", 0.0));
    EXPECT_EQ (eps, 0.0);
    eps = stoClass("1e-5", 0.0);
    EXPECT_EQ (eps, 1e-5);

    size_t max_iter(stoClass("", size_t(100000)));
    EXPECT_EQ (max_iter, 100000);
    max_iter = stoClass("100", size_t(100000));
    EXPECT_EQ (max_iter, 100);


}



TEST(SolverFactory, SolvesWithStandardinput){

    // For iterative solver             : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    //      Special cases               :
    //      PCConjugate Gradient        : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter preconditinner
    //      Richardson                  : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter omega


    // Syntax expected                 : ./Main A.txt B.txt
    string Solvers="ConjugateGradient", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "", epss="", max_iters="", supps="";
    Matrix A(inputOutput::readFromText(As)), B(inputOutput::readFromText (Bs));
    Solver * solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    Vector result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-6);

    // For direct solver (LU/Cholesky)  : ./Main Solver A.txt B.txt
    Solvers="LU", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "", epss="", max_iters="", supps="";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-6);

    // For direct solver (LU/Cholesky)  : ./Main Solver A.txt B.txt
    Solvers="Cholesky", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "", epss="", max_iters="", supps="";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-6);


    // For iterative solvers : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    Solvers="ConjugateGradient", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "../Examples/X10by10.txt", epss="1e-8", max_iters="10000000", supps="";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-8);

    // For iterative solvers : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    Solvers="PCConjugateGradient", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "../Examples/X10by10.txt", epss="1e-8", max_iters="10000000", supps="Jacobi";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-8);

    // For iterative solvers : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    Solvers="GaussSeidel", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "../Examples/X10by10.txt", epss="1e-8", max_iters="10000000", supps="";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-8);


    // For iterative solvers : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    Solvers="Jacobi", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "../Examples/X10by10.txt", epss="1e-8", max_iters="10000000", supps="";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-8);


    // For iterative solvers : ./Main Solver A.txt B.txt [optional] X.txt eps max_iter
    Solvers="Richardson", As="../Examples/A10by10.txt", Bs="../Examples/B10by10.txt", Xs = "../Examples/X10by10.txt", epss="1e-8", max_iters="10000000", supps="0.01";
    delete solver;
    solver = SolverFactory(Solvers,As,Bs,Xs,epss, max_iters,supps);
    result = solver->solve();
    EXPECT_LT(Vector(A*result-B).norm(), 1e-8);

    delete solver;
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
