#include<iostream>
#include"Node.h"
#include"HashTable.h"
using namespace std;

int main()
{
    HashTable h1(10);

    h1.insert(1, 10);
    h1.insert(11, 20); 
    h1.insert(2, 30);
    h1.insert(12, 50);


    cout << "************  Search key 1  **************** " << h1.search(1) << endl;
    cout << "************  Search key 11  *************** " << h1.search(11) << endl;
    cout << "************  Search key 2  **************** " << h1.search(2) << endl;


    h1.remove(1);
    cout << "************  After remove Key1 ---> Search key 1  **************** " << h1.search(1) << endl;
    cout << "\n\n\n\n";
    HashTable h2(7);
    h2.insert_quadratic_probing(1, 10);
    h2.insert_quadratic_probing(3, 15);
    h2.insert_quadratic_probing(4, 20);
    h2.insert_quadratic_probing(6, 25);

    cout << "************  Search key 1  **************** " << h2.search(1) << endl;
    cout << "************  Search key 3  **************** " << h2.search(3) << endl;
    cout << "************  Search key 6  **************** " << h2.search(6) << endl;


    return 0;
}