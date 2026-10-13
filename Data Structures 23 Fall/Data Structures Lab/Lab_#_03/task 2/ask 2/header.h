#pragma once


template <typename T>
T findNthModifiedFibonacci(int n) 
{
    T num1 = 0, num2 = 1, num3 = 1;

    if (n == 0)
    {
        return num1;
    }
    
    else if (n == 1 || n == 2) 
    {
        return num2;
    }

    
    for (int i = 3; i <= n; i++) 
    {
        T next = num1 + num2 + num3;  // 2
        num1 = num2; // 1
        num2 = num3; // 1
        num3 = next; // 2
    }

    return num3;
}