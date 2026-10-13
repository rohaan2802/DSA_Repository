#pragma once
#include<iostream>
using namespace std;



class Stack
{
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size = 50)
    {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(int x)
    {
        if (top < capacity)
        {
            data[++top] = x;

        }
    }

    int pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        return data[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            return 0;
        }
        return data[top];
    }

    void clear()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void print()
    {
        cout << endl;

        for (int i = 0; i < top; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};


//Q# 02
bool isValid(string str)
{

    Stack stack;





    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {

            stack.push(str[i]);

        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (stack.isEmpty())
            {
                return false;
            }

            if ((str[i] == ')' && stack.peek() == '(') || (str[i] == '}' && stack.peek() == '{') || (str[i] == ']' && stack.peek() == '['))
            {
                stack.pop();
            }

            else
            {
                return false;
            }


        }
    }

    if (stack.isEmpty())
    {
        return true;
    }
    else
        return false;


}






//Q# 03

class Queue
{
    Stack* s1;
    Stack* s2;

public:

    Queue(int x = 50)
    {
        s1 = new Stack(x);
        s2 = new Stack(x);
    }

    void enqueue(int val)
    {
        s1->push(val);
    }

    int front()
    {
        if (s2->isEmpty())
        {
            while (!s1->isEmpty())
            {
                int val = s1->pop();
                s2->push(val);
            }
        }

        return s2->peek();
    }


    void dequeue()
    {

        s2->pop();
    }


};








