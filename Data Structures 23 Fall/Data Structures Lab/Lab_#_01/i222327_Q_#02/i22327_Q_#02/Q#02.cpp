#include<iostream>
#include<cmath>
using namespace std;

int main()
{


	int per1[] = { 2,23,2 ,6};
	int size = sizeof(per1) / sizeof(int);
	int count=0;

	bool val=false;

	int a;
	float c;

	int arr_cou=0;
	int arr[10];


	/*for (int i = 0; i < 2; i++)
	{
		if (per1[i] > per1[i + 1])
		{
			int temp = per1[i];
			per1[i] = per1[i + 1];
			per1[i + 1] = temp;
		}
	
		
		
	}
	*/
	cout << "\n\n\n";



	for(int i=0; i<size; i++)
	{
		cout << per1[i] << "       ";

	}

	cout<<"\n\n\n\n";

	for (int i = 0; i <size-1; i++)
	{



		for (int j = 0; j <i; j++)
		{
			c = sqrt(per1[i] + per1[j]);
			//cout << "\n\n\n" << c << "\n\n\n";


			a = c;

			

			if (a - c == 0)

			{
				count++;
			}

			arr[arr_cou] = a;
			arr_cou++;

		}
		
	
			
			

			

		
	}




/*	for (int i = 0; i < 1; i++)
	{
		if (per1[i] == per1[i + 1] && per1[i+1] == per1[i + 2] && per1[i]==per1[i+2])
		{
			count--;
		}
	}
	

	for (int i = 0; i < 2; i++)
	{
		if (per1[i] == per1[i + 1])
			val = true;
		else
			val = false;
	}


	if (val == true)
		count--;

	*/

	cout << "\n\n\n     The Total Perms Are        " << count << "           \n\n\n\n";



}