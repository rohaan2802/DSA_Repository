#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
//***************** Q1 Test cases *****************

TEST(StackTest, PushPop) {
    Stack stack1;
    stack1.push(42);
    stack1.push(43);
    stack1.push(44);
    stack1.print();
    EXPECT_EQ(stack1.peek(), 44);
    stack1.pop();
    EXPECT_FALSE(stack1.isEmpty());
    stack1.pop();
    stack1.pop();
    stack1.print();
    EXPECT_TRUE(stack1.isEmpty());
}

TEST(StackTest, Clear) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.clear();
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, EmptyStack) {
    Stack stack2;
    EXPECT_TRUE(stack2.isEmpty());
    EXPECT_EQ(stack2.pop(), 0);
    EXPECT_EQ(stack2.peek(), 0);
}
//***************** Q2 Test cases *****************

TEST(IsValidTest, ValidBrackets) {
    std::string input = "(){}[]";
    EXPECT_TRUE(isValid(input));  
}
TEST(IsValidTest, InvalidBrackets_Order) {
    std::string input = "({[)]}";
    EXPECT_FALSE(isValid(input));  
}
TEST(IsValidTest, SingleUnmatchedOpeningBracket) {
    std::string input = "(";
    EXPECT_FALSE(isValid(input));  
}
TEST(IsValidTest, SingleUnmatchedClosingBracket) {
    std::string input = ")";
    EXPECT_FALSE(isValid(input));  
}
TEST(IsValidTest, NestedValidBrackets) {
    std::string input = "{[()]}";
    EXPECT_TRUE(isValid(input));  
}
TEST(IsValidTest, EmptyString) {
    std::string input = "";
    EXPECT_TRUE(isValid(input));  
}
TEST(IsValidTest, ComplexValidBrackets) {
    std::string input = "(({{[[]]}}))";
    EXPECT_TRUE(isValid(input));  
}
TEST(IsValidTest, NonBracketCharacters) {
    std::string input = "(a + b) * {x - y} + [z]";
    EXPECT_TRUE(isValid(input)); 
}
TEST(IsValidTest, UnmatchedBrackets) {
    std::string input = "[{]";
    EXPECT_FALSE(isValid(input)); 
}
//***************** Q3 Test cases *****************
TEST(QueueTest, Queue_using_stack) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    EXPECT_EQ(queue.front(), 10);
    queue.dequeue();
    EXPECT_EQ(queue.front(), 20);
    queue.enqueue(40);
    EXPECT_EQ(queue.front(), 20);
    queue.dequeue();
    queue.dequeue();
    EXPECT_EQ(queue.front(), 40);
}