#pragma once
#pragma once
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