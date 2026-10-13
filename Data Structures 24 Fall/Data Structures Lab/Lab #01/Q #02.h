#pragma once
template<typename T>
T* RemoveDups(T *A, int x)
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