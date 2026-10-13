#pragma once
#include<iostream>
using namespace std;
#include<string>
template<typename T>
class Node
{
	T data;
	Node<T>* next;
public:
	Node(int x = 0)
	{
		data = x;
		next = nullptr;
	}
	void setNext(Node<T>* n)
	{
		next = n;
	}
	Node<T>* getNext()
	{
		return next;
	}
	T getdata()
	{
		return data;
	}
};


template<typename T>
class Queue
{
	Node<T>* front;
	Node<T>* rear;
	int c_size;
public:
	Queue()
	{
		c_size = 0;
		front = nullptr;
		rear = nullptr;
	}
	bool isEmpty()
	{
		return(front == nullptr);
	}

	void enqueue(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (isEmpty())
		{
			c_size++;
			front = rear = newNode;
			return;
		}
		c_size++;
		rear->setNext(newNode);
		rear = newNode;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			return -1;
		}

		Node<T>* temp = front;
		front = front->getNext();

		T data = temp->getdata();
		c_size--;
		delete temp;
		return data;
	}

	void print()
	{
		Node<T>* current = front;
		while (current != nullptr)
		{
			cout << current->getdata() << " ";
			current = current->getNext();
		}
		cout << endl;
	}

	T Front()
	{
		if (front == nullptr)
		{
			rear = nullptr;
			return -1;
		}
		return front->getdata();
	}

	int size()
	{
		return c_size;
	}

	void clear()
	{
		Node<T>* current = front;
		while (current != nullptr)
		{
			dequeue();
			current = current->getNext();
		}
		front = rear = nullptr;
	}

	bool check(char* str, int start, int end)
	{
		if (start >= end)
			return true;

		if (str[start] != str[end])
			return false;

		return check(str, start + 1, end - 1);
	}

	bool isPalindrome(char* str)
	{
		int length = strlen(str);
		return check(str, 0, length - 1);
	}
};

class Process
{
public:

	int processID;
	int priority;
	int burst_time;
	Process* next;
	int state;
	Process* Nest_Terminated;
	Process(int x, int y, int z)
	{
		processID = x;
		priority = y;
		burst_time = z;
		next = nullptr;
		state = 2;
		Nest_Terminated = nullptr;
	}

	void setNext(Process* n)
	{
		next = n;
	}
	Process* getNext()
	{
		return next;
	}

};

class CustomQueue
{
	Process* front;
	Process* rear;
public:
	CustomQueue()
	{
		front = nullptr;
		rear = nullptr;
	}

	bool isEmpty()
	{
		return(front == nullptr);
	}

	void enqueue(Process* process)
	{
		if (isEmpty())
		{
			front = rear = process;
			return;
		}
		rear->setNext(process);
		rear = process;
	}

	Process* dequeue()
	{
		if (front == nullptr)
		{
			return nullptr;
		}
		Process* node = front;
		front = front->getNext();
		if (front == nullptr)
		{
			rear = nullptr;
		}
		return node;
	}

};


class MultiLevelFeedbackQueueScheduler
{
	CustomQueue low;
	CustomQueue med;
	CustomQueue high;

	Process* terminated_process;
	int count;
public:
	MultiLevelFeedbackQueueScheduler()
	{
		count = 0;
		terminated_process = nullptr;
	}
	void addProcess(Process* process)
	{
		if (process->priority == 0)
		{
			high.enqueue(process);
		}
		else if (process->priority == 1)
		{
			med.enqueue(process);
		}
		else
		{
			low.enqueue(process);
		}
	}

	void addTerminatedProcess(Process* process)
	{
		process->state = 4;
		if (terminated_process == nullptr)
		{
			terminated_process = process;
		}
		else
		{
			Process* temp = terminated_process;
			while (temp->Nest_Terminated != nullptr)
			{
				temp = temp->Nest_Terminated;
			}
			temp->Nest_Terminated = process;
		}
		count++;

	}

	int getTerminatedCount()
	{
		return count;
	}

	Process* getTerminatedProcess(int processID)
	{
		Process* temp = terminated_process;
		while (temp != nullptr)
		{
			if (temp->processID == processID)
			{
				return temp;
			}
			temp = temp->Nest_Terminated;
		}
		return nullptr;
	}


	void printTerminatedProcesses()
	{
		Process* temp = terminated_process;
		while (temp != nullptr)
		{
			cout << temp->processID << " " << temp->state << endl;
			temp = temp->Nest_Terminated;
		}
		cout << endl;
	}







};