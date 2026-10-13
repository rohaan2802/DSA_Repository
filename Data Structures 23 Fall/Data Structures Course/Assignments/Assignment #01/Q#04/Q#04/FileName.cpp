#include <iostream>
#include"header.h"
using namespace std;


int main()
{

    cout << "\n\n\n\n";
    Talk requests[]={ {2, 3}, {4, 10}, {2, 8}, {6, 9}, {0, 1}, {1, 12}, {13, 14} };

   // After Sorting ---->   (0,1) (1,12) (2,3) (2,8) (4,10) (6,9) (13,14)



    int n = sizeof(requests) / sizeof(requests[0]);

    Room_Booking schedule[100];  

    
    Fun(requests, n, schedule);

    cout << "                   Hello World\n\n\n\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << "(" << schedule[i].Room_val() << ", " << schedule[i].S_time_val() << ", " << schedule[i].E_time_val() << ") ";
    }
    cout << endl;

    cout << "\n\n\n\n";














    return 0;











}
