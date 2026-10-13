#pragma once
#include<iostream>
using namespace std;



template<typename T>
int Max_Function(int m, int n, T a[], T p[], T s) 

{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            double profitPerBarrel1 = static_cast<double>(p[j]) / a[j];
            double profitPerBarrel2 = static_cast<double>(p[j + 1]) / a[j + 1];
            if (profitPerBarrel1 < profitPerBarrel2) {
                std::swap(a[j], a[j + 1]);
                std::swap(p[j], p[j + 1]);
            }
        }
    }

    int filledBarrels = 0;
    T totalProfit = 0;

    // Fill the orders starting from the most profitable until all barrels are sold or no more orders can be filled
    for (int i = 0; i < n && filledBarrels < m; ++i) {
        T availableBarrels = std::min(m - filledBarrels, a[i]);
        filledBarrels += availableBarrels;
        totalProfit += availableBarrels * p[i];
    }

    // Calculate the profit for unsold barrels
    T unsoldBarrels = m - filledBarrels;
    totalProfit -= unsoldBarrels * s;

    return totalProfit;
}



