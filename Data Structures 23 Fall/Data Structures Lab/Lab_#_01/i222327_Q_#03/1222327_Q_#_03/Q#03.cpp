#include<iostream>
#include<iomanip>
using namespace std;


//int main()
//{
//	
//
//	int k = 4;
//
//	int sum=0;
//	int sum1=0;
//	int sum2=0;
//
//	int lrg = 0;
//	int ans = 0;
//
//	int arr[6] = {1,12,-5,-6,50,3};
//
//	for (int i = 0; i < k; i++)
//	{
//		sum += arr[i];
//		sum1 += arr[i + 1];
//		sum2 += arr[i + 2];
//		
//			
//	}
//	
//	
//
//	if (sum > sum1 && sum > sum1)
//		lrg = sum;
//
//	if (sum1 > sum && sum1 > sum2)
//		lrg = sum1;
//
//	if (sum2 > sum1 && sum2 > sum)
//		lrg = sum1;
//
//
//	cout << "\n\n\n  " << "   Max Val =   " << lrg << "\n\n\n";
//
//	ans = lrg / k;
//
//	cout << " Final Ans = " << ans << "." << setw(8) << setfill('0');
//
//	cout << "\n\n\n";
//	
//}





double findMaxAverage(int nums[], int n, int k) 
{
    double maxAvg = -1; 


    int sum = 0;
    for (int i = 0; i < k; ++i) 
    {
        sum += nums[i];
    }

    // Iterate through the array to find the maximum average
    for (int i = k; i < n; ++i) {
        // Update maxAvg if the current average is greater
        if (sum/ k > maxAvg) 
        {
            maxAvg = sum / k;
        }

        // Add the next element and remove the first element in the current window
        sum += nums[i] - nums[i - k];  //left to right operation
    }

    // Check the maximum average for the last window
    if (sum / k > maxAvg)
    {
        maxAvg = (sum) / k;
    }

    return maxAvg;
}

int main() {
    int nums1[] = { 1, 12, -5, -6, 50, 3 };
    int k1 = 4;
    cout << "Output for nums1: " << findMaxAverage(nums1, sizeof(nums1) / sizeof(nums1[0]), k1) << endl; // Output: 12.75

    int nums2[] = { 5 };
    int k2 = 1;
    cout << "Output for nums2: " << findMaxAverage(nums2, sizeof(nums2) / sizeof(nums2[0]), k2) << endl; // Output: 5.0

    return 0;
}
