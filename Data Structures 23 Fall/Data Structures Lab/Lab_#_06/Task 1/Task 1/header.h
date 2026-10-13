//#pragma once
//
#include<iostream>
using namespace std;
//
//
//template<typename T>
//
//class Node 
//{
//public:
//
//    T data;
//    Node* next;
//
//   
//    Node()
//    {
//        data = 0;
//        next = nullptr;
//    
//    }
//
//    
//    Node(T val)
//    {
//        data = val;
//        next = NULL;
//    }
//
//
//   
//    int get_val() 
//    {
//        return data;
//    }
//
//   
//    Node* get_Next()
//    {
//        return next;
//    }
//
//    
//    void set_val(int val)
//    {
//        data = val;
//    }
//
//   
//    void set_Next(Node* node) 
//    {
//        next = node;
//    }
//};
//
//
//
//
//
//
//
//
//
//template<typename T>
//class SLinkedList 
//{
//public:
//    Node<T>* head;
//
//
//   
//    LinkedList()
//    {
//        head = nullptr;
//    }
//
//    
//    void insert_at_tail(int val)
//    {
//        Node* newNode = new Node(val);
//
//        if (head==NULL)
//        {
//            head = newNode;
//            return;
//        }
//       
//      
//
//            Node* temp = head;
//
//            while (temp->next!=NULL)
//           
//            {
//                temp = temp->next;
//            }
//            
//            temp->next = newNode;
//    
//
//    }
//
//
//  
//    void insert_at_Head(int val)
//    {
//        Node<T>* newNode = new Node(val);
//        newNode->set_Next(head);
//        head = newNode;
//    }
//
//    
//    bool isEmpty() 
//    {
//        return head == nullptr;
//    }
//
//   
//    bool search(int val)
//    {
//        Node<T>* temp = head;
//        while (temp!=NULL)
//        {
//            if (temp->get_val() == val)
//            {
//                return true;
//            }
//            temp = temp->get_Next();
//        }
//        return false;
//    }
//
//
//  
//    void update(int oldVal, int newVal) 
//    {
//        Node* current = head;
//        while (current) 
//        {
//            if (current->get_val() == oldVal) 
//            {
//                current->set_val(newVal);
//                return;
//            }
//            current = current->get_Next();
//        }
//    }
//
//  
//    void insertAtIndex(int val, int index)
//    {
//        if (index < 0) 
//        {
//            cout << "Invalid index" << endl;
//            return;
//        }
//
//        if (index == 0)
//        {
//            insert_at_Head(val);
//            return;
//        }
//
//        Node* newNode = new Node(val);
//        Node* current = head;
//        int count = 0;
//
//        while (current)
//        {
//            if (count == index - 1)
//            {
//                newNode->set_Next(current->get_Next());
//                current->set_Next(newNode);
//                return;
//            }
//            current = current->get_Next();
//            count++;
//        }
//
//        cout << "Index out of bounds" << endl;
//    }
//
//   
//    void deleteNode(int val) 
//    {
//        if (!head) 
//        {
//           cout << "List is empty" << endl;
//            return;
//        }
//
//        if (head->get_val() == val) 
//        {
//            Node* temp = head;
//            head = head->get_Next();
//            delete temp;
//            return;
//        }
//
//        Node* current = head;
//        while (current->get_Next()) 
//        {
//            if (current->get_Next()->get_val() == val) 
//            {
//                Node* temp = current->get_Next();
//                current->set_Next(temp->get_Next());
//                delete temp;
//                return;
//            }
//            current = current->get_Next();
//        }
//
//        cout << "Element not found" << endl;
//    }
//
//   
//    void print()
//    {
//        Node* current = head;
//        while (current) 
//        {
//           cout << current->get_val() << " ";
//            current = current->get_Next();
//        }
//       cout << endl;
//    }
//};
// 
//





template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node() : data(T()), next(nullptr) {}
    Node(T val) : data(val), next(nullptr) {}
};


template <typename T>
class SLinkedList
{
public:
    Node<T>* head;

public:
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
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtHead(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    bool isEmpty() {
        return head == nullptr;
    }

   T search(T val)
   {
        Node<T>* current = head;
        T count = 0;

        while (current!=NULL) {
            if (current->data == val) 
            {
                return count;
            }
            current = current->next;
            count++;
        }
        return false;
    }



    void update(T oldVal, T newVal) {
        Node<T>* current = head;
        while (current) {
            if (current->data == oldVal) {
                current->data = newVal;
                return;
            }
            current = current->next;
        }
    }

    void InsertAtIndex(T val, int index) {
        if (index < 0) 
        {
           cout << "Invalid index" << endl;
            return;
        }

        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        Node<T>* current = head;
        int count = 0;

        while (current) {
            if (count == index - 1) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
            count++;
        }

        std::cout << "Index out of bounds" << std::endl;
    }

    void remove(T val) {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            if (current->next->data == val) {
                Node<T>* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << "Element not found" << std::endl;
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~SLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};