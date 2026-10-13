#include<iostream>
#include"header.h"
using namespace std;


int main() {
    // Example usage
    List<int> myList(6);

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);


    cout << "\n\n\n\n";
    
    
    myList.print();                       // Output: 1 2 3 4 5

    cout << "\n\n\n\n";



    bool res = myList.insertAt(0, 0);     //0,1,2,3,4,5



    if (res == false)
    {
        cout << "     Limit Exceeding\n\n\n";
    }
    else
    {
        myList.print();                    
    }

    cout << "\n\n\n\n";




  bool res1=  myList.insertAt(6, 6);


  if (res1 == false)
  {
      cout << "     Limit Exceeding\n\n\n";
  }
  else
  {
      myList.print();                   
  }

    cout << "\n\n\n\n";



    myList.remove(3);

    myList.print();                    // Output: 0 1 2 4 5 

    cout << "\n\n\n\n";



    int index = myList.search(4);
    if (index != -1)
    {
        cout << "\n\n\n\n";

        cout << "Found at index " << index << std::endl;
    }
    else
    {
        cout << "\n\n\n\n";

        cout << "Not found" << std::endl;
    }

    cout << "\n\n\n\n";



    List<int> myList2(5);
    myList2.insert(0);
    myList2.insert(1);
    myList2.insert(2);
    myList2.insert(4);
    myList2.insert(5);

    if (myList == myList2)
    {
        cout << "\n\n\n\n";

        cout << "Lists are equal" << std::endl;
    }
    else 
    {

        cout << "\n\n\n\n";


        cout << "Lists are not equal" << std::endl;
    }

    cout << "\n\n\n\n";


    myList.reverse();
    myList.print();  // Output:   5 4 2 1 0

    cout << "\n\n\n\n";

    return 0;
}