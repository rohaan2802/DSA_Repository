#include "pch.h"
#include"../TASK 02/header.h"



TEST(SafeArrayTest, WithinBounds) {
    safeArray list(2, 13);
    safeArray yourList(-5, 9);

    list[2] = 10;
    EXPECT_EQ(list[2], 10);

    yourList[-5] = 20;
    EXPECT_EQ(yourList[-5], 20);
}

TEST(SafeArrayTest, OutOfBounds) {
    safeArray list(2, 13);

    // Use ASSERT_THROW to check if out-of-bounds access throws an exception
    ASSERT_THROW({
        std::cout << list[1] << std::endl;
        }, std::out_of_range);
}
