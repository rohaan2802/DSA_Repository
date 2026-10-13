#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL
{
    Node* root;
public:
    AVL()
    {
        root = nullptr;
    }

    int height(Node* node) 
    {
        if (node != nullptr)
        {
            return node->height;
        }
        else
        {
            return 0;
        }
    }

    int balanceFactor(Node* node) 
    {
        if (node != nullptr)
        {
            return height(node->left) - height(node->right);
        }
        else
        {
            return 0;
        }
    }

   Node* rotate_right(Node* y)
    {
        Node* x = y->left;
        Node* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
       
    }

   Node* rotate_left(Node* x) 
    {
        Node* y = x->right;
        Node* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
        
    }

    void rebalance(Node* node) 
    {
        int balance = balanceFactor(node);

        if (balance > 1 && balanceFactor(node->left) >= 0)
        {
            rotate_right(node);
        }

        if (balance > 1 && balanceFactor(node->left) < 0) 
        {
            rotate_left(node->left);
            rotate_right(node);
        }

        if (balance < -1 && balanceFactor(node->right) <= 0)
        {
            rotate_left(node);
        }

        if (balance < -1 && balanceFactor(node->right) > 0) 
        {
           rotate_right(node->right);
            rotate_left(node);
        }

        return; 
    }

    void insert(int data)
    {

        Node* new_node = new Node(data);

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

            if (data < current->data) 
            {
                current = current->left;
            }
            else if (data > current->data)
            {
                current = current->right;
            }
            else 
            {
                return ;
            }
        }

        if (data < parent->data)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }

      

        new_node->height = 1 + max(height(new_node->left), height(new_node->right));

        rebalance(new_node);
    }

    void problem2()
    {
        Node* node = root;
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            if (is_prime(current->data))
            {
            }
            else if (current->data % 2 == 0)
            {
                if (current->left != nullptr)
                {
                    Node* new_root = rotate_left(current);
                    if (current == root)  
                    {
                        root = new_root;
                    }
                }
            }
            else
            {
                if (current->right != nullptr)
                {
                    Node* new_root = rotate_right(current);
                    if (current == root)  
                    {
                        root = new_root;
                    }
                }
            }

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
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
            rebalance(successor_parent);

        }
    }

    int find_min()
    {
        Node* node = root;

        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node->data;
    }

    int find_max()
    {
        Node* node = root;
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node->data;
    }

    void inordertraversal(Node* node) 
    {
        if (node==nullptr)
        {
            return;
        }
        inordertraversal(node->left);
        cout << node->data << " ";
        inordertraversal(node->right);
    }

    void preordertraversal(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preordertraversal(node->left);
        preordertraversal(node->right);
    }

    void postordertraversal(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postordertraversal(node->left);
        postordertraversal(node->right);
        cout << node->data << " ";
    }

    void inorder() 
    {
        inordertraversal(root);
        cout << endl;
    }

    void preorder()
    {
        preordertraversal(root);
        cout << endl;
    }

    void postorder()
    {
        postordertraversal(root);
        cout << endl;
    }

    bool helper_fun(Node* node)
    {

        if (node!=nullptr)
        {
            return true;
        }

        int balance = balanceFactor(node);
        if (balance > 1 || balance < -1) return false;

        return helper_fun(node->left) && helper_fun(node->right);
    }

    bool is_avl()
    {
       return helper_fun(root);
    }

    bool is_prime(int n)
    {
        int count = 0;
        if (n <= 1)
            return false;
        if (n == 2 || n == 3) 
            return true;
        for (int i = 2; i < n; i++)
        {
            
                if (n % i == 0)
                {
                    count++;
                } 
            
        }
        if (count > 1)
            return false;
        return true;
    }
};



int main()
{
    AVL tree;

   /* tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    cout << "In-Order Traversal: ";
    tree.inorder();

    cout << "\n\n\n";
    cout << "Pre-Order Traversal: ";
    tree.preorder();

    cout << "\n\n\n";


    cout << "Post-Order Traversal: ";
    tree.postorder();

    cout << "\n\n\n";


    cout << "MIN " << tree.find_min() << endl;
    cout << "MAX " << tree.find_max() << endl;
    cout << "Is AVL Tree: ";
    if (tree.is_avl() == true)
    {
        cout << " TRUE ";
    }
    else
    {
        cout << " FALSE ";
    }

    tree.remove(10);
    cout << "after delete  ";
    tree.inorder();*/


    tree.insert(10);  
    tree.insert(2);  
    tree.insert(13);   
    tree.insert(5);  
    tree.insert(7); 
    tree.insert(8);   

    cout << "In-Order Traversal: ";
    tree.inorder();

    cout << "\n\n\n";
    tree.problem2();

    cout << "In-Order Traversal: ";
    tree.inorder();
}