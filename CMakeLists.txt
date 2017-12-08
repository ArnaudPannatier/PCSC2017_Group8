cmake_minimum_required(VERSION 3.8)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)
add_executable(TestMatrix TestMatrix.cpp Matrix.cpp Vector.cpp Cholesky.cpp Jacobi.cpp)
add_executable(Test test.cpp)
add_executable(Test2 test.cpp Matrix.cpp LU.cpp iterativeSolvers.cpp)
add_executable(TestJacobi TestJacobi.cpp Matrix.cpp Vector.cpp Jacobi.cpp)
add_executable(TestRichardson TestRicharson.cpp Richardson.cpp Matrix.cpp Vector.cpp)