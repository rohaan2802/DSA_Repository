#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;


struct EmployeeRecord 
{
    int employeeID;
    string name;
    float salary;
};


void swap(EmployeeRecord& a, EmployeeRecord& b)
{
    EmployeeRecord temp = a;
    a = b;
    b = temp;
}
                                                                    // size==5;

void iterativeQuickSortEmployees(EmployeeRecord arr[], int size)   // if i=0 ---> i<4   ===> j=0 ---> j<4 ===> if(3000 > 2500) ===> ( 2500,3000 )
                                                                  // if i=1 ---> i<4   ===> j=0 ---> j<3 ===> if(3000 > 2500) ===> ( 2500,3000 )
                                                                 // if i=2 ---> i<4   ===> j=0 ---> j<2 ===> if(3000 > 2500) ===> ( 2500,3000 )
                                                                // if i=3 ---> i<4   ===> j=0 ---> j<1 ===> if(3000 > 2500) ===> ( 2500,3000 )



{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j].salary > arr[j + 1].salary) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
