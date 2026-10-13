#include"pch.h"
#include"../Task 2/header.h"


TEST(SwapAdjacentNodes, T1) {
    SLinkedList<int> obj;
    int arr[] = { 0, 3, 1, 2, 2, 0 };

    // Create the linked list from the given array.
    for (int i = 0; i < 6; i++) {
        obj.insert(arr[i]);
    }

    // Call the function to swap adjacent nodes.
    obj.head = swapAdjacentNodes(obj.head);

    // Verify the modified list.
    int expected[] = { 3, 0, 2, 1, 0, 2 };
    Node<int>* temp = obj.head;
    int i = 0;

    while (temp != nullptr) {
        EXPECT_EQ(expected[i], temp->data);
        temp = temp->next;
        i++;
    }
}

TEST(SwapAdjacentNodes, T2) {
    SLinkedList<int> obj;
    int arr[] = { 0, 1, 2, 3 };

    // Create the linked list from the given array.
    for (int i = 0; i < 4; i++) {
        obj.insert(arr[i]);
    }

    // Call the function to swap adjacent nodes.
    obj.head = swapAdjacentNodes(obj.head);

    // Verify the modified list.
    int expected[] = { 1, 0, 3, 2 };
    Node<int>* temp = obj.head;
    int i = 0;

    while (temp != nullptr) {
        EXPECT_EQ(expected[i], temp->data);
        temp = temp->next;
        i++;
    }
}
