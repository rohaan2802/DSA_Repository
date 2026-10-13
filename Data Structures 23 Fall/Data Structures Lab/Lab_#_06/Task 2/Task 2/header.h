#pragma once
#include<iostream>
using namespace std;



template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node()
    {
        data = T;
        next = nullptr;
    }


    Node(T val)
    {
        data = val;
    next = nullptr;
    }
};



template <typename T>
class SLinkedList
{
public:
    Node<T>* head;

    SLinkedList() : head(nullptr) {}

    void insert(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (!head) {
            head = newNode; 
        }

        else
        {
            Node<T>* current = head;
            while (current->next)                                    // 0 -> 3 -> 1 -> 2 -> 2 -> 0
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

template <typename T>
Node<T>* swapAdjacentNodes(Node<T>* head) 
{
    if (!head || !head->next) 
    {                                   
        return head;
    }
     
    Node<T>* newHead = head->next;
    Node<T>* prev = nullptr;                                             // for first time    ===>   3 -> 0 -> 1 -> 2 -> 2 -> 0
                                                                         //  for Second Time   ===>   3 -> 0 -> 2 -> 1 -> 2-> 0
                                                                         //  for Second Time   ===>   3 -> 0 -> 2 -> 1 -> 0-> 2
    Node<T>* current = head;

    while (current && current->next)
    {                                                     
        Node<T>* nextNode = current->next;
        current->next = nextNode->next;
        nextNode->next = current;

        if (prev)
        {
            prev->next = nextNode;
        }

        prev = current;
        current = current->next;
    }

    return newHead;
}
