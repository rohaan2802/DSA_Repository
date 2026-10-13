#include<iostream>
#include "pch.h"
#include "../Lab01/Header.h"
using namespace std;
// Question 1
TEST(List, insert) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    ASSERT_EQ(false, obj1.insert(6));
    obj1.print();

}

TEST(List, insertat) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1)); //0
    ASSERT_EQ(true, obj1.insert(2)); //1
    ASSERT_EQ(true, obj1.insert(3)); //2
    ASSERT_EQ(true, obj1.insert(4)); //3

    bool f = obj1.insertAt(3, 1);
    EXPECT_EQ(3, obj1.values[1]);
    obj1.print();

}

TEST(List, insertafter) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    obj1.insertAfter(5, 4);
    EXPECT_EQ(5, obj1.values[4]);

}

TEST(List, insertbefore) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(5));

    obj1.insertBefore(4, 5);
    EXPECT_EQ(4, obj1.values[3]);

}


TEST(List, remove) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2)); //1
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.remove(1);
    int j = 2;
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(j++, obj1.values[i]);
        cout << obj1.values[i] << endl;
    }
}

TEST(List, removeafter) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.removeAfter(3);
    EXPECT_EQ(5, obj1.values[3]);
}

TEST(List, removebefore) {
    List<int> obj1(4);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    obj1.removeBefore(3);
    EXPECT_EQ(3, obj1.values[1]);
}
TEST(List, ComparisonOperator) {
    List<int> obj1(4);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    List<int> obj2(4);
    ASSERT_EQ(true, obj2.insert(1));
    ASSERT_EQ(true, obj2.insert(2));
    ASSERT_EQ(true, obj2.insert(3));
    ASSERT_EQ(true, obj2.insert(4));

    List<int> obj3(4);
    ASSERT_EQ(true, obj3.insert(1));
    ASSERT_EQ(true, obj3.insert(5));
    ASSERT_EQ(true, obj3.insert(6));
    ASSERT_EQ(true, obj3.insert(9));

    ASSERT_EQ(true, obj1 == obj2);
    ASSERT_EQ(false, obj2 == obj3);

}

TEST(List, reverse) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.reverse();
    int j = 5;
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(j--, obj1.values[i]);
    }
}
// Question 2
TEST(Dynamic_List, addend) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a,5);
    obj1.addEnd(8);
    EXPECT_EQ(8, obj1.arr[5]);
    obj1.print();
    obj1.addEnd(9);
    EXPECT_EQ(9, obj1.arr[6]);
    obj1.print();
}
TEST(Dynamic_List, addstart) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.addStart(6);
    EXPECT_EQ(6, obj1.arr[0]);
    for (int i = 1; i < 6; i++) {
        EXPECT_EQ(i, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, addGivenPosition) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.addGivenP(7,3);
    EXPECT_EQ(7, obj1.arr[3]);
    obj1.print();
    obj1.addGivenP(9, 3);
    EXPECT_EQ(9, obj1.arr[3]);
    obj1.print();
}
TEST(Dynamic_List, deleteStart) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delStart();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(i+2, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, deleteEnd) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delEnd();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(i + 1, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, deleteGivenPosition) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delGivenP(2);
    EXPECT_EQ(4, obj1.arr[2]);
    obj1.print();
}
TEST(Dynamic_List, case1) {
    int* a = new int[7];
    for (int i = 0; i < 7; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 7);
    EXPECT_EQ(5, obj1.Next(3));
    EXPECT_EQ(3, obj1.Previous(3));
    EXPECT_EQ(0, obj1.checkDupli());
}


