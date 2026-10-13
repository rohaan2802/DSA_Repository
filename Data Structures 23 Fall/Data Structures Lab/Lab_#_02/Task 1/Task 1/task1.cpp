#include <iostream>
#include"header.h"
using namespace std;




int main() 
{
   
    int age_data[] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
    int age_size = sizeof(age_data) / sizeof(age_data[0]);

    RemoveDups(age_data, age_size);
    for (int i = 0; i < age_size; ++i)
    {
        cout << age_data[i] << " ";
    }
    cout << endl << endl;

   
    string name_data[] = { "sara", "mary", "larry", "sara" };
    int name_size = sizeof(name_data) / sizeof(name_data[0]);

    RemoveDups(name_data, name_size);

    for (int i = 0; i < name_size; ++i)
    {
        cout << name_data[i] << " ";
    }
    cout <<endl<<endl;

    return 0;
}
