#pragma once
#include<iostream>
using namespace std;


template <typename T>
T* target(T scores[], T target)
{
    int size = sizeof(scores) / sizeof(T);
T *result = new T[2];

    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if (scores[i] + scores[j] == target) 
            {
                result[0] = i;
                result[1] = j;
               // return true;
            }
        }
    }

    

    return result;
}




//template <typename T>
//bool findTwoSumIndices(T scores[], int size, T target, int& index1, int& index2) {
//    for (int i = 0; i < size; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            if (scores[i] + scores[j] == target) {
//                index1 = i;
//                index2 = j;
//                return true;
//            }
//        }
//    }
//    return false;
//}
