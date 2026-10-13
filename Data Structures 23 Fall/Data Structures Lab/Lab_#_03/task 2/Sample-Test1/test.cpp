#include "pch.h"
#include"../ask 2/header.h"

TEST(NthModifiedFibonacciTest, IntTest) {
    int result = findNthModifiedFibonacci<int>(6);
    EXPECT_EQ(result, 13);
}

TEST(NthModifiedFibonacciTest, FloatTest) {
    float result = findNthModifiedFibonacci<float>(5);
    EXPECT_FLOAT_EQ(result, 7.0f);
}

TEST(NthModifiedFibonacciTest, DoubleTest) {
    double result = findNthModifiedFibonacci<double>(4);
    EXPECT_DOUBLE_EQ(result, 4.0);
}