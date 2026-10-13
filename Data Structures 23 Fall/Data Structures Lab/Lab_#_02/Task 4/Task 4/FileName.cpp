#include <iostream>
#include"header.h"


int main() {
    int student_scores1[] = { 10, 7, 0, 7 };
    int target_score1 = 14;
    int index1_1, index1_2;
    int arr_size = sizeof(student_scores1) / sizeof(student_scores1[0]);


    if (target(student_scores1, arr_size, target_score1, index1_1, index1_2))
    {
        cout << "Output 1: [" << index1_1 << ", " << index1_2 << "]" << endl;
    }
    else {
        std::cout << "No such pair found for target 1." << std::endl;
    }



    double student_scores2[] = { 3.0, 2.0, 4.0 };
    double target_score2 = 6.0;
    int index2_1, index2_2;
    int arr_size2 = sizeof(student_scores2) / sizeof(student_scores2[0]);

    if (target(student_scores2, arr_size2, target_score2, index2_1, index2_2))
    {
        cout << "Output 2: [" << index2_1 << ", " << index2_2 << "]" << endl;
    }
    else {
        std::cout << "No such pair found for target 2." << std::endl;
    }



    

    return 0;
}
