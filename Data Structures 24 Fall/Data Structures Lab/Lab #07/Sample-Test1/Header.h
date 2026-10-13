#pragma once
#include<iostream>
using namespace std;


//***************** Q1 Implementation ********************


class DoublyNode
{
	int data;
	DoublyNode* previous;
	DoublyNode* next;
public:
	DoublyNode(int x = 0)
	{
		data = x;
		previous = nullptr;
		next = nullptr;
	}
	void setPrev(DoublyNode* prev)
	{
		previous = prev;
	}
	void setNext(DoublyNode* n)
	{
		next = n;
	}
	int getData()
	{
		return data;
	}
	void setData(int x)
	{
		data = x;
	}
	DoublyNode* getPrev()
	{
		return previous;
	}
	DoublyNode* getNext()
	{
		return next;
	}

};


class DoublyLinkedList
{
	DoublyNode* head;
public:

	DoublyLinkedList()
	{
		head = nullptr;
	}
	DoublyNode* getHead()
	{
		return head;
	}
	bool isEmpty()
	{
		return(head == nullptr);
	}
	void insert(int data)
	{
		DoublyNode* temp = new DoublyNode(data);
		if (head == nullptr)
		{
			head = temp;
			return;
		}
		DoublyNode* current = head;
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(temp);
		temp->setPrev(current);
	}
	void print()
	{
		DoublyNode* current = head;
		while (current != nullptr)
		{
			cout << current->getData() << " ";
			current = current->getNext();
		}
		cout << endl;
	}
	void insertToHead(int data)
	{
		DoublyNode* temp = new DoublyNode(data);
		if (head == nullptr)
		{
			head = temp;
		}
		else {
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}
	}
	//there is no need to implement an `isFull` function 
	// beacuse the size of linked list is not fixed

	bool search(int data)
	{
		DoublyNode* temp = head;
		while (temp != nullptr)
		{
			if (temp->getData() == data)
			{
				return true;
			}
			temp = temp->getNext();

		}
	}

	void update(int data, int val)
	{
		DoublyNode* temp = head;
		while (temp->getData() != data)
		{

			temp = temp->getNext();

		}
		temp->setData(val);
	}

	void insertAtIndex(int data, int index)
	{
		DoublyNode* current = head;
		DoublyNode* temp = new DoublyNode(data);
		if (index < 0)
		{
			return;
		}
		if (index == 1)
		{
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}
		int count = 1;
		while (current != nullptr && count < index)
		{

			current = current->getNext();
			count++;

		}
		temp->setNext(current->getNext());
		temp->setPrev(current);
		current->setNext(temp);

	}

	void deleteData(int data)
	{
		DoublyNode* cuurent = head;
		while (cuurent != nullptr && cuurent->getData() != data)
		{
			cuurent = cuurent->getNext();
		}
		cuurent->getPrev()->setNext(cuurent->getNext());
		cuurent->getNext()->setPrev(cuurent->getPrev());
		delete cuurent;
	}
};


//***************** Q2 Implementation ********************


class Node
{
	int data;
	Node* next;
public:
	Node(int x = 0, Node* nxt = nullptr)
	{
		data = x;
		next = nxt;
	}
	void setData(int x)
	{
		data = x;
	}
	void setNext(Node* n)
	{
		next = n;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}


};

class CircularLinkedList
{
	Node* head;
public:
	CircularLinkedList()
	{
		head = nullptr;
	}

	Node* getHead()
	{
		return head;
	}

	void print()
	{
		Node* temp = head;
		cout << head->getData() << " ";
		temp = temp->getNext();
		while (temp != head)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}

	void insert(int data)
	{
		Node* temp = new Node(data);
		if (head == nullptr)
		{
			head = temp;
			temp->setNext(temp);
			return;
		}
		Node* current = head;
		while (current->getNext() != head)
		{
			current = current->getNext();
		}
		current->setNext(temp);
		temp->setNext(head);
	}

	bool isEmpty()
	{
		return(head == nullptr);
	}

	bool search(int val)
	{


		if (head->getData() == val)
		{
			return true;
		}

		Node* temp = head->getNext();

		while (temp != head)
		{
			if (temp->getData() == val)
			{
				return true;
			}
			temp = temp->getNext();

		}
		if (head->getData() == val)
		{
			return true;
		}
		return false;
	}

	void update(int data, int val)
	{
		Node* temp = head;
		while (temp->getData() != data)
		{

			temp = temp->getNext();

		}
		temp->setData(val);
	}

	void insertAtIndex(int data, int index)
	{
		Node* current = head;
		Node* temp = new Node(data);
		if (index < 0)
		{
			return;
		}
		if (index == 1)
		{
			temp->setNext(head);
			head = temp;
		}
		int count = 1;
		while (current != nullptr && count < index)
		{

			current = current->getNext();
			count++;

		}
		temp->setNext(current->getNext());
		current->setNext(temp);
	}

	void deleteData(int data)
	{
		Node* current = head->getNext();
		Node* temp = head;

		while (current != head)
		{
			if (current->getData() == data)
			{
				temp->setNext(current->getNext());
				delete current;
				return;
			}
			current = current->getNext();
		}

	}

};



