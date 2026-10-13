#include<iostream>
#include "pch.h"
using namespace std;
//question 1
TEST(UnionSet, type_double) {
    double A[] = { 10.43, 4.3, 5.61, 6.9, 11.57, 12.11, 3.8, 2.4, 9.5 };
    double B[] = { 11.01, 12.34, 16.5, 3.8, 8.1, 2.4, 9.11, 12.11, 
        6.75, 10.43, 20.2, 2.1, 4.3 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    double unionResult[] = { 10.43,4.3,5.61,6.9,11.57,12.11,3.8,2.4,9.5,
        11.01,12.34,16.5,8.1,9.11,6.75,20.2,2.1 };  // Result array for union
    double* p = unionSets(A, 9, B, 13);
    for (int i = 0; i < 17; i++)
    {
        ASSERT_EQ(unionResult[i],p[i]);
    }

}

TEST(IntersectionSet, type_int) {
    int A[] = { 10, 4, 5, 6, 11, 12, 3, 2, 9 };
    int B[] = { 11, 12, 16, 3, 8, 2, 9, 12,
        6, 10, 20, 2, 4 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    int unionResult[] = { 10, 4, 6, 11, 12, 3, 2, 9 }; 
    int* p = intersectionSets(A, 9, B, 13);
    for (int i = 0; i < 8; i++)
    {
        ASSERT_EQ(unionResult[i], p[i]);
    }
}
TEST(DisjointSet, type_string) {
    std::string A[] = { "apple", "banana", "cherry", "date" };
    std::string B[] = { "fig", "grape", "honeydew", "kiwi" };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    bool result = areDisjoint(A, sizeA, B, sizeB);
    ASSERT_TRUE(result);  // Expecting true because A and B have no common elements
}
TEST(FindElement, type_int) {
    int A[] = { 10, 4, 5, 6, 11, 12, 3, 2, 9 };
    int B[] = { 11, 12, 16, 3, 8, 2, 9, 12,
        6, 10, 20, 2, 4 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    // Test if specific elements exist in array A
    ASSERT_TRUE(elementExists(A, sizeA, 11));  // Expecting true because 11 is in A
    ASSERT_TRUE(elementExists(A, sizeA, 4));   // Expecting true because 4 is in A
    ASSERT_FALSE(elementExists(A, sizeA, 15)); // Expecting false because 15 is not in A

    // Test if specific elements exist in array B
    ASSERT_TRUE(elementExists(B, sizeB, 20));  // Expecting true because 20 is in B
    ASSERT_FALSE(elementExists(B, sizeB, 7));  // Expecting false because 7 is not in B
}
//question 2
TEST(RemoveDuplicate, case1) {
    int A[] = { 21, 32, 22 , 33, 22 };
    int A1[] = { 21, 32, 22, 33 };
    string B[] = { "sara", "mary", "larry", "sara" };
    string B1[] = { "sara", "mary", "larry" };
    int* p = RemoveDups(A, 5);
    string* p1 = RemoveDups(B, 4);
    for (int i = 0; i < 4; i++)
    {
        ASSERT_EQ(A1[i], p[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(B1[i], p1[i]);
    }

}
////question 3

TEST(CalculatorTests, Addition) {
    // Test with integers
    Calculator<int> calcInt(5, 3);
    EXPECT_EQ(calcInt.add(), 8);

    // Test with double
    Calculator<double> calcDouble1(2.1, 7.4);
    EXPECT_EQ(calcDouble1.add(), 9.5);

    Calculator<double> calcDouble2(5.5, 3.2);
    EXPECT_EQ(calcDouble2.add(), 8.7);
}
TEST(CalculatorTests, Multiplication) {
    // Test with integers
    Calculator<int> calcInt(5, 3);
    EXPECT_EQ(calcInt.multiply(), 15);

    // Test with doubles
    Calculator<double> calcDouble1(5.5, 3.2);
    EXPECT_EQ(calcDouble1.multiply(), 17.6);

    Calculator<double> calcDouble2(0.0, 3.3);
    EXPECT_EQ(calcDouble2.multiply(), 0.0);
}
TEST(CalculatorTests, Subtraction) {
    // Test with integers
    Calculator<int> calcInt(5, 3);
    EXPECT_EQ(calcInt.subtract(), 2);

    Calculator<int> calcIntNegative(-2, 7);
    EXPECT_EQ(calcIntNegative.subtract(), -9);

    // Test with doubles
    Calculator<double> calcDouble(5.5, 3.2);
    EXPECT_EQ(calcDouble.subtract(), 2.3);
}

// Test cases for division
TEST(CalculatorTests, Division) {
    // Test with integers
    Calculator<int> calcInt(6, 3);
    EXPECT_EQ(calcInt.divide(), 2);

    // Test with doubles
    Calculator<double> calcDouble(6.6, 3.3);
    EXPECT_EQ(calcDouble.divide(), 2.0);

    // Test division by zero edge case for integer
    Calculator<int> calcIntZero(0, 1);
    EXPECT_EQ(calcIntZero.divide(), 0);

    // Optional: Test division by zero for non-zero denominator
    Calculator<int> calcZeroDivision(6, 0);
    EXPECT_EQ(calcZeroDivision.divide(), 0);  // Assuming divide() handles divide-by-zero as return 0 or custom error handling
}
TEST(CalculatorTests, Power) {
    // Test with integers
    Calculator<int> calcInt(2, 3);
    EXPECT_EQ(calcInt.power(), 8);

    Calculator<int> calcIntZeroExponent(5, 0);
    EXPECT_EQ(calcIntZeroExponent.power(), 1);

    Calculator<int> calcIntBaseZero(0, 5);
    EXPECT_EQ(calcIntBaseZero.power(), 0);

    // Test with doubles
    Calculator<double> calcDouble(2.0, 3.0);
    EXPECT_EQ(calcDouble.power(), 8.0);
}
TEST(CalculatorTests, Square) {
    // Test with integers
    Calculator<int> calcInt(5, 0);  // num2 is not used for square operation
    EXPECT_EQ(calcInt.square(), 25);

    Calculator<int> calcIntZero(0, 0);
    EXPECT_EQ(calcIntZero.square(), 0);

    // Test with doubles
    Calculator<double> calcDouble(5.5, 0);
    EXPECT_EQ(calcDouble.square(), 30.25);
}
//question 4
TEST(ContainerTest, InsertInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);

    EXPECT_TRUE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
    EXPECT_FALSE(intContainer.search(30));
}

TEST(ContainerTest, InsertFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14);
    floatContainer.insert(2.718);

    EXPECT_TRUE(floatContainer.search(3.14));
    EXPECT_TRUE(floatContainer.search(2.718));
    EXPECT_FALSE(floatContainer.search(1.0));
}

TEST(ContainerTest, InsertString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");

    EXPECT_TRUE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
    EXPECT_FALSE(stringContainer.search("Goodbye"));
}

TEST(ContainerTest, RemoveInt) {
    Container<int> intContainer(5);
    intContainer.insert(10);
    intContainer.insert(20);
    intContainer.remove(10);

    EXPECT_FALSE(intContainer.search(10));
    EXPECT_TRUE(intContainer.search(20));
}

TEST(ContainerTest, RemoveFloat) {
    Container<float> floatContainer(5);
    floatContainer.insert(3.14);
    floatContainer.insert(2.718);
    floatContainer.remove(2.718);

    EXPECT_TRUE(floatContainer.search(3.14));
    EXPECT_FALSE(floatContainer.search(2.718));
}

TEST(ContainerTest, RemoveString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");
    stringContainer.remove("Hello");

    EXPECT_FALSE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
}


