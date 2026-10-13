#include<iostream>
#include"header.h"
using namespace std;


int main()
{
	int matrix1[3][3] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
	};

	int result1[9];

	spiralOrderTraversal(matrix1,result1);

	cout << "\n\n\n Matrix 1 Spiral Order:\n\n\n";

	for (size_t i = 0; i < 9; ++i)
	{
		cout << " " << result1[i];
	}
	cout <<"\n\n\n\n" << endl;

	float matrix2[4][4] = {
{1.1, 2.1, 3.1, 4.1},
{5.2, 6.2, 7.2, 8.2},
{9.3, 10.3, 11.3, 12.3},
{13.4, 14.4, 15.4, 16.4},
	};

	float result2[16];

	spiralOrderTraversal(matrix2,result2);

	cout << "\n\n\n Matrix 2 Spiral Order:\n\n\n";

	for (size_t i = 0; i < 16; ++i)
	{
		cout << " " << result2[i];
	}
	cout << "\n\n\n\n" << endl;

}