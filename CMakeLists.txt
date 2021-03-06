cmake_minimum_required(VERSION 3.8)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The next lines represent a list of all the executables

add_subdirectory(Types)
add_subdirectory(Solvers)
add_subdirectory(Helpers)


add_executable(Main Executables/Main.cpp)

target_link_libraries(Main Solvers)
target_link_libraries(Main Types)
target_link_libraries(Main Helpers)


add_executable(Test Executables/TestMatrix.cpp)
add_executable(Temp Executables/test.cpp)

target_link_libraries(Test Types)
target_link_libraries(Test Solvers)
target_link_libraries(Test Helpers)

target_link_libraries(Temp Types)
target_link_libraries(Temp Solvers)
target_link_libraries(Temp Helpers)


#TODO : IF GOOGLE TEST IS NEEDED MODIFIY THE LINES AT THE END OF FILES TOO.

# The next lines are required to get the google test suite
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed.
## TODO : CHANGE FOR ALL EXECUTABLES
target_link_libraries(Test gtest_main)
add_test(NAME example_test COMMAND Test)
