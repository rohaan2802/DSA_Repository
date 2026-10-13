#include "pch.h"
#include "Question_One.h"

// Define test cases using Google Test
TEST(TimeToBuyTest, SinglePerson)
{
    std::queue<Person> Q1;
    Q1.push(Person(0, 2));
    Q1.push(Person(1, 3));
    Q1.push(Person(2, 2));

    int k = 1;
    int result = TimeToBuy(Q1, k);

    EXPECT_EQ(result, 7); // Adjust the expected result based on the correct logic
}

TEST(TimeToBuyTest, MultiplePersons)
{
    std::queue<Person> Q1;
    Q1.push(Person(0, 2));
    Q1.push(Person(1, 3));
    Q1.push(Person(2, 2));

    int k = 0;
    int result = TimeToBuy(Q1, k);

    EXPECT_EQ(result, 4); // Adjust the expected result based on the correct logic
}

