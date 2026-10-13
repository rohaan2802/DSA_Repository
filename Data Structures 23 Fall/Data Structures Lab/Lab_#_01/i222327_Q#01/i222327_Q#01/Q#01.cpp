#include <iostream>
using namespace std;



int main()
{

    int  count=-1;

    int nums1[] = { 1,2,3,4,5,6,7,8 };
    int nums2[] = { 1,2,7,4,4,4,7,3};
  
    int res[20];

    int new_array[20];
    int new_count = -1;
  
    
    for (int i = 0; i < 20; i++)
    {
        new_array[i] = 0;
   }



        for (int i = 0; i < 8; i++)
        {
           
            for (int j = 0; j < 8; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    ++count;

                    res[count] = nums1[i];
                }
            }

           

           }


       for (int i = 0; i < count+1; i++)
        {
            cout << res[i] << " ";
        }
        



       cout << "\n\n\n";
      for (int i = 0; i < 8; i++)
        {
            bool val = false;

            for (int j = 0; j <=i; j++)
            {
                if (res[i] == res[j])
                {
                    val = true;

                    break;

                }
            }


            if (!val)
            {
                ++new_count;

                new_array[new_count] = res[i];
            }

        }
   

    cout << " \n\n\n        Hello World\n\n\n";

    cout << "     Common Numbers are           ";

    for (int i = 0; i < 20 ; i++)
    {
        if (new_array[i] != 0)
        {
            cout << new_array[i] << " ";

        }
    }


    cout << "\n\n\n";
   

}