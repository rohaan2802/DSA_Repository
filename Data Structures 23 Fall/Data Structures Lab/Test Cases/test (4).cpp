#include "pch.h"
#include "Header.h"

/*  *********************Task-1 Test Cases*********************/
TEST(DotProductTest, IntDotProduct) {
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };

    int result = DotProduct<int, 3>(arr1, arr2);

    EXPECT_EQ(result, 1 * 4 + 2 * 5 + 3 * 6);
}

TEST(DotProductTest, FloatDotProduct) {
    float arr1[] = { 1.5f, 2.5f, 3.5f };
    float arr2[] = { 4.5f, 5.5f, 6.5f };

    float result = DotProduct<float, 3>(arr1, arr2);

    EXPECT_FLOAT_EQ(result, 1.5f * 4.5f + 2.5f * 5.5f + 3.5f * 6.5f);
}

/*  *********************Task-2 Test Cases*********************/
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
/*  *********************Task-3 Test Cases*********************/

TEST(SpiralOrderTraversalTest, IntMatrixTest) {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int result[9];
    spiralOrderTraversal<int, 3, 3>(matrix,result);

    int expected[9] = {1, 2, 3, 6, 9, 8, 7, 4, 5};

    for (size_t i = 0; i < 9; ++i) {
            ASSERT_EQ(result[i], expected[i]);
    }
    //EXPECT_TRUE(ArraysEqual(expected, result));
    
}

TEST(SpiralOrderTraversalTest, CharMatrixTest) {
    char matrix[4][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };
    char result[16];
    spiralOrderTraversal<char, 4, 4>(matrix,result);

    char expected[16] = {'a', 'b', 'c', 'd', 'h', 'l', 'p', 'o','n', 'm', 'i', 'e','f', 'g', 'k', 'j'};

    for (size_t i = 0; i < 16; ++i) {
            ASSERT_EQ(result[i], expected[i]);
    }
   // EXPECT_TRUE(ArraysEqual(expected, result));

    
}

/*  *********************Task-4 Test Cases*********************/


TEST(OnlineBankTest, ConstructorTest) {
    OnlineBank<int> bank(1000, 3);

    ASSERT_EQ(bank.isWithdrawal(), true);
    ASSERT_EQ(bank.isDeposit(), true);
}

TEST(OnlineBankTest, MakeDepositTest) {
    OnlineBank<int> bank(1000, 3);

    bank.makeDeposit(500);

    ASSERT_EQ(bank.isDeposit(), true);
    ASSERT_EQ(bank.isWithdrawal(), true);
    ASSERT_EQ(bank.getCurrentBalance(), 1500);
}

TEST(OnlineBankTest, MakeWithdrawalTest) {
    OnlineBank<int> bank(1000, 3);

    bank.makeWithdrawal(200);

    ASSERT_EQ(bank.isDeposit(), true);
    ASSERT_EQ(bank.isWithdrawal(), true);
    ASSERT_EQ(bank.getCurrentBalance(), 800);
}

TEST(OnlineBankTest, MakeExcessiveWithdrawalTest) {
    OnlineBank<int> bank(1000, 3);

    bool withdrawalResult = bank.makeWithdrawal(1200);

    ASSERT_EQ(withdrawalResult, false);
    ASSERT_EQ(bank.isDeposit(), true);
    ASSERT_EQ(bank.isWithdrawal(), true);
    ASSERT_EQ(bank.getCurrentBalance(), 1000);
}

TEST(OnlineBankTest, MakeExcessiveDepositTest) {
    OnlineBank<int> bank(1000, 3);

    bank.makeDeposit(2000);

    ASSERT_EQ(bank.isDeposit(), true);
    ASSERT_EQ(bank.isWithdrawal(), true);
    ASSERT_EQ(bank.getCurrentBalance(), 3000);
}
