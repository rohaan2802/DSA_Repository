#include "pch.h"
#include"../Task 1/header.h"
using namespace std;

TEST(RemoveDupsTest, ExampleTest) {
    int arr[] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
    int newSize = 0;

     RemoveDups(arr, newSize);

    EXPECT_EQ(newSize, 6);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
    EXPECT_EQ(arr[5], 6);

  //  delete[] result;
}




TEST(RemoveDupsTest, StringsTest) {
    std::string arr[] = { "apple", "banana", "apple", "cherry", "banana" };
    int newSize = 0;

    RemoveDups(arr, newSize);

    EXPECT_EQ(newSize, 3);
    EXPECT_EQ(arr[0], "apple");
    EXPECT_EQ(arr[1], "banana");
    EXPECT_EQ(arr[2], "cherry");

  //  delete[] result;
}