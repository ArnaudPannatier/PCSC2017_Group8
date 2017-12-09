cmake_minimum_required(VERSION 3.8)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)
add_executable(TestMatrix TestMatrix.cpp inputOutput.cpp Matrix.cpp Vector.cpp Solver.cpp IterativeSolvers.cpp LU.cpp Cholesky.cpp GaussSeidel.cpp ConjugateGradientDescent.cpp Jacobi.cpp Richardson.cpp)
add_executable(Test test.cpp inputOutput.cpp Matrix.cpp Vector.cpp Solver.cpp IterativeSolvers.cpp LU.cpp Cholesky.cpp GaussSeidel.cpp ConjugateGradientDescent.cpp Jacobi.cpp Richardson.cpp)
add_executable(TestJacobi TestJacobi.cpp  inputOutput.cpp Matrix.cpp Vector.cpp Solver.cpp IterativeSolvers.cpp LU.cpp Cholesky.cpp GaussSeidel.cpp ConjugateGradientDescent.cpp Jacobi.cpp Richardson.cpp)
add_executable(TestRichardson TestRicharson.cpp inputOutput.cpp Matrix.cpp Vector.cpp Solver.cpp IterativeSolvers.cpp LU.cpp Cholesky.cpp GaussSeidel.cpp ConjugateGradientDescent.cpp Jacobi.cpp Richardson.cpp)