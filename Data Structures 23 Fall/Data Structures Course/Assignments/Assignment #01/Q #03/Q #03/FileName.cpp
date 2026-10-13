#include <iostream>
#include"header.h"
using namespace std;







int main()
{
    int m = 10;
    int n = 5;
    int a[] = { 2, 3, 1, 4, 5 };
    int p[] = { 20, 30, 10, 40, 50 };
    int s = 0;


    cout << "\n\n\n\n";
    cout << "                Hello World\n\n\n\n";
    int result1 = Max_Function<int>(m, n, a, p, s);
    std::cout << "Test case 1: " << result1 << std::endl;  // Expected output: 100

    cout << "\n\n\n\n";
  
    return 0;
}