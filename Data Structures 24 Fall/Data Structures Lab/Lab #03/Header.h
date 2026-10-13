#pragma once
#include<cmath>
#include<iostream>
using namespace std;


template<typename T,int rows,int cols>
double calculateEuclideanNorm(const T array[rows][cols])
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += array[i][j] * array[i][j];
		}
	}
	return sqrt(sum);
}

template<typename T, int rows, int cols>
void rotateMatrix90DegreesClockwise(T matrix[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = i+1; j < cols; j++)
		{
			T temp = matrix[i][j];
			matrix[i][j]= matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2; j++) 
		{
			T temp = matrix[i][j];
			matrix[i][j]= matrix[i][2-j];
			matrix[i][2 - j] = temp;
			
		}
	}
}


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


void inputStudentData(int numStudents, int numQuizzes, int rollNumbers[], int scores[][3])
{
    system("cls");
    for (int i = 0; i < numStudents; i++) 
    {

        cout << "Enter scores for 3 Quizzes of Roll# "<< rollNumbers[i]<<" Student     ";
        for (int j = 0; j < numQuizzes; j++)
        {
            cin >> scores[i][j];
        }
    }
}

void printStudentScores(int numStudents, int rollNumbers[], int scores[][3])
{
    system("cls");
    cout << "\nScore Board\n";
    for (int i = 0; i < numStudents; i++) 
    {
        cout << " Scores of Roll#: " << rollNumbers[i]<<"   ";
        for (int j = 0; j < 3   ; j++)
        {
            cout << scores[i][j] << " ";
        }
        cout <<endl;
    }
}

 void calculateHighLowScores(int numStudents, int numQuizzes, int scores[][3])
{

    system("cls");
    for (int i = 0; i < numStudents; i++)
    {
        int marks1 = scores[0][0],marks2=scores[0][0];

        for (int j = 0; j < numQuizzes; j++)
        {
            if (scores[i][j] > marks1)
            {
                marks1 = scores[i][j];
            }
            if (scores[i][j] < marks2)
            {
                marks2 = scores[i][j];
            }

        }
        cout << " Highest Marks of student " << i + 1 << " = " << marks1 << endl;
        cout << " Lowest  Marks of student " << i + 1 << " = " << marks2 << endl;
    }
    
    
}

void calculateAverages(int numStudents, int numQuizzes, int scores[][3])
{
    system("cls");
    int sum=0;
    for (int i = 0; i < numQuizzes; i++)
    {
        int x = 0;
        for (int j = 0; j < numStudents; j++)
        {
            x += scores[i][j];
        }
        sum += x;
        cout << " Average of Quiz# " << i + 1 << " " << x / numStudents << endl;
    }
    cout << "\n\n" << " Average of All Quizes " << sum / numStudents << endl;
}

void calculateHighestLowestAverages(int numStudents, int numQuizzes, int scores[][3])
 {
    
    system("cls");
    int avg1 = 0, avg2 = 0;

    for (int i = 0; i < numQuizzes; i++)
    {
        int marks1 = scores[0][0], marks2 = scores[0][0];

        for (int j = 0; j < numStudents; j++)
        {
            if (scores[i][j] > marks1)
            {
                marks1 = scores[i][j];
                avg1 += marks1;
                
            }
            if (scores[i][j] < marks2)
            {
                marks2 = scores[i][j];
                avg2 += marks2;
            }
            
        }
       
      
        cout << " Highest Average Marks Quiz# " << i + 1 << " = " << avg1/ numStudents << endl;
        cout << " Lowest  Average Marks Quiz# " << i + 1 << " = " << avg2/ numStudents << endl;
    }
   
}

void calculateHighestLowestMarks(int numStudents, int numQuizzes, int scores[][3])
{
    system("cls");
    for (int i = 0; i < numQuizzes; i++)
    {
        int marks1 = scores[0][0], marks2 = scores[0][0];

        for (int j = 0; j < numStudents; j++)
        {
            if (scores[i][j] > marks1)
            {
                marks1 = scores[i][j];
            }
            if (scores[i][j] < marks2)
            {
                marks2 = scores[i][j];
            }

        }
        cout << " Highest Marks of student " << i + 1 << " = " << marks1 << endl;
        cout << " Lowest  Marks of student " << i + 1 << " = " << marks2 << endl;
    }
}

int main()
{
  const  int numStudents = 10;
  const  int numQuizes = 3;
  int rollNumbers[numStudents] = {1111,1112,1113,1114,1115,1116,1117,1118,1119,1120};
    int scores[numStudents][numQuizes];

    inputStudentData(numStudents, numQuizes, rollNumbers, scores);

    printStudentScores(numStudents, rollNumbers, scores);

    calculateHighLowScores(numStudents, numQuizes, scores);

    calculateAverages(numStudents, numQuizes, scores);

    calculateHighestLowestAverages(numStudents, numQuizes, scores);

    calculateHighestLowestMarks(numStudents, numQuizes, scores);

    return 0;
}


