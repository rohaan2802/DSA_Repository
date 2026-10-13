#include<iostream>
#include "pch.h"
#include "Header.h"
using namespace std;
// // ****** TASK-1 ******
TEST(QueueTest, EnqueueAndDequeue) {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(9);
    q.print();
    EXPECT_EQ(q.dequeue(), 5);
    EXPECT_EQ(q.dequeue(), 3);
    EXPECT_EQ(q.dequeue(), 7);
    EXPECT_EQ(q.dequeue(), 4);
    EXPECT_EQ(q.dequeue(), 9);
}

TEST(QueueTest, Front) {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);
    std::cout << "After enquening element:" << std::endl;
    q.print();
    EXPECT_EQ(q.Front(), 5);

    q.dequeue();
    EXPECT_EQ(q.Front(), 3);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    EXPECT_EQ(q.Front(), -1); // Queue is empty, expect -1
}
TEST(PalindromeTest, BasicPalindromeTest) {
    Queue<char> q;
    EXPECT_TRUE(q.isPalindrome("madam"));   // Palindrome case
    EXPECT_TRUE(q.isPalindrome("racecar")); // Palindrome case
    EXPECT_FALSE(q.isPalindrome("hello"));  // Non-palindrome case
    EXPECT_FALSE(q.isPalindrome("ab"));     // Two different characters
}
