#include<iostream>
#include "pch.h"
#include "Header.h"
using namespace std;
// Question 1
TEST(Insert, T1) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4,5,6,7 };
    for (int i = 0; i < 8; i++)
    {

        obj.insert(arr[i]);
    }

    Node<int>* temp = obj.head;
    int i = 0;
    obj.print();
    while (temp->getNext() != NULL) {
        EXPECT_EQ(arr[i], temp->getData());
        temp = temp->getNext();
        i++;
    }

}

TEST(InsertatHead, T2) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4 };
    for (int i = 0; i < 5; i++)
    {
        obj.insert(arr[i]);
    }

    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[i]);
        temp = temp->getNext();
        i++;
    }
    temp = obj.head;
    obj.insertAtHead(66);
    EXPECT_EQ(66, obj.head->getData());
    temp = obj.head->getNext();
    int j = 0;
    obj.print();   //66,0,1,2,3,4 
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[j]);
        temp = temp->getNext();
        j++;
    }
}

TEST(InsertAtIndex, T3) {
    int arr[] = { 0, 1, 2, 3 };
    SLinkedList<int> obj1;
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr[i]);
    }

    obj1.InsertAtIndex(5, 4); // InsertAtIndex(5 is the value to be inserted, 4 is the Index.no);
    obj1.print();  //0, 1, 2, 3, 5
    Node<int>* temp = obj1.head;
    int j = 0;

    while (temp->getNext() != nullptr) {
        EXPECT_EQ(temp->getData(), arr[j]);
        temp = temp->getNext();
        j++;
    }
}

TEST(Search, T4) {

    SLinkedList<int> obj1;
    for (int i = 0; i < 3; i++)
    {
        obj1.insert(i);
    }
    obj1.print();
    EXPECT_EQ(2, obj1.search(2));
    ASSERT_NE(3, obj1.search(2));
}


TEST(Update, T5) {
    SLinkedList<int> obj;
    for (int i = 0; i < 5; i++)
    {

        obj.insert(i);
    }
    obj.update(3, 67);     //value to be updated=3, updated_value=67
    obj.print();   //0,1,2,67,4
    Node<int>* temp = obj.head;
    int i = 0;
    int arr[] = { 0,1,2,67,4 };
    while (temp->getNext() != NULL) {
        EXPECT_EQ(arr[i], temp->getData());
        temp = temp->getNext();
        i++;
    }

}
TEST(Delete, T6) {
    SLinkedList<int> obj;

    for (int i = 0; i < 5; i++)
    {
        obj.insert(i);
    }
    obj.remove(3);    //remove value=3
    int arr[] = { 0,1,2,4 };
    obj.print();    //0,1,2,4
    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[i]);
        temp = temp->getNext();
        i++;
    }
}
