#include "pch.h"
#include "../Task 1/header.h"
#include <cstring>


TEST(StudentSortTest, SortingTest) {
    StudentRecord students[] = {
        {101, "Alice", 3.8},
        {102, "Bob", 3.6},
        {103, "Charlie", 3.9},
        {104, "David", 3.5},
        {105, "Eve", 4.0}
    };

    int size = sizeof(students) / sizeof(students[0]);

    insertionSortStudents(students, size);

    // Check if the students are sorted by GPA in non-decreasing order
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(students[i - 1].GPA, students[i].GPA);
    }
}