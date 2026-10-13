#pragma once
using namespace std;


template<typename T>
class Node
{
	T data;
	Node<T>* next;
public:

	Node(int x=0)
	{
		data = x;
		next = nullptr;

	}
	void set_next(Node<T> *n)
	{
		next =n ;
	}
	void setData(T x)
	{
		data = x;
	}
	Node* getNext()
	{
		return this->next;
	}
	T getData()
	{
		return this->data;
	}
	
};

template<typename T>
class SLinkedList
{
	public:
	Node<T>* head;
	SLinkedList()
	{
		head = nullptr;
	}
	void insertAtHead(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			newNode->set_next(head);
			head = newNode;
		}
	}

	void insert(T data)
	{
		
		Node<T>* newNode = new Node<T>(data);

		if (head == nullptr)
		{
			
			head = newNode;
		}
		else
		{
			Node<T>* current = head;
			while (current->getNext() != nullptr)
			{
						current = current->getNext();
			}
			current->set_next(newNode);

		}
	}

	void print()
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			cout<< current->getData()<<"---> ";
			current=current->getNext();
		}
	}


	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}

	int search(T data)
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			if (current->getData() == data)
			{
				return current->getData();
			}
			current = current->getNext();
		}
		return -1;
	}


	void InsertAtIndex(T data, int index)
	{
		if (index <=0) 
		{
			return ;
		}

		if (index == 1) {
			insertAtHead(data);
			
		}

		Node<T>* current = head;
		int count = 1;
		while (count < index  && current != nullptr)
		{
			current = current->getNext();
			count++;
		}
		Node<T>* temp = new Node<T>(data);
		temp->set_next(current->getNext());
		current->set_next(temp);
	}

	void update(T value, T newValue)
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			if (current->getData() == value)
			{
				current->setData(newValue);
			}
			current = current->getNext();
		}
	}

	void remove(T value)
	{
		Node<T>* temp;
		while (head != nullptr)
		{
			if (head->getData() == value)
			{
				Node<T>* temp = head;
				head = head->getNext(); 
				delete temp; 
			}
		}
	}

};