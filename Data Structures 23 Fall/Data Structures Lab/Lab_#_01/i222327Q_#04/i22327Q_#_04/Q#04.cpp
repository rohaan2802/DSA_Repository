//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//
//	int input;
//
//
//	string user_name[4] = { "Ali","Usman","Yasir","Tom" };
//	string user_interests[4][3] = { { "hiking ","photography","cooking" },
//		{" photography" ,"travel"," painting"},
//{"cooking" ,"gaming","movies"},
//		{"hiking","travel"," photography"} };
//
//	cout << "\n\n\n\n";
//	for (int i = 0; i < 4; i++)
//	{
//
//		cout << "        " << i << ")   " << user_name[i] << "\n\n";
//
//
//	}
//
//	cout << " Select One Of The User_Name         ";
//	cin >> input;
//	cout << "\n\n\n";
//
//
//	string recommended_friends[4];
//
//	int recommended_friends_count=0;
//	string common_interests[3]; // Assuming the maximum number of common interests is 3
//	int common_interests_count = 0;
//
//
//	for (int i = 0; i < 4; ++i)
//	{
//
//		for (int i = 0; i < 3; i++)
//		{
//
//			for (int j = 0; j < 3; j++)
//			{
//				if (user_interests[i][j] == user_interests[input][i])
//					common_interests[common_interests_count] = user_interests[input][i];
//				common_interests_count++;
//				break; 
//
//
//
//
//			}
//
//
//		}
//
//
//
//		if (common_interests_count > 0) 
//		{
//			recommended_friends[recommended_friends_count]=user_name[i];
//			recommended_friends_count++;
//		}
//
//
//
//	}
//
//
//
//
//
//	cout << "Recommended friends for " << input << ":" << endl;
//	if (recommended_friends_count == 0) {
//		cout << "No recommended friends found." << endl;
//	}
//	else {
//		for (int i = 0; i < recommended_friends_count; ++i) {
//			cout << recommended_friends[i] << endl;
//		}
//	}
//
//
//
//}



#include <iostream>
#include <string>

using namespace std;

const int num_users = 4;

// Function to recommend friends based on shared interests
void recommendFriends(string user_profiles[], string user_interests[][3], string target_user, int num_users) {
    string recommended_friends[4]; // Assuming the maximum number of friends is equal to the number of users
    int recommended_friends_count = 0;

    // Find the index of the target_user
    int target_user_index = -1;
    for (int i = 0; i < num_users; ++i) {
        if (user_profiles[i] == target_user) {
            target_user_index = i;
            break;
        }
    }

    // If the target user is not found, return a message
    if (target_user_index == -1) {
        cout << "User not found." << endl;
        return;
    }

    // Calculate the intersection of interests between the target user and other users
    for (int i = 0; i < num_users; ++i) 
    {
        if (i != target_user_index)
        {
            string common_interests[3]; // Assuming the maximum number of common interests is 3
            int common_interests_count = 0;

            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (user_interests[target_user_index][j] == user_interests[i][k]) 
                    {
                        common_interests[common_interests_count] = user_interests[target_user_index][j];
                        common_interests_count++;
                        break; // Move to the next interest in the target user's list
                    }
                }
            }

            // If there are shared interests, recommend the user as a friend
            if (common_interests_count > 0) 
            {
                recommended_friends[recommended_friends_count] = user_profiles[i];
                recommended_friends_count++;
            }
        }
    }

    cout << "Recommended friends for " << target_user << ":" << endl;
    if (recommended_friends_count == 0) {
        cout << "No recommended friends found." << endl;
    }
    else {
        for (int i = 0; i < recommended_friends_count; ++i) {
            cout << recommended_friends[i] << endl;
        }
    }
}

int main() {
    string user_profiles[num_users] = { "UserA", "UserB", "UserC", "UserD" };
    string user_interests[num_users][3] = {
        {"hiking", "photography", "cooking"},
        {"photography", "travel", "painting"},
        {"cooking", "gaming", "movies"},
        {"hiking", "travel", "photography"}
    };

    string target_user = "UserD";
    recommendFriends(user_profiles, user_interests, target_user, 4);

    return 0;
}
