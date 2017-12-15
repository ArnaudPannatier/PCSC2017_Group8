

<p align="center">
<a href="https://www.epfl.ch/"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT-vVrl4uJ_wi87EB-oh-tAntpf3ct4ev7i2BSJLaF_3mC6zhoc" /></a>
</p>

# MATH-458 - PCSC - Linear solvers

This C++ project consist in solving linear system _Ax = b_ by different methods.

7 solvers are implemented : LU decomposition, Cholesky decomposition, Conjugate Gradient Descent, Preconditioned Conjugate Gradient Descent, Jacobi, Gauss-Seidel, and Richardson method.
The first two solvers are direct methods and the others are iterative methods.

This project is a part of the course : "*Programming Concepts in Scientific Computing*" given at EPFL by **Guillaume Anciaux** in fall 2017.

**Authors : Muhammad Haziq Bin Razali, Arnaud Pannatier**

Group 8
## Compilation and Execution
1. Clone this repository
```bash
$ git clone https://github.com/ArnaudPannatier/PCSC2017_Group8.git
```

### CMake
2. Create a build directory
```bash
$ cd PCSC2017_Group8/
$ mkdir build
$ cd build
```
3. Run CMake
```bash
cmake ..
make
```

The google test API is downloaded during the build by CMake. If it does not work, please redo the cmake command.

### Clion

2. Ensure that you have [Clion](https://www.jetbrains.com/clion/) installed (tested on clion version 2017.2 on ubuntu and MacOSX)
3. Launch clion via bash
```bash
$ clion
```
4. Set the working directory to the root of the cloned file
5. Run the demo by setting the Run/Debug configuration dialog box to demo then clicking on Run (Green Arrow)

## Using the programm


### Executable

The simplest way of using the program is to simply run the executable with the proper arguments.

#### If you just want to solve the matrix
the syntax expected is :

```bash
$ ./Main ../Examples/A.txt ../Examples/B.txt
```
and it will use Conjugate gradient descend to solve the system.

#### If the solver is known
the syntax expected is :
 ```bash
 $ ./Main Solver ../Examples/A.txt ../Examples/B.txt [optionnal] X.txt eps max_iter preconditionner/omega
 ```

##### In particular :
For direct solvers (LU/Cholesky)  :
 ```bash
 $ ./Main LU ../Examples/A.txt ../Examples/B.txt
 ```

For iterative solvers (ConjugateGradient/Jacobi/GaussSeidel):
 ```bash
 $ ./Main Jacobi ../Examples/A.txt ../Examples/B.txt [optionnal] X.txt eps max_iter
 ```
##### Special cases:

Preconditionate Conjugate Gradient :
```bash
$ ./Main PCConjugateGradient ../Examples/A.txt ../Examples/B.txt [optionnal] X.txt eps max_iter [notoptional] preconditionner
$ ./Main PCConjugateGradient ../Examples/A.txt ../Examples/B.txt - - - Jacobi
```

preconitioner values : Jacobi/GaussSeidel for Jacobi or GaussSeidel preconditionners

Richardson:
```bash
$ ./Main Richardson ../Examples/A.txt ../Examples/B.txt [optionnal] X.txt eps max_iter omega
```

### CLion

The cases described bellow can be applied in CLion by using _Edit Configuration_ of the executable.

### From cin

You can run :
```bash
$ ./Main.cpp
```

and the needed arguments will be asked by the program.

## Typical program execution (the flow)


The program typically starts by instantating a Matrix and Vector object. This can be done in 2 ways: by reading from a text file, or by coding it manually as shown below. Note that each row of the `Matrix A represents a single equation.

```c++
inputOutput io;
Matrix A1 = io.readFromText("A1.txt");
Vector b1 = Vector(io.readFromText("B1.txt"));

const Matrix A2({{1,1,-1},{1,-2,3},{2,3,-1}});
const Vector B2({4,-6,7});
```

The user can then instantiate a solver from the list below. Note that some of the iterative methods require an initial guess x_0 to the solution to Ax = b and more arguments.

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


## List of Features
### Available solvers

Below are the list of implemented solvers and their constructors.

#### Direct solvers :
- LU

 Implements the LU decomposition of a matrix based on Crout's algorithm that returns a lower triangular matrix and a unit upper triangular matrix.

 https://en.wikipedia.org/wiki/Crout_matrix_decomposition

```c++
LU(A, B, opts[X_0])
```


- Cholesky

Implements the Cholesky decomposition of a matrix that returns a lower triangular matrix and its transpose. It's a special case of LU decomposition when the matrix A is symmetric.

https://en.wikipedia.org/wiki/Cholesky_decomposition

```c++
Cholesky(A,B, opts[X_0])
```

#### Iterative solvers :
- Conjugate Gradient Descent

Implements the method for conjugate gradient descent. Which has the property to converge when the matrix is symmetric definite positive. In the other cases, the convergence can appear as well but with no guarantee.

https://en.wikipedia.org/wiki/Conjugate_gradient_method

```c++
ConjugateGradientDescent(A, B, opts[ X_0, epsilson, max_iter ])
```

- Preconditioned Gradient Descent

Implements the method for preconditioned gradient descent. Preconditioning will ensure that the matrix has a smaller condition number. This should lead to a faster and numerically more stable convergence.

https://en.wikipedia.org/wiki/Conjugate_gradient_method

```c++
PCConjugateGradientDescent(A,B, P, opts[ X_0, epsilson, max_iter ])
```


- Gauss Seidel

Implements the Gauss-Seidel method for solving a system of linear equations.

https://en.wikipedia.org/wiki/Gauss%E2%80%93Seidel_method

```c++
GaussSeidel(A, B, opts[ X_0, epsilson, max_iter ])
```


- Jacobi

Implements the Jacobi method for solving a system of linear equations

https://en.wikipedia.org/wiki/Jacobi_method

 ```c++
Jacobi(A, B, opts[ X_0, epsilson, max_iter ])
 ```
- Richardson

Implements the Richardson Method for solving a system of linear equations

https://en.wikipedia.org/wiki/Modified_Richardson_iteration


```c++
Richardson(A, B, omega, opts[ X_0, epsilson, max_iter ]);
```

### Preconditioners

A class Preconditioner was added to provide preconditioner for preconditioned gradient descent.
Two basic preconditionner where implemented : Jacobi preconditioner and Gauss-Seidel preconditionner.

The Jacobi preconditioner only consist of the diagonal of the matrix A and the Gausse Seidel preconditionner consist of the lower triangular matrix of the LU decomposition on which the diagonal of the matrix A is added.

The tests seems to shows that Jacobi preconditioner works quite well but the GaussSeidel one not. Some investigation should be made to solve that problem.

### Types
- Matrix

Class that represents Matrices. They can be of any size. An instance of this class can be created from `vector<vector<double>>`, ` initializer_list ` and can also be read from files using the reader.

Operator +,-, *double, *Matrix, =,\[ \],() have been overloaded to allow pratical computation.
Operator << and >> have been overloaded to allow practical display and practical translation from string.

Some typical methods for matrices as `Transpose()`, ` Inverse() ` ... also have been implemented.

- Vector

Inherit from Matrix class. Represent vector type.

Some practical methods for vectors  as scalar product : ` dot()`, norm induced from scalar product : ` norm() `, ... also have been implemented.

### Reader and writer

A class reader is provided in order to create an instance of Matrix from a .txt file.

```c++
Matrix A = inputOutput::readFromText("A.txt");
```

A writer was also implemented if one want to output the results in a file instead of printing it in the terminal.

### Solver Factory

A solver factory is implemented to create the Solver that the user want. It takes as input the parameters that the user provides either in the _arguments_ or in the _cin_ and return a pointer to a Solver.

The resolution is then made taking use of the polymorphism of the class.

A templated function `stoClass` which translate string to object have also been implemented. It was practical for the solver factory.

### Example of linear systems

Example of linear systems can be found in the folder Examples.


## List of tests
The tests are implemented using Google Test Suite.

https://github.com/google/googletest

To run all the test, run the following command :

```bash
./Test
```

The google test API is downloaded during the build by CMake. If it does not work, please redo the cmake process.

### Matrix and Vector

- All constructors have been tested for the Matrix and Vector classes.

- Mutator and Accessor have been tested.

- The copy constructor was tested too.

- TODO : Tests for the differents operator : +,-,* and methods translate(), inverse(), dot(), norm().

### Solver

- All the solver have been tested on the base case provided in the Example Folder.

- TODO : Test the solvers in different cases.

### Solver Factory

- The template function `stoClass` have been tested in the case of `Vector()`, `double`, `size_t`. Which are used by the programm.

- Test for the solver factory, all solvers are tested.

## TODOs and perspectives

- Correct Gauss Seidel preconditioner.

- Add tests for all the cases that are not treated for now.

- Test the solver with more examples of linear systems.

- Add new preconditioners.

- Implement the preconditioners for more iterative solvers.

- Compute _omega_ for Richardson method using the power method to find the eigenvalues. Knowing that _omega_ = 2/(_lambda_\_min + _lambda_\_max)

- More control on the cin input of the solver factory.

- Add more organization in the tests.
