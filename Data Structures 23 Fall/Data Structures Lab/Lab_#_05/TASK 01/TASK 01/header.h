#pragma once
#include<iostream>
using namespace std;



template<typename T>
class List
{
public:
    T* values;                 // A pointer of type T
    int capacity;             //  A variable capacity of type int to hold the total capacity of the list
    int counter;             //   A variable counter of type int which holds the current index of the list

                                   // Parametrized Constructor
    List(int capacity) 
    {
        this->capacity = capacity;
        values = new T[capacity];
        counter = 0;
    }

                                   // Destructor
    ~List()
    {
        delete[] values;
    }




                                  // Insert an item at the end of the list ( Inserts an item and increments the counter only if the list is not full )
    bool insert(T item) 
    {
        if (counter < capacity) 
        {
            values[counter] = item;
            counter++;
            return true;
        }

        return false;
    
    }



                                    
    bool insertAt(T item, int index)
    {
        if (index >= 0 && index <= counter && counter < capacity)
        {
        
            for (int i = counter-1 ; i >= index; i--) 
            {
                values[i + 1] = values[i];
            }

           /* for (i = counter; i >= index; i--)
                values[i] = values[i - 1];*/



            values[index] = item;
            counter++;
            return true;
        }
        return false;
    }


                                                         
   
                                                     // Search for an item in the list
    int search(T item) 
    {
        for (int i = 0; i < counter; i++) 
        {
            if (values[i] == item)
            {
                return i;
            }
        }
        return -1;
    }
    
    
                                                      //search the item already present in the list and then insert the itemtobeinserted after item.
    void insertAfter(T itemToBeInserted, T item)
    {
        int index = search(item);
        if (index != -1)
        {
            insertAt(itemToBeInserted, index + 1);
        }
    }



                                                      // search the item already present in the list and then insert the itemtobeinserted before item.

    void insertBefore(T itemToBeInserted, T item) 
    {
        int index = search(item);
        if (index != -1)
        {
            insertAt(itemToBeInserted, index);
        }
    }






                                            // Check if the list is empty
    bool isEmpty() 
    {
        return counter == 0;
    }



                                          // Check if the list is full
    bool isFull()
    {
        return counter == capacity;
    }

                                          // Remove an item from the list
    void removeAt(T item) 
    {
        int index = search(item);
        if (index != -1)
        {
           
            for (int i = index; i < counter - 1; i++) 
            {
                values[i] = values[i + 1];
            }
            counter--;
        }
    }




                                                            // Remove an item before a specific item
    void removeBefore(T item) 
    {
        int index = search(item);
        if (index != -1 && index > 0) 
        {
            removeAt(index - 1);
        }
    }




                                          // Remove an item after a specific item
    void removeAfter(T item)
    {
        int index = search(item);
        if (index != -1 && index < counter - 1)
        {
            removeAt(index + 1);
        }
    }





   
    
                                                        // Print all the items in the list
    void print()
    {
        for (int i = 0; i < counter; i++) 
        {
            cout << values[i] << " ";
        }
        cout << endl;
    }







                                                     // Overload the equality operator to compare two lists
    bool operator==(const List& other) 
    {
        if (counter != other.counter)
        {
            return false;
        }

        for (int i = 0; i < counter; i++)
        {
            if (values[i] != other.values[i])
            {
                return false;
            }
        }

        return true;
    }




                                               // Reverse the elements in the list
    void reverse()
    {
        int start = 0;
        int end = counter - 1;

        while (start < end) 
        {
            T temp = values[start];
            values[start] = values[end];
            values[end] = temp;

            start++;
            end--;
        }


    }





};