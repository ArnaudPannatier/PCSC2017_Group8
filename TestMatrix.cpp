//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//
#include <iostream>
#include "gtest/gtest.h"
#include "Matrix.h"
#include "Vector.h"

using namespace std;


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


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
