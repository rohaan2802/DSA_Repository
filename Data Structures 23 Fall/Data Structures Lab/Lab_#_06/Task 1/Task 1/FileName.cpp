#include<iostream>
#include"header.h"
using namespace std;



int main() 

{
   

    LinkedList myList;

    // Inserting elements
    myList.insert_at_tail(10);
    myList.insert_at_tail(20);
    myList.insert_at_tail(30);

    // Insert at the beginning
    myList.insert_at_Head(5);

    // Check if empty
    if (myList.isEmpty())
    {
       cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }

  
    if (myList.search(20))
    {
       cout << "Element 20 found" << endl;
    }

    else
    {
        cout << "Element 20 not found" << endl;
    }

   
    myList.update(20, 25);

  
    myList.insertAtIndex(15, 2);

    myList.deleteNode(30);

   
    myList.print();

    return 0;


}
