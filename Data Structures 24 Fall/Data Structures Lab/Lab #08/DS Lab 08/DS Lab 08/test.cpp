#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
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
// question 2
TEST(MultiLevelFeedbackQueueSchedulerTest, BasicSchedulingTest) {
    MultiLevelFeedbackQueueScheduler scheduler;

    // Add processes to the scheduler
    scheduler.addProcess(new Process(1, 0, 5));  // High-priority process
    scheduler.addProcess( new Process(2, 1, 3));  // Medium-priority process
    scheduler.addProcess( new Process(3, 2, 2));  // Low-priority process
    scheduler.addProcess( new Process(4, 0, 4));  // High-priority process
    scheduler.addProcess( new Process(5, 1, 1));  // Medium-priority process
    scheduler.addProcess( new Process(6, 2, 6));  // Low-priority process

    // Execute processes using FCFS scheduling
    scheduler.executeProcesses();

    // Output the terminated processes
    scheduler.printTerminatedProcesses();

    // Check if all processes have terminated
    EXPECT_EQ(scheduler.getTerminatedCount(), 6);  // Assuming all processes should terminate

    // Check if specific process states are correct
    Process* terminatedProcess1 = scheduler.getTerminatedProcess(1);
    EXPECT_EQ(terminatedProcess1->state, 4); // State 4 indicates termination

    Process* terminatedProcess2 = scheduler.getTerminatedProcess(2);
    EXPECT_EQ(terminatedProcess2->state, 4);

    // Additional assertions as needed
    Process* terminatedProcess3 = scheduler.getTerminatedProcess(3);
    EXPECT_EQ(terminatedProcess3->state, 4);
}
