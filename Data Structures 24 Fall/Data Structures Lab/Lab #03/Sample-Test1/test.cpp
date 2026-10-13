#include<iostream>
#include "pch.h"
#include "Header.h"
using namespace std;

// Question 1:
TEST(CalculateEuclideanNormTest, BasicTest) {
    int array[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    double expectedNorm = std::sqrt(1 * 1 + 2 * 2 + 3 * 3 + 4 * 4 + 5 * 5 + 6 * 6 + 7 * 7 + 8 * 8 + 9 * 9);
    EXPECT_NEAR(calculateEuclideanNorm(array), expectedNorm, 1e-9);
}
// Question 3: 
TEST(RotateMatrix, case1) {
    const int rows = 3;
    const int cols = 3;
    int matrix[3][3] = { {3, 4, 2}, {5, 6, 1}, {7, 8, 9} };
    int matrix1[3][3] = { {7, 5, 3}, {8, 6, 4}, {9, 1, 2} };
    rotateMatrix90DegreesClockwise<int, rows, cols>(matrix);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(matrix[i][j], matrix1[i][j]);
        }
    }
}
// Question 4: 
TEST(SpiralOrderTest, BasicTest) {
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int size;
    int* result = spiralOrder<int, rows, cols>(matrix, size);

    int expected[] = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
    delete[] result;
}