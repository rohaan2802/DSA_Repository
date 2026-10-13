#pragma once
#include<iostream>
using namespace std;



template <typename T>
class Container
{
private:
    T* values;
    int capacity;
    int counter;



public:
    Container(int capacity) : capacity(capacity), counter(0)
    {
        values = new T[capacity];
    }

    ~Container()
    {
        delete[] values;
    }


    bool isFull() const
    {
        return counter >= capacity;
    }


    bool insert(T value)
    {
        if (isFull())
        {
            return false; // Container is full
        }

        values[counter++] = value;
        return true;
    }

    bool search(T value) const
    {
        for (int i = 0; i < counter; ++i)
        {
            if (values[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    bool remove(T value)
    {
        int indexToRemove = -1;
        for (int i = 0; i < counter; ++i) {
            if (values[i] == value) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove == -1) {
            return false;
        }


        for (int i = indexToRemove; i < counter ; ++i)
        {
            values[i] = values[i + 1];
        }

        --counter;
        return true;
    }

    void print() const
    {
        for (int i = 0; i < counter; ++i)
        {
            cout << values[i] << " ";
        }
        cout << "\n\n";
    }
};
