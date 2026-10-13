#pragma once
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
				for (int j=i;j<counter-1;j++)
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