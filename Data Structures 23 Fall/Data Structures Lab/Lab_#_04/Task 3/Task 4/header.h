#pragma once
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) 

                                                    // if i=0 ---> i<4 ===> j=0 ---> j<4
                                                    // if i=1 ---> i<4 ===> j=0 ---> j<3
                                                    // if i=2 ---> i<4 ===> j=0 ---> j<2
                                                    // if i=3 ---> i<4 ===> j=0 ---> j<1

{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)      
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}




int binarySearch(int grades[], int n, int studentID)
{
    int left = 0;                                         // if n=5 ---> left ==0   --->  right ==4



                                                          // 1st Iteration ( 0<=4 )

    int right = n - 1;                                    // mid= 0+(4-0)/2==2 ====> if (grades[2]==studentID)  return grades[2]
                                                          // if( grades[2]<studentID ) ===> left=2+1==3
                                                          // else ===> right =2-1==1
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (grades[mid] == studentID)
        {
            return grades[mid];
        }

        if (grades[mid] < studentID) 
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    
    }

    return -1; 
}