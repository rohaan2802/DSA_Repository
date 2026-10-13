#include "pch.h"
#include"../Task 4/header.h"

TEST(GradeSortSearchTest, BubbleSortAndBinarySearchTest) 
{
    int studentGrades[] = { 88, 76, 92, 95, 85, 78, 89, 91, 87 };
    int studentIDs[] = { 101, 102, 103, 104, 105 };

    int numStudents = sizeof(studentGrades) / sizeof(studentGrades[0]);

    // Sort the student grades using bubble sort
    bubbleSort(studentGrades, numStudents);

    // Perform binary searches
    int grade102 = binarySearch(studentGrades, numStudents, 102);
    int grade91 = binarySearch(studentGrades, numStudents, 91);
    int grade77 = binarySearch(studentGrades, numStudents, 77);

    // Check the results of binary searches
    ASSERT_EQ(grade102, -1); // Student ID 102 not found
    ASSERT_EQ(grade91, 91);  // Student ID 91 found with grade 91
    ASSERT_EQ(grade77, -1);  // Student ID 77 not found
}
