#include <iostream>
#include <string>
#include"header.h"
using namespace std;




int main() 

{
    EmployeeRecord employees[] =
    {
        {1, "Usman Khan", 5000},
        {2, "Mohammad Rohaan", 3000},
        {3, "Ali Murtaza", 4000},
        {4, "Ayesha Khan", 6000},
        {5, " Sh Ahsan ", 2000}
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    iterativeQuickSortEmployees(employees, size);

    cout << "    \n\n\n Hello World  \n\n\n" << endl;
    
    
    for (int i = 0; i < size; i++) 
    {
        cout << "Employee ID: " << employees[i].employeeID << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << endl;
    }

    return 0;
}