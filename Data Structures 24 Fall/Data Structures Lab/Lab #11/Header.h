#pragma once
#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class BST
{
    Node* root;
public:
    BST()
    {
        root = nullptr;
    }

    void Helper_fun1(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }
        Helper_fun1(current->left);
        cout << current->data << " ";
        Helper_fun1(current->right);
    }

    void Helper_fun2(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }
        Helper_fun2(current->left);
        Helper_fun2(current->right);
        cout << current->data << " ";

    }

    void Helper_fun3(Node* current)
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->data << " ";
        Helper_fun3(current->left);
        Helper_fun3(current->right);
    }


    void insert(int insertItem)
    {
        Node* new_node = new Node(insertItem);

        if (root == nullptr)
        {
            root = new_node;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (insertItem < current->data)
            {
                current = current->left;
            }
            else if (insertItem > current->data)
            {
                current = current->right;
            }
            else if (insertItem == current->data)
            {

                delete new_node;
                return;
            }
        }

        if (insertItem < parent->data)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }

    }

    bool search(int serachItem)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == serachItem)
        {
            return true;
        }

        Node* current = root;

        while (current != nullptr)
        {
            if (serachItem < current->data)
            {
                current = current->left;
            }
            else if (serachItem > current->data)
            {
                current = current->right;
            }
            else if (serachItem == current->data)
            {
                return true;
            }
        }

        return false;
    }


    void preorderTraversal()
    {

        Helper_fun3(root);
        cout << "\n";

    }

    void postorderTraversal()
    {

        Helper_fun2(root);
        cout << "\n";
    }


    void inorderTraversal()
    {

        Helper_fun1(root);
        cout << "\n";
    }


    void remove(int removeItem) 
    {
        if (root == nullptr)
        {
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr && current->data != removeItem) 
        {
            parent = current;
            if (removeItem < current->data) 
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

       

        if (current->left == nullptr || current->right == nullptr) 
        {
            Node* child = (current->left != nullptr) ? current->left : current->right;

            if (parent->left == current)
            {
                parent->left = child;
            }
            else 
            {
                parent->right = child;
            }

            delete current;
        }
        else 
        {
           
            Node* successor = current->right;
            Node* successor_parent = current;

            while (successor->left != nullptr)
            {
                successor_parent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (successor_parent->left == successor) 
            {
                successor_parent->left = successor->right;
            }
            else 
            {
                successor_parent->right = successor->right;
            }

            delete successor;
        }
    }


   
    int helper_count(Node* current)
    {
        if (current == nullptr)
        {
            return 0;
        }
        if (current->left == nullptr && current->right == nullptr)
        {
            return 1;
        }
        return helper_count(current->left) + helper_count(current->right);
    }

    int countLeafNodes()
    {
        return helper_count(root);
    }



    Node* subtree_search(int value)
    {
        Node* current = root;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return nullptr;
    }

    Node* fun1(int x, int y)
    {
        Node* current = root;

        while (current != nullptr)
        {
            if (x < current->data && y < current->data)
            {
                current = current->left;
            }
            else if (x > current->data && y > current->data)
            {
                current = current->right;
            }
            else
            {
                return current;
            }
        }
        return nullptr;
    }
};



int main()
{
    //BST bst; // Q# 02

    //bst.insert(4);
    //bst.insert(2);
    //bst.insert(7);
    //bst.insert(1);
    //bst.insert(3);
    //Node* n1 = bst.subtree_search(2);
   
    //if(n1!=nullptr)
    //{
    //    cout << n1->data << endl;
    //}
    //else
    //{
    //    cout << "Null ptr";
    //}

    //    if (n1->left !=nullptr)
    //    {
    //        cout << n1->left->data << endl;
    //    }
    //    else
    //    {
    //        cout << "Null ptr";
    //    }

    //    if (n1->right != nullptr)
    //    {
    //        cout << n1->right->data << endl;
    //    }
    //    else
    //    {
    //        cout << "Null ptr";
    //    }
       

    BST bst;
    bst.insert(6);   // Q# 03
    bst.insert(2);
    bst.insert(8);
    bst.insert(0);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);
    bst.insert(3);
    bst.insert(5);
    int p = 2;
    int q = 4;

   


    Node* lca = bst.fun1( p, q);


        cout <<  lca->data << endl;
   

    return 0;

}