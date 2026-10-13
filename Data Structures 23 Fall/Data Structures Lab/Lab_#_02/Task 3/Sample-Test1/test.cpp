#include "pch.h"
#include"../Task 3/header.h"

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