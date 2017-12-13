# MATH-458 - PCSC - Group 8 - Linear solvers

This C++ project consist in solving linear system _Ax = b_ by different methods.

7 solvers are implemented : LU decomposition, Cholesky decomposition, Conjugate Gradient Descent, Preconditionate Conjugate Gradient Descent, Jacobi, Gauss-Seidel, and Richardson method.
The two first solvers are direct methods and the others are iterative methods.

This project is a part of the course : "*Programming concepts for scientific computing*" given at EPFL by **Guillaume Anciaux** in 2017.

**Authors : Muhammad Haziq Bin Razali, Arnaud Pannatier**
## Compilation
1. Clone this repository
```bash
$ git clone https://github.com/ArnaudPannatier/PCSC2017_Group8.git
```

### CMake
2. create a build directory
```bash
$ cd PCSC2017_Group8/
$ mkdir build
$ cd build
```
3. run CMake
```bash
cmake ..
make
```

### Clion

2. Ensure that you have [Clion](https://www.jetbrains.com/clion/) installed (tested on clion version 2017.2 on ubuntu and MacOSX)
3. Launch clion via bash
```bash
$ clion
```
4. Set the working directory to the root of the cloned file
5. Run the demo by setting the Run/Debug configuration dialog box to demo then clicking on Run (Green Arrow)

## Use the program with the executable

.....

## Typical program execution (the flow)
TODO : Add some description of the solvers and the wikipedia link


The program typically starts by instantating a Matrix and Vector object. This can be done in 2 ways: by reading from a text file, or by coding it manually as shown below. Note that each row of the Matrix A represents a single equation.

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
Vector X_sol_conj = conjSolver.solve();

// Example of running the jacobi
Jacobi jacobi(A2,B2);
Vector X_sol_jacobi = jacobi2.solve();
```

Lastly, the contents of any Matrix and Vector can be easily viewed using the output steam operator which has been overloaded to handle the Matrix and Vector class.
```c++
cout << X_conjSolver << endl;
cout << X_jacobi << endl;
```

## Available solvers

Below are the list of implemented solvers and their constructors

### Direct solvers :
- Lu
```c++
LU(A, B, opts[X_0])
```
- Cholesky
```c++
Cholesky(A,B, opts[X_0])
```

### Iterative solvers :
- Conjugate Gradient Descent

```c++
ConjugateGradientDescent(A, B, opts[ X_0, epsilson, max_iter ])
```

- Preconditionate Gradient Descent
```c++
PCConjugateGradientDescent(A,B, P, opts[ X_0, epsilson, max_iter ])
```
- Gauss Seidel
```c++
GaussSeidel(A, B, opts[ X_0, epsilson, max_iter ])
```
- Jacobi
 ```
 GaussSeidel(A, B, opts[ X_0, epsilson, max_iter ])
 ```
- Richardson
```
Richardson(A, B, omega, opts[ X_0, epsilson, max_iter ]);
```

## List of tests

### Matrix and Vector

### Solver

### Solver Factory

## TODOs and perspectives


