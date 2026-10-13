#pragma once
#include<iostream>
using namespace std;

template<typename T>
class List
{
	int capacity;
	int index;

public:
	T* values;

	List(int size=5)
	{
		capacity = size;
		index = 0;
		values = new T[capacity];
	}

	bool insert(T item)
	{
		if (index < capacity)
		{
			values[index++] = item;
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if (capacity == index)
		{
			return true;
		}
		return false;
	}

	bool isEmpty()
	{
		if (index == 0)
		{
			return true;
		}
		return false;
	}


	bool insertAt(T item,int i)
	{
		if (isFull())
		{
			return false;
		}

		if (index < i)
		{
			values[i] = item;
			index++;
			return true;
		}
		else
		{
			for (int j = i; j < index; j++)
			{
				values[j + 1] = values[j];
			}
			values[i] = item;
			return true;
		}
	}

	void print()
	{
		for (int i = 0; i < index; i++)
		{
			cout << values[i] << " ";
		}
	}
	int search(T item)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (values[i] == item)
				return i;
		}
		return -1;
	}


	bool insertAfter(T itemTobeInserted, T item)
	{
		if (isFull())
		{
			return false;
		}

		int x = search(item);

		if (x == -1)
		{
			return false;
		}
		values[x + 1] = itemTobeInserted;
		index++;
		return true;
		
	}

	bool insertBefore(T itemTobeInserted, int item)
	{
		if (isFull())
		{
			return false;
		}

		int x = search(item);
		if (x == -1)
		{
			return false;
		}

		for (int j = x; j < index; j++)
		{
			 values[j+1]= values[j];
		}
		values[x] = itemTobeInserted;
		index++;
		return true;
	}

	bool remove(T item)
	{
		int x = search(item);
		if (x == -1)
		{
			return false;
		}
		for (int i = x; i < index; i++)
		{
			values[i] = values[i + 1];
		}
		index--;
		return true;
	}

	bool removeBefore(T item)
	{
		int x = search(item);
		if (x == -1)
		{
			return false;
		}

		/*for (int i = x; i < index; i++)
		{
			 values[i-1]= values[i];

		}*/
		remove(values[x - 1]);
		index--;

		return true;
	}
	bool removeAfter(T item)
	{
		int x = search(item);
		if (x == -1)
		{
			return false;
		}
	/*	for (int i = x; i < index; i++)
		{
			 values[i]= values[i+1];

		}*/
		remove(values[x + 1]);
		index--;

		return true;
	}
	bool operator==(List& L)
	{
		if (index != L.index)
		{
			return false;
		}
		for (int i = 0; i < index; i++)
		{
			if (values[i] != L.values[i])
			{
				return false;
			}
		}
		return true;
	}
	void reverse()
	{
		for (int i = 0; i <index/2; i++)
		{
			T temp = values[i];
			values[i] = values[index-i-1];
			values[index - i - 1] = temp;
		}
		cout << "\n\n\n\n";
		print();
		cout << "\n\n\n\n";
	}
	~List()
	{
		delete[] values;
	}
};


class DynamicList 
{
private:
	int size;
public:
	int* arr;
	DynamicList(int* temp, int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
	}
	~DynamicList()
	{
		delete[] arr;
	}
	void addEnd(int val) 
	{
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = val;
		delete[] arr;
		arr = temp;
		size++;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	void addStart(int val)
	{
		int* temp = new int[size + 1];
		temp[0] = val;
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size++;
	}

	void delStart()
	{
		int* temp = new int[size - 1];
		for (int i = 1; i < size; i++)
		{
			temp[i - 1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}

	void delEnd()
	{
		int* temp = new int[size - 1];
		for (int i = 0; i < size-1; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
	}

 bool Isempty()
	{
	 if (size == 0)
		 return true;
	}
 void clear() 
 {
	 delete[] arr;
	 arr = nullptr;
	 size = 0;
 }
 bool checkDupli()
 {
	 for (int i = 0; i < size; i++)
	 {
		 for (int j = i + 1; j < size; j++)
		 {
			 if (arr[i] == arr[j])
			 {
				 return true;
			 }
		 }
	 }
	 return false;
 }

 int Next(int pos)
 {
	 if (pos < 0 || pos >= size - 1)
		 return -1;
	 else
		 return arr[pos + 1];
 }
 int Previous(int pos)
 {
	 if (pos <= 0 || pos > size -1)
		 return -1;
	 else
		 return arr[pos - 1];
 }
	};