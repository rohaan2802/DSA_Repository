#include "pch.h"
#include"../Task 2/header.h"


TEST(RotateTest, IntArrayRotation) {
    int strs[] = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 2;
    int size = sizeof(strs) / sizeof(int);
    Rotate(strs, k, size);

    int expected[] = { 3, 4, 5, 6, 7, 1, 2 };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}

TEST(RotateTest, StringArrayRotation) {
    std::string strs[] = { "apple", "banana", "cherry", "date" };
    int k = 2;
    int size = sizeof(strs) / sizeof(string);

    Rotate(strs, k, size);

    std::string expected[] = { "cherry", "date", "apple", "banana" };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}