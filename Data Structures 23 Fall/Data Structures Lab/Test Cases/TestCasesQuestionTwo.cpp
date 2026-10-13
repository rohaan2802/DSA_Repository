//---------Test cases for Question 2 ----------//
TEST(MidPointTest, OddNumberOfElements) {
    LinkedList<int> myList;
    for (int i = 1; i <= 5; ++i) {
        myList.append(i);
    }
    ASSERT_EQ(find_mid_point(myList), 3);
}

//In Even elements , we can have two middle values
// 1 2 3 4 5 6
//     - -
// We will select second middle value (4)

TEST(MidPointTest, EvenNumberOfElements) {
    LinkedList<int> myList;
    for (int i = 1; i <= 6; ++i) {
        myList.append(i);
    }
    ASSERT_EQ(find_mid_point(myList), 4);
}

TEST(MidPointTest, SingleElement) {
    LinkedList<int> myList;
    myList.append(42);
    ASSERT_EQ(find_mid_point(myList), 42);
}

TEST(MidPointTest, EmptyList) {
    LinkedList<int> emptyList;
    ASSERT_EQ(find_mid_point(emptyList), -1);
}


//In Even elements , we can have two middle values
// 1 2 3 4 5 6 7 8 9 10
//         - - 
// We will select second middle value (6)

TEST(MidPointTest, AdditionalTest) {
    LinkedList<int> myList;
    for (int i = 1; i <= 10; ++i) {
        myList.append(i);
    }
    ASSERT_EQ(find_mid_point(myList), 6);
}

TEST(CharMidPointTest, OddNumberOfElements) {
    LinkedList<char> charList;
    for (char c = 'a'; c <= 'e'; ++c) {
        charList.append(c);
    }
    ASSERT_EQ(find_mid_point(charList), 'c');
}
