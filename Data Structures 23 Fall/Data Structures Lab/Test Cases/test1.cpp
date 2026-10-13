#include <gtest/gtest.h>
#include "header.h"
TEST(q1, t3) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(4, 10);
    string org = "4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t4) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(10, 4);
    string org = "10-1 -> 9-1 -> 8-1 -> 7-1 -> 7-2 -> 7-3 -> 6-3 -> 5-3 -> 4-3";
    EXPECT_EQ(result, org);
}


TEST(q1, t5) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(5, 15);
    string org = "5-1 -> 6-1 -> 7-1 -> 8-1 -> 8-2 -> 8-3 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2 -> 15-2";
    EXPECT_EQ(result, org);
}



TEST(q1, t6) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(15, 5);
    string org = "15-2 -> 14-2 -> 13-2 -> 12-2 -> 12-3 -> 11-3 -> 10-3 -> 9-3 -> 8-3 -> 8-2 -> 8-1 -> 7-1 -> 6-1 -> 5-1";
    EXPECT_EQ(result, org);
}


TEST(q1, t7) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(5, 10);
    string org = "5-1 -> 6-1 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t8) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath( 10 , 5);
    string org = "10-1 -> 9-1 -> 8-1 -> 7-1 -> 6-1 -> 5-1";
    EXPECT_EQ(result, org);
}

TEST(q1, t9) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result  =  obj.GetPath(3, 11);
    string org = "3-1 -> 2-1 -> 2-2 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 8-2 -> 8-3 -> 9-3 -> 10-3 -> 11-3";
    EXPECT_EQ(result, org);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
