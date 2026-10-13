#include<iostream>
#include"header.h"
using namespace std;




int main() 
{
    safeArray list(2, 13);
    safeArray yourList(-5, 9);
    

    cout << "\n\n\n";


    try 
    {
        list[2] = 10;
        cout << "list[2]: " << list[2] << endl;

        cout << "\n\n\n";


        yourList[-5] = 20;
        cout << "yourList[-5]: " << yourList[-5] << endl;

        cout << "\n\n\n";


        // Accessing out-of-bounds index
        cout << "list[1]: " << list[1] << endl;

        cout << "\n\n\n";

    }
    
  

    catch (const out_of_range& e)
    {
        cout << "\n\n\n";

        cout << "Exception caught: " << e.what() << endl;

        cout << "\n\n\n";

    }

    cout << "\n\n\n";



    return 0;
}