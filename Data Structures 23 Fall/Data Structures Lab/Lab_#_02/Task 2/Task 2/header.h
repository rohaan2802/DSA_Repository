#pragma once
#include<iostream>
using namespace std;


//template<typename T>

/*T* Rotate(T* arr, int& k, int size)
{

	int count = 0;
	T* new_array = new T[size];

	for (int i = k; i < size; i++)
	{
		new_array[count] = arr[i];
		count++;
	}

	for (int i = 0; i <k; i++)
	{
		new_array[count] = arr[i];
		count++;


	}


	return new_array;
	delete[] new_array;

}

*/







template<typename T>

T* Rotate(T* arr, int& k, int size)
{

	int count = 0;
	T* new_array = new T[size];

	for (int i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}


	for (int i = k; i < size; i++)
	{
		arr[count] = new_array[i];
		count++;
	}

	for (int i = 0; i < k; i++)
	{
		arr[count] = new_array[i];
		count++;


	}


	return arr;
	delete[] new_array;

}
