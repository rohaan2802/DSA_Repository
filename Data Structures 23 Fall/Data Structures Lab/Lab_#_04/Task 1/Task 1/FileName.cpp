#include <iostream>
#include"header.h"
#include<string>
using namespace std;




int main()

{


    StudentRecord students[] =
    {
        {101, "Ali", 3.8},
        {102, "Usman", 3.2},
        {103, "Rohaan", 3.5},
        {104, "Ahsan", 3.9},
        {105, "Zanish", 3.6}
    };

    int size = sizeof(students) / sizeof(students[0]);

    insertionSortStudents(students, size);

    cout << "         \n\n\n     Hello World\n\n\n" <<endl;


    for (int i = 0; i < size; ++i)
    {
        std::cout << "ID: " << students[i].studentID << ", Name: " << students[i].name << ", GPA: " << students[i].GPA << std::endl;
    }

    return 0;
}
