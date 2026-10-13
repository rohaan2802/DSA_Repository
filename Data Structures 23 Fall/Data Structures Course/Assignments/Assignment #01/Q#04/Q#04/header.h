#pragma once

#include<iostream>
using namespace std;

class Talk
{
	int S_time;
	int E_time;

public:
	Talk(int s,int t)
	{
		S_time = s;
		E_time = t;
	}

	

	int S_time_val()
	{
		return S_time;
	}


	int E_time_val()
	{
		return E_time;
	}




};


class Room_Booking
{
	int room_num;
	int start_t;
	int end_t;

public:
	Room_Booking() :room_num(0), start_t(0), end_t(0) {};



	void room_initializing(int x, int y, int z)
	{
		room_num = x;
		start_t = y;
		end_t = z;
	}


	int Room_val()
	{
		return room_num;
	}


	int S_time_val()
	{
		return start_t;
	}


	int E_time_val()
	{
		return end_t;
	}




};





void bubble_sorting(Talk* requests, int n)           // Bubble sorting to sort the starting time in the ascending Order
{
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (requests[j].S_time_val() > requests[j + 1].S_time_val())
			{
				Talk temp = requests[j];
				requests[j] = requests[j + 1];
				requests[j + 1] = temp;
			}
		}
	}
}






void Fun(Talk* requests, int n, Room_Booking* schedule_making) 
{
	int availableRooms[100] = { 0 };  
	int room_count = 1;

	
	bubble_sorting(requests, n);




	int count = 0;

	for (int i = 0; i < n; ++i) 
	{
		int s = requests[i].S_time_val();
		int t = requests[i].E_time_val();

		

		int index;        //1       //1
		for (index = 1; index <= room_count; index++)   // For iteration #01
		{               //0             //0
			if (availableRooms[index] <= s)            // availableRooms[1]<=0
			{        
				availableRooms[index] = t;            // availableRooms[1]=1
				break;
			}
		}

            //1   >    1    // False            It Runs for iteartion #03
		if (index > room_count)
		{
			availableRooms[room_count + 1] = t;        // availableRooms[1+1]  --->  availableRooms[2]=3
			index = room_count + 1;                   //  index=2
			room_count++;                            //   next_room ---> 2
		}

	                     //0                     //1  //0  //1        
		schedule_making[count].room_initializing(index,s,t);
		
		count++;
	}
}



// Working 


// ---> Available Rooms ---->    1,2,3,4





