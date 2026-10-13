#include "pch.h"
#include"../Project1/header.h"

TEST(RemoveDupsTest, ExampleTest) {
    int arr[] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
    int size = sizeof(arr) / sizeof(int);
    int newSize = 0;

    int* result = RemoveDups(arr, size, newSize);

    EXPECT_EQ(newSize, 6);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 5);
    EXPECT_EQ(result[5], 6);

    delete[] result;
}




/*TEST(RemoveDupsTest, StringsTest) {
    std::string arr[] = { "apple", "banana", "apple", "cherry", "banana" };
    int newSize = 0;
    int size = sizeof(arr) / sizeof(string);


    std::string* result = RemoveDups(arr, size, newSize);

    EXPECT_EQ(newSize, 3);
    EXPECT_EQ(result[0], "apple");
    EXPECT_EQ(result[1], "banana");
    EXPECT_EQ(result[2], "cherry");

    delete[] result;
}*/