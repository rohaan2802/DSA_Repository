#pragma once
#include<iostream>
using namespace std;


class Node
{
public:
	Node* left;
	Node* right;
   
	int data;
	
	Node(int x=0)
	{
		data = x;
		left = right = nullptr;
	}
};

class queue_node 
{
public:
    Node* data;
    queue_node* next;

    queue_node(Node* val)
    {
        data = val;
        next = nullptr;
    }
};


class Queue 
{
private:
    queue_node* front;
    queue_node* rear;

public:
    Queue()
    {
        front = rear = nullptr;
    } 

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(Node* node) 
    {
        queue_node* new_node = new queue_node(node);
        if (rear == nullptr) 
        {
            front = rear = new_node;
        }
        else 
        {
            rear->next = new_node;
            rear = new_node;
        }
    }

    Node* dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        queue_node* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        Node* nodeData = temp->data;
        delete temp;
        return nodeData;
    }
};

class BinaryTree
{
	Node* root;
public:
	BinaryTree()
	{
		root = nullptr;
	}
    void insert(int data) 
    {
        Node* newNode = new Node(data);
        if (root == nullptr) 
        {
            root = newNode;
            return;
        }

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty()) 
        {
            Node* current = q.dequeue();

            if (current->left == nullptr) 
            {
                current->left = newNode;
                return;
            }
            else 
            {
                q.enqueue(current->left);
            }

            if (current->right == nullptr) 
            {
                current->right = newNode;
                return;
            }
            else 
            {
                q.enqueue(current->right);
            }
        }
    }

    void InoderTraversal(Node* treeNode)
    {
        if (treeNode == nullptr)
            return;
        InoderTraversal(treeNode->left);
        cout << treeNode->data << ' ';
        InoderTraversal(treeNode->right);
    }

    void PreorderTraversal(Node* treeNode)
    {
        if (treeNode == nullptr)
            return;
        cout << treeNode->data << ' ';
        PreorderTraversal(treeNode->left);
        PreorderTraversal(treeNode->right);
    }

    void PostoderTraversal(Node* treeNode)
    {
        if (treeNode == nullptr)
            return;
        PostoderTraversal(treeNode->left);
        PostoderTraversal(treeNode->right);
        cout << treeNode->data << ' ';
    }

    void Display()
    {
        cout << "Inorder Traversal: ";
        InoderTraversal(root);
        cout << "Preorder Traversal: ";
        PreorderTraversal(root);
        cout << "Postorder Traversal: ";
        PostoderTraversal(root);
    }

    
};

bool hasPathSum(Node* root, int target_sum)
{
    if (root == nullptr)
    {
        return false;
    }

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        Node* current = q.dequeue();

        if (current->left == nullptr && current->right == nullptr && current->data == target_sum)
        {
            return true;
        }

        if (current->left != nullptr)
        {
            q.enqueue(current->left);
            current->left->data += current->data;
        }


        if (current->right != nullptr)
        {
            q.enqueue(current->right);
            current->right->data += current->data;


        }

    }
    return false;
}