#include<iostream>
#include"hearder.h"
using namespace std;



int main()
{
    int Vector1[] = { 1, 2, 3 };
    int Vector2[] = { 4, 5, 6 };
    double Vector3[] = { 1.1, 4.2, 2.3 };
    double Vector4[] = { 6.4, 1.5, 8.6 };


    int result1 = DotProduct(Vector1, Vector2);
    double result2 = DotProduct(Vector3, Vector4);

    cout << "Dot Product 1: " << result1 << endl;
  cout << "Dot Product 2: " << result2 << endl;

    return 0;
}