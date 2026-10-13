#include "pch.h"
#include"../Q#04/header.h"

TEST(BookingScheduleTest, MergeTwoBookingSchedules) {
    int R1[][2] = {
        {3, 5},
        {4, 8},
        {10,12}
    };
    int n1 = sizeof(R1) / sizeof(R1[0]);

    int R2[][2] = {
        {2, 4},
        {0, 6}
    };
    int n2 = sizeof(R2) / sizeof(R2[0]);

    int mergedSchedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    mergeBookingSchedules(R1, n1, R2, n2, mergedSchedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = 
    {
        {1, 0, 2},
        {2, 2, 3},
        {3, 3, 4},
        {3, 4, 5},
        {2, 5, 6},
        {1, 6, 8},
        {1, 10, 12}
    };

    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(mergedSchedule[i][j], expectedSchedule[i][j]);
        }
    }
}

TEST(BookingScheduleTest, MakeBookingSchedules) {
    int R[][2] = {
        {0, 2},
        {4, 6},
        {1, 7},
        {8, 9},
        {7, 10},
        {9, 10},
        {4, 10}
    };
    int n1 = sizeof(R) / sizeof(R[0]);

    int Schedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    makeBookingSchedules<int>(R, n1, Schedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 1},
        {2, 1, 2},
        {1, 2, 4},
        {3, 4, 6},
        {2, 6, 7},
        {2, 7, 8},
        {3, 8, 9},
        {3, 9, 10}
    };

    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Schedule[i][j], expectedSchedule[i][j]);
        }
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}