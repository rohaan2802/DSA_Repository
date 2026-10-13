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
	DoublyNode(int x=0)
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
		while (current->getNext()!=nullptr)
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

	void update(int data,int val)
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
		while (current !=nullptr && count<index)
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
	Node(int x=0, Node* nxt = nullptr)
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
			cout << temp->getData()<<" ";
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
		return(head==nullptr);
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

	void update(int data,int val)
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

		while (current != head )
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




/*class Double_list
{
	int data;
	Double_list* next;
	Double_list* previous;
public:
	Double_list(int x=0)
	{
		data = x;
		next = nullptr;
		previous = nullptr;
	}

	void insert_at_end(int data, Double_list* head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			return;
		}
		Double_list* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->previous = current;
	}

	void insert_at_beg(int data, Double_list* &head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			return;
		}
		new_node->next = head;
		head->previous = new_node;
		head = new_node;
	}
	
	void insert_at_index(int data, Double_list* &head,int pos)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			return;
		}
		Double_list* current = head;
		int count = 1;
		while (count<pos)
		{
			current = current->next;
			count++;
		}
		new_node->next = current->next;
		new_node->previous = current;
		current->next = new_node;
		current->next->previous = new_node;
	}
	
	void insert_at_match(int data, Double_list* &head,int val)
	{
		//Double_list* new_node = new Double_list(data);

		
		Double_list* current = head;
		while (current->data!=data)
		{
			current = current->next;
			
		}
		current->data = val;
	}



	void print(Double_list* head)
	{
		Double_list* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void del_at_begin(Double_list* &head)
	{
		if (head == nullptr)
		{
			return;
		}
		Double_list* current = head;

		head=head->next;
		delete current;
	}
	
	void del_at_end(Double_list* head)
	{
		if (head == nullptr)
		{
			return;
		}
		Double_list* current = head;

		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}	
	
	void del_at_index(Double_list* head,int pos)
	{
		if (head == nullptr)
		{
			return;
		}
		Double_list* current = head;
		int count = 1;
		while (count<pos)
		{
			current = current->next;
			count++;
		}
		
		current->next = current->next->next;
		current->next->previous = current;

	}

	void del_at_match(Double_list* head,int val)
	{
		if (head == nullptr)
		{
			return;
		}
		Double_list* current = head;
		while (current->data!=val)
		{
			current = current->next;
		}
		
		current->previous->next=current->next;
		current->next->previous=current->previous;
		delete current;

	}

	

};*/



/*class Double_list
{
	int data;
	Double_list* next;
public:
	Double_list(int x=0)
	{
		data = x;
		next = nullptr;
	}

	void insert_at_end(int data, Double_list* &head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			new_node->next = new_node;
			return;
		}
		Double_list* current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->next = head;

	}

	void print(Double_list* head)
	{
		Double_list* current = head;
		do {
			cout << current->data << " ";
			current = current->next;
		} while (current != head);

		cout << endl;
	}

	void insert_at_beg(int data, Double_list* &head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			new_node->next = new_node;
			return;
		}
		Double_list* current = head;
		while (current->next != head) 
		{
			current = current->next;
		}
		new_node->next = head;
		current->next = new_node;
		head = new_node;
	}
	
	void insert_at_index(int data, Double_list* &head,int pos)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			new_node->next = new_node;
			return;
		}
		Double_list* current = head;
		int count = 1;
		while (count<pos)
		{
			current = current->next;
			count++;
		}
		new_node->next = current->next;
		current->next = new_node;


	}
	
	void insert_at_match(int data, Double_list*& head, int val)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			head = new_node;
			new_node->next = new_node;
			return;
		}
		Double_list* current = head;
		while (current->data!=data)
		{
			current = current->next;
		}
		current->data = val;
		
		
	}

	

	

	void del_at_begin(Double_list* &head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{
			
			return;
		}
		Double_list* current = head;
		Double_list* temp = head;
		while (current->next != head)
		{
			current = current->next;
		}
		head = head->next;
		current->next = head;
		delete temp;

		
	}
	
	void del_at_end(Double_list* &head)
	{
		Double_list* new_node = new Double_list(data);

		if (head == nullptr)
		{

			return;
		}
		Double_list* current = head;
		while (current->next->next != head)
		{
			current = current->next;
		}
		Double_list* temp = current->next;
		current->next = head;
		delete temp;
		
	}	
	
	void del_at_index(Double_list* &head,int pos)
	{
		Double_list* current = head;

		if (pos == 0)
		{
			Double_list* temp = head;
			while (current->next != head)
			{
				current = current->next;
			}
			head = head->next;
			current->next = head;
			delete temp;
			return;
		}
		int count = 1;
		while (count < pos)
		{
			current = current->next;
			count++;
		}
		Double_list* temp1 = current->next;
		current->next = current->next->next;
		delete temp1;

	}
	
	void del_at_match(Double_list* head,int val)
	{
		Double_list* current = head;
		
		
		while (current->next->data!=val)
		{
			current = current->next;
		}
		Double_list* temp1 = current->next;
		current->next = current->next->next;
		delete temp1;
	}

	

};
*/

/*#include<iostream>
using namespace std;


class Stack
{
	int data;
	Stack* next;
public:
	Stack(int x=0)
	{
		data = x;
		next = nullptr;
	}
	bool isEmpty(Stack* head)
	{
		return(head == nullptr);
	}
	
	void push(Stack* &head,int x)
	{
		Stack* new_node = new Stack(x);
		new_node->next = head;
		head = new_node;

	}
	void pop(Stack* &head)
	{
		if (isEmpty(head)) 
		{
			cout << "\nStack Underflow" << endl;
		}
		else
		{
			
			Stack* temp = head;

			head = head->next;

			delete temp;
		}
		
	}
	int peek(Stack* head)
	{

		if (!isEmpty(head))
			return head->data;
		else 
		{
			cout << "\nStack is empty";
			return 0;
		}
	}
};



int main()
{
	Stack *head=nullptr;
	head->push(head,1);
	head->push(head,2);
	head->push(head,3);
	head->push(head,4);
	head->push(head,5);
	while (!head->isEmpty(head))
	{

		cout<<head->peek(head)<<" ";
		head->pop(head);

	}
}*/

/*#include<iostream>
using namespace std;


class Stack
{
	int data;
	Stack* next;
public:
	Stack(int x=0)
	{
		data = x;
		next = nullptr;
	}
	bool isEmpty(Stack* head)
	{
		return(head == nullptr);
	}
	
	void push(Stack* &head,int x)
	{
		Stack* new_node = new Stack(x);
		new_node->next = head;
		head = new_node;

	}
	void pop(Stack* &head)
	{
		if (isEmpty(head)) 
		{
			cout << "\nStack Underflow" << endl;
		}
		else
		{
			
			Stack* temp = head;

			head = head->next;

			delete temp;
		}
		
	}
	int peek(Stack* head)
	{

		if (!isEmpty(head))
			return head->data;
		else 
		{
			cout << "\nStack is empty";
			return 0;
		}
	}
};



int main()
{
	Stack *head=nullptr;
	head->push(head,1);
	head->push(head,2);
	head->push(head,3);
	head->push(head,4);
	head->push(head,5);
	while (!head->isEmpty(head))
	{

		cout<<head->peek(head)<<" ";
		head->pop(head);

	}
}*/

/*#include<iostream>
using namespace std;


class Queue
{
	int front, rear, capacity;
	int* queue;
public:
	Queue(int x)
	{
		front = 0;
		rear = -1;
		capacity = x;
		queue = new int[x];
	}

	bool isEmpty()
	{
		return(rear == -1);
	}
	bool isFull()
	{
		return (rear == capacity-1);
	}
	void Enqueue(int data)
	{
		if (isFull()) 
		{
			cout << "Queue Overflow\n";
			return;
		}
	
		queue[++rear] = data;
	}
	void dequeue() 
	{
		if (isEmpty()) 
		{
			cout << "Queue Underflow\n";
			return;
		}

		rear--;
		front = capacity-1 - rear;
	}

	int peek()
	{
		if (isEmpty()) 
		{
			cout << "Queue is Empty\n";
			return -1;
		}
		return queue[front];
	}



};	



int main()
{
	Queue q(5);

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
//	q.Enqueue(6);

	while (!q.isEmpty())
	{
		cout << q.peek() << " ";
		q.dequeue();
	}
}*/