#include <iostream>
#include"header.h"
using namespace std;







int main() 
{
    Container<int> intContainer(5);

    intContainer.insert(10);
    intContainer.insert(20);
    intContainer.insert(30);
    intContainer.insert(40);

    cout << "Container is full: " << (intContainer.isFull() ? "true" : "false") << endl;
    intContainer.print();

    intContainer.remove(20);
    intContainer.print();

    std::cout << "Search 30: " << (intContainer.search(30) ? "found" : "not found") << std::endl;
    std::cout << "Search 50: " << (intContainer.search(50) ? "found" : "not found") << std::endl;

    return 0;
}
