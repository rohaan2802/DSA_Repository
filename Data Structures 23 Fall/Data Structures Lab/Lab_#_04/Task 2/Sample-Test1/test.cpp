#include "pch.h"
#include<string>
#include"../Task 2/header.h"

TEST(QuickSortTest, SortingTest) {
    EmployeeRecord employees[] = {
        {101, "Alice", 3000.0},
        {102, "Bob", 2500.0},
        {103, "Charlie", 3500.0},
        {104, "David", 2800.0},
        {105, "Eve", 3200.0}
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    iterativeQuickSortEmployees(employees, size);

    // Check if the employees are sorted by salary in non-decreasing order
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(employees[i - 1].salary, employees[i].salary);
    }
}

TEST(QuickSortTest, AlreadySortedTest) {
    EmployeeRecord employees[] = {
        {101, "Alice", 2500.0},
        {102, "Bob", 2800.0},
        {103, "Charlie", 3000.0},
        {104, "David", 3200.0},
        {105, "Eve", 3500.0}
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    iterativeQuickSortEmployees(employees, size);

    // Check if the employees are still sorted by salary in non-decreasing order
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(employees[i - 1].salary, employees[i].salary);
    }
}