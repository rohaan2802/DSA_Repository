#pragma once
#include<math.h>
template<typename T>

// Union
T* unionSets(T* set1, int size1, T* set2, int size2)
{




	int size = size1 + size2;
	T* new_array = new T[size];
	int x = 0;

	for (int i = 0; i < size1; i++)
	{
		new_array[x++] = set1[i];
	}

	for (int i = 0; i < size2; i++)
	{
		bool val = false;

		for (int j = 0; j < x; j++)
		{
			if (set2[i] == new_array[j])
			{
				val = true;
				break;
			}
		}
		if (!val)
		{
			new_array[x++] = set2[i];
		}
	}
	//sorting for removing duplicates
	/*	for(int i=0;i<x;i++)
	{
		for (int j = 0; j < x - i - 1; j++)
		{
			if (new_array[j] > new_array[j + 1])
			{
				T temp = new_array[j];
				new_array[j] = new_array[j + 1];
				new_array[j + 1] = temp;
			}
		}
	}*/

	// removing duplicates
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		if (new_array[i] != new_array[i + 1])
			new_array[a++] = new_array[i];
	}

	return new_array;
}

// Intersection
template<typename T>
T* intersectionSets(T* set1, int size1, T* set2, int size2)
{

	int x = 0;
	T* temp_array = new T[size1 < size2 ? size1 : size2];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (set1[i] == set2[j])
			{
				temp_array[x++] = set1[i];
				break;
			}
		}
	}





	// removing duplicates
	int a = 0;
	for (int i = 0; i < x; i++)
	{
		if (temp_array[i] != temp_array[i + 1])
			temp_array[a++] = temp_array[i];
	}

	return temp_array;
}

// Disjoint Sets
template<typename T>
bool areDisjoint(T* set1, int size1, T* set2, int size2)
{
	int x = 0;
	T* temp_array = new T[size1 < size2 ? size1 : size2];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (set1[i] == set2[j])
			{
				return false;
			}
		}
	}

	return true;
}

// Find element
template<typename T>
bool elementExists(T* set, int size, T element)
{


	for (int i = 0; i < size; i++)
	{
		if (set[i] == element)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
T* RemoveDups(T* A, int x)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = i + 1; j < x;)
		{
			if (A[i] == A[j])
			{
				for (int k = j; k < x - 1; ++k)
				{
					A[k] = A[k + 1];
				}
				--x;
			}
			else
			{
				++j;
			}
		}
	}
	/*  int c = 0;
	  for (int i = 0; i < x; i++)
	  {
		  if (A[i] != A[i + 1])
		  {
			  A[c++] = A[i];
		  }
	  }*/
	return A;
}







template<class T>
class Calculator
{
	T num1, num2;
public:
	Calculator(T a, T b)
	{
		num1 = a;
		num2 = b;
	}
	T add()
	{
		return (num1 + num2);
	}
	T multiply()
	{
		return(num1 * num2);
	}
	T subtract()
	{
		return (num1 - num2);
	}
	T divide()
	{
		if (num2 != 0)
		{
			return (num1 / num2);
		}
		else
			return 0;
	}
	T power()
	{
		return(pow(num1, num2));
	}
	T square()
	{
		return(num1 * num1);
	}
};


template<class T>
class Container
{
	T* value;
	int capacity;
	int counter;
public:
	Container(int x)
	{
		value = new T[x];
		capacity = x;
		counter = 0;
	}
	bool isFull()
	{
		if (counter == capacity)
			return true;
		else
			return false;
	}
	void insert(T x)
	{
		value[counter++] = x;
	}
	bool search(T x)
	{
		for (int i = 0; i < counter; i++)
		{
			if (value[i] == x)
			{
				return true;
			}
		}
		return false;
	}
	void remove(T x)
	{
		for (int i = 0; i < counter;)
		{
			if (value[i] == x)
			{
				for (int j = i; j < counter - 1; j++)
				{
					value[j] = value[j + 1];
				}
				counter--;
			}
			else
			{
				i++;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < counter; i++)
		{
			cout << value[i] << "  ";
		}
	}
	~Container()
	{
		delete[] value;
	}
};