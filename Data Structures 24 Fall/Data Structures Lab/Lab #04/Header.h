#pragma once
#include<iostream>
#include<string>
using namespace std;

struct EmployeeRecord
{
	int employeeID;
	string name;
	float salary;
};

void bubbleSortEmployees(EmployeeRecord arr[],int size)
{
	EmployeeRecord temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j].salary > arr[j + 1].salary)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	
}

void sortUpperLowerSeparately(char* str, int size)
{
	char arr1[10], arr2[10];
	int x = 0, y = 0;

	for (int i = 0; i < size; i++)
	{
		int x = i;
		for (int j = i + 1; j < size; j++)
		{
			if (str[j] < str[x])
			{
				x = j;
			}
		}
		char temp = str[i];
		str[i] = str[x];
		str[x] = temp;
	}
	


	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			arr1[x++] = str[i];
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			arr2[y++] = str[i];
		}
	}

	int j = 0;
	for (int i = 0; i < x; i++)
	{
		str[j++] = arr1[i];
	}
	for (int i = 0; i < y; i++)
	{
		str[j++] = arr2[i];
	}


}

int linearSearchString(string arr[], int n, string target)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i]==target)
		{
			return i;
		}
	}
	return -1;
}



bool binarySearch2D(int arr[4][4], int rows, int cols, int target) {
	int start = 0;
	int end = rows * cols-1;
	int array1[16];
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array1[count++] = arr[i][j];
		}
	}



	while (start <= end) 
	{
		int mid = (start + end) / 2;
     	int mid_value =array1[mid];

		if (mid_value == target) 
		{
			return true;
		}
		else if (mid_value < target) 
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	

	return false; 
}
