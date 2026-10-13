#pragma once
#include<iostream>
using namespace std;

template<typename T,int N>
T DotProduct( T (&arr1)[N], T(&arr2)[N])
{
    T result = 0;
    T sum = 0;
    for (size_t i = 0; i < N; ++i) 
    {
        result = arr1[i] * arr2[i];
        sum += result;
    }
     return sum;
}