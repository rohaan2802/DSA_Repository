#include <iostream>
#include"header.h"
using namespace std;
const int MAX_STUDENTS = 100;



int main()
{

    int studentIDs[MAX_STUDENTS] = { 101, 102, 103, 104, 105 };
    int grades[MAX_STUDENTS] = { 85, 92, 78, 95, 88 };
    int n = 5;

    bubbleSort(grades, n);

  

    cout << "\n\n\n   Bubbule Sorting\n\n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "   Student's ID'z    " << studentIDs[i] << "           Students Grades     " << grades[i] << endl<<endl;
    }


    int FindID = 103;
    int grade = binarySearch( grades, n, FindID);

    if (grade != -1) {
        cout << "Student ID " << FindID << " has a grade of " << grade <<endl;
    }
    else {
        cout << "Student ID " << FindID << " not found in the database." << endl;
    }

    return 0;
}
