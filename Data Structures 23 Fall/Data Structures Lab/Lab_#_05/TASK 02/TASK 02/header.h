#pragma once
#include<iostream>
using namespace std;



class safeArray 
{
private:
    int* array;
    int lowerbound;
    int upperbound;


public:


    safeArray(int lower, int upper) : lowerbound(lower), upperbound(upper)
    {
        int size = upper - lower + 1;
        array = new int[size];
    }



    int& operator[](int index)
    {

        if (index < lowerbound || index > upperbound)
        {
            throw out_of_range("Array index out of bounds");
        }

        return array[index - lowerbound];
    }

    ~safeArray() 
    {
        delete[] array;
    }


};