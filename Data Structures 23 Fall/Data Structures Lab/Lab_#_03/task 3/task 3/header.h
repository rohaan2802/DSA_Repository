#pragma once

template<typename T, int N, int M>
void spiralOrderTraversal(T (&matrix)[N][M],T result[])
{

	int top = 0, bottom = M - 1, left = 0, right = N - 1,idx=0;

	while (top <= bottom && left <= right)
	{
		             //0        //2
		for (int i = left; i <= right; ++i)          // from left to right
		{ 
			result[idx++] = matrix[top][i];      //00 , 01 , 02
		}
		++top;//1


		             //1           //2
		for (int i = top; i <= bottom; ++i)          // from top to bottom
		{
			result[idx++] = matrix[i][right];       // 12 , 22
		}
		--right;//1


		     //1    //2
		if (top <= bottom) 
		{
			            // 1         //0              // from right to left
			for (int i = right; i >= left; --i) 
			{
				result[idx++] = matrix[bottom][i];   // 21 , 20
			}
			--bottom; //1
		}



		if (left <= right)
		{
			             // 1       //1                     // from bottom to top
			for (int i = bottom; i >= top; --i)
			{
				result[idx++] = matrix[i][left];       // 10 
			}
			++left;
		}



	}




}