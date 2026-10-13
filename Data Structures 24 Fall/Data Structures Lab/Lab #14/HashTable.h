#pragma once

class HashTable
{
	int capacity;
	Node** arr_of_linkedlist;

public:
    HashTable(int size) 
    {
        capacity = size;
        arr_of_linkedlist = new Node * [capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr_of_linkedlist[i] = nullptr;
        }
    }

    int Hash_Function(int key)
    {
        int x = key % capacity;
        return x;
    }

    void insert(int key, int value) 
    {
        int i = Hash_Function(key); 
        Node* new_node = new Node(key, value);
        Node* current = arr_of_linkedlist[i];

        if (arr_of_linkedlist[i] == nullptr) 
        {
            arr_of_linkedlist[i] = new_node;
        }
        else 
        {
            while (current->get_Next() != nullptr)
            { 
                if (current->get_key() == key)
                {
                    current->set_value(value);
                    return;
                }
                current = current->get_Next();
            }
            if (current->get_key() == key)
            {
                current->set_value(value);
            }
            else 
            {
                current->set_Next(new_node);
            }
        }
    }

    void remove(int key)
    {
        int i = Hash_Function(key);
        Node* current = arr_of_linkedlist[i];

        if (current == nullptr) 
        {
            return;
        }
        if (current->get_key() == key)
        {
            arr_of_linkedlist[i] = current->get_Next(); 
            delete current; 
            return;
        }
        while (current->get_Next() != nullptr) 
        {
            if (current->get_Next()->get_key() == key)
            {
                Node* temp = current->get_Next();         
                current->set_Next(current->get_Next()->get_Next());
                delete temp;                         
                return;
            }
            current = current->get_Next();
        }

       }

    int search(int key) 
    {
        int i = Hash_Function(key);
        Node* current = arr_of_linkedlist[i];

        while (current != nullptr)
        {
            if (current->get_key() == key)
            {
                return current->get_value();
            }
            current = current->get_Next();
        }

        return -1;
    }

    ~HashTable() 
    {
        for (int i = 0; i < capacity; i++) 
        {
            Node* current = arr_of_linkedlist[i];
            while (current != nullptr) 
            {
                Node* temp = current;
                current = current->get_Next();
                delete temp;
            }
        }
        delete[] arr_of_linkedlist;
    }

    void  insert_quadratic_probing(int key, int value)
    {
        int t = Hash_Function(key);                 
        int i = 0,i1;
        while (i < capacity)
        {
            i1 = (t + i * i) % capacity;
            if (arr_of_linkedlist[i1] == nullptr)
            {
               arr_of_linkedlist[i1] = new Node(key, value);
                return;
            }
            else if (arr_of_linkedlist[i1]->get_key() == key) 
            {
                arr_of_linkedlist[i1]->set_value(value);
                return;
            }

            i++; 
        }
              
    }
};