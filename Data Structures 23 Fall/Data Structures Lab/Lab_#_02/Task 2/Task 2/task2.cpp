#include<iostream>
#include"header.h"
using namespace std;


int main()
{


	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	int arr_size = sizeof(arr) / sizeof(int);
	int k = 2;
	

	int *ptr=Rotate(arr,k, arr_size);

	cout << "\n\n\n\n";

	for (int i = 0; i < arr_size; i++)
	{
		cout << "  " << ptr[i] << "  ";
	}

	cout << "\n\n\n\n";







	string strs[] = {"apple", "banana", "cherry", "date"};

	


	int strs_size = sizeof(strs) / sizeof(string);


	string* ptr2 = Rotate(strs, k, strs_size);

	cout << "\n\n\n\n";


	for (int i = 0; i < strs_size; i++)
	{
		cout << "  " << ptr2[i] << "  ";
	}

	cout << "\n\n\n\n";
	
	
	

}