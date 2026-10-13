#pragma once

#include <string>
using namespace std;





struct StudentRecord
{
    int studentID;
    string name;
    float GPA;
};



void insertionSortStudents(StudentRecord students[], int size)
{

    for (int i = 1; i < size; ++i)
    {
        StudentRecord new_arr = students[i];

        int j = i - 1;               // if i=0 ---> j=-1      then 2nd condition will become false So we start iteration from i=1
        // if i=1 ---> j=0      
       // if i=2 ---> j=1      
      // if i=3 ---> j=2      
     // if i=4 ---> j=3      



        while (j >= 0 && students[j].GPA > new_arr.GPA)
            //   3.2        //3.8  
// if i=1--> j=0 ===> students[0+1]=students[0]  bcz---> 3.8>3.2    ---> j--   ===> j=-1 // condition become false




// if i=2--> j=1 ===> students[1+1]=students[1]  bcz---> 3.5>3.5    ---> j--   ===> j=0
// if i=2--> j=0 ===> students[0+1]=students[0]  bcz---> 3.8>3.2    ---> j--   ===> j=-1 // condition become false



// if i=3--> j=2 ===> students[2+1]=students[0]  bcz---> 3.9>3.5    ---> j--   ===> j=1 
// if i=3--> j=1 ===> students[1+1]=students[0]  bcz---> 3.6>3.5    ---> j--   ===> j=0 
// if i=3--> j=0 ===> students[0+1]=students[0]  bcz---> 3.8>3.2    ---> j--   ===> j=-1 // condition become false



        {
            students[j + 1] = students[j];
            j = j--;
        }


        students[j + 1] = new_arr;
    }

}

