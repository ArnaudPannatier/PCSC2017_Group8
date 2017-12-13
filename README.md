# MATH-458 - PCSC - Group 8 - Linear solvers

This C++ project is solving linear system _Ax = b_ by using different methods.
Two principals differences distinguishes the solvers ....

## Compilation

TODO : compilation with CMake

1. Ensure that you have [clion](https://www.jetbrains.com/clion/) installed (tested on clion version 2017.2 on ubuntu)
2. Clone this repository
3. Launch clion via bash
```bash
$ clion
```
4. Set the working directory to the root of the cloned file
5. Run the demo by setting the Run/Debug configuration dialog box to demo then clicking on Run (Green Arrow)

## Typical program execution (the flow) and usage

The program typically starts by instantating a Matrix and Vector object. This can be done in 2 ways: by reading from a text file, or by coding it manually as shown below. Note that each row of the Matrix A represents a single observation.

```c++
inputOutput io;
Matrix A1 = io.readFromText("A1.txt");
Vector b1 = Vector(io.readFromText("B1.txt"));

const Matrix A2({{1,1,-1},{1,-2,3},{2,3,-1}});
const Vector B2({4,-6,7});

```

We can then instantiate from the list of solvers below. Note that some of the iterative methods require an initial guess x_0 of the solution to Ax = b. 

```c++
// Example of running the conjugate gradient method
Vector x_0({2,1});
ConjugateGradientDescent conjSolver(A2, B2, x_0);
Vector X_conjSolver = conjSolver.solve();

// Example of running the jacobi
Jacobi jacobi(A2,B2);
Vector X_jacobi = jacobi2.solve();

```

Lastly, the contents of any Matrix and Vector can be easily viewed using the output steam operator which has been overloaded to handle the Matrix and Vector class.
```c++

cout << X_conjSolver << endl;
cout << X_jacobi << endl;

```

## Available solvers

Below are the list of implemented solvers and their constructors

- Conjugate Gradient Descent `ConjugateGradientDescent(A, B, X_0, epsilson, max_iter)`
- Gauss Seidel `GaussSeidel(A, B, X_0, epsilson, max_iter)`
- Jacobi `GaussSeidel(A, B)`
- Richardson `Richardson(A, B, omega)`

## List of tests



## TODOs and perspectives
