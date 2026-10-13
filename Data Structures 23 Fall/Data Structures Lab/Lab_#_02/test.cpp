#include "pch.h"
#include "Header.h"


// Lab-2 Test Cases
/*  *********************Task-1 Test Cases*********************/
TEST(RemoveDupsTest, ExampleTest) {
    int arr[] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
    int newSize = 0;

    int* result = RemoveDups(arr, newSize);

    EXPECT_EQ(newSize, 6);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 5);
    EXPECT_EQ(result[5], 6);

    delete[] result;
}



TEST(RemoveDupsTest, StringsTest) {
    std::string arr[] = { "apple", "banana", "apple", "cherry", "banana" };
    int newSize = 0;

    std::string* result = RemoveDups(arr, newSize);

    EXPECT_EQ(newSize, 3);
    EXPECT_EQ(result[0], "apple");
    EXPECT_EQ(result[1], "banana");
    EXPECT_EQ(result[2], "cherry");

    delete[] result;
}

/*  *********************Task-2 Test Cases*********************/
TEST(RotateTest, IntArrayRotation) {
    int strs[] = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 2;
    Rotate(strs, k);

    int expected[] = { 3, 4, 5, 6, 7, 1, 2 };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}

TEST(RotateTest, StringArrayRotation) {
    std::string strs[] = { "apple", "banana", "cherry", "date" };
    int k = 2;
    Rotate(strs, k);

    std::string expected[] = { "cherry", "date", "apple", "banana" };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i) {
        ASSERT_EQ(strs[i], expected[i]);
    }
}
/*  *********************Task-3 Test Cases*********************/

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
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_TRUE(floatContainer.search(2.718f));
    EXPECT_FALSE(floatContainer.search(1.0f));
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
    floatContainer.insert(3.14f);
    floatContainer.insert(2.718f);
    floatContainer.remove(2.718f);

    EXPECT_TRUE(floatContainer.search(3.14f));
    EXPECT_FALSE(floatContainer.search(2.718f));
}

TEST(ContainerTest, RemoveString) {
    Container<std::string> stringContainer(5);
    stringContainer.insert("Hello");
    stringContainer.insert("World");
    stringContainer.remove("Hello");

    EXPECT_FALSE(stringContainer.search("Hello"));
    EXPECT_TRUE(stringContainer.search("World"));
}

/*  *********************Task-4 Test Cases*********************/


TEST(FindIndicesTest, ExampleTest) {
    int student_scores[] = { 10, 7, 0, 7 };
    int target_score = 14;

    int* result = findIndicesWithTargetSum(student_scores, target_score);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 3);

    delete[] result;
}

TEST(FindIndicesTest, NoSolutionTest) {
    int student_scores[] = { 10, 7, 0, 7 };
    int target_score = 100;

    int* result = findIndicesWithTargetSum(student_scores, target_score);

    EXPECT_EQ(result, nullptr);
}



