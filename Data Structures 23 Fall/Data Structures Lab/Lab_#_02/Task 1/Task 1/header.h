#include<iostream>
using namespace std;



template <typename T>
void RemoveDups(T data[], int& size)
{
   

    int newSize = 0; 

    for (int i = 0; i < size; ++i) 
    {
        bool isDuplicate = false;

        for (int j = 0; j < newSize; ++j) 
        {
            if (data[i] == data[j]) 
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) 
        {
            data[newSize] = data[i];
            ++newSize;
        }
    }

    size = newSize; 
}
