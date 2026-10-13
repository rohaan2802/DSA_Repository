#include "pch.h"
#include "Header.h"


//***************** Q1 Test cases ********************
TEST(DoublyLinkedListTest, EmptyList) {
    DoublyLinkedList dll;
    EXPECT_TRUE(dll.isEmpty());
}

TEST(DoublyLinkedListTest, InsertToHead) {
    DoublyLinkedList dll;
    dll.insertToHead(10);
    dll.insertToHead(20);
    dll.print();
    int expected[] = { 20, 10 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, InsertToEnd) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.print();
    int expected[] = { 10, 20 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, Search) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.print();
    EXPECT_TRUE(dll.search(20));
    EXPECT_FALSE(dll.search(40));
}

TEST(DoublyLinkedListTest, Update) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.update(20, 25);
    dll.print();

    EXPECT_TRUE(dll.search(25));
    EXPECT_FALSE(dll.search(20));
}

TEST(DoublyLinkedListTest, InsertAtIndex) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(40);

    dll.insertAtIndex(30, 2);

    dll.print();

    int expected[] = { 10, 20, 30, 40 };
    int result[4] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, Delete) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.deleteData(20);

    dll.print();

    int expected[] = { 10, 30 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}



//****************** Q2 Test cases *******************
TEST(CircularLinkedListTest, EmptyList) {
    CircularLinkedList cll;
    EXPECT_TRUE(cll.isEmpty());
}

TEST(CircularLinkedListTest, InsertToEnd) {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);

    int expected[] = { 10, 20 };
    int result[2] = { 0 };

    cll.print();
    int i = 0;
    Node* current = cll.getHead();
    do {
        result[i++] = current->getData();
        current = current->getNext();
    } while (current != cll.getHead());

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(CircularLinkedListTest, Search) {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.print();
    EXPECT_TRUE(cll.search(20));
    EXPECT_FALSE(cll.search(40));
}

TEST(CircularLinkedListTest, Update) {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    cll.update(20, 25);

    cll.print();
    EXPECT_TRUE(cll.search(25));
    EXPECT_FALSE(cll.search(20));
}

TEST(CircularLinkedListTest, InsertAtIndex) {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(40);

    cll.insertAtIndex(30, 2);

    cll.print();

    int expected[] = { 10, 20, 30, 40 };
    int result[4] = { 0 };

    int i = 0;
    Node* current = cll.getHead();
    do {
        result[i++] = current->getData();
        current = current->getNext();
    } while (current != cll.getHead());

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(CircularLinkedListTest, Delete) {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    cll.deleteData(20);
    cll.print();
    int expected[] = { 10, 30 };
    int result[2] = { 0 };

    int i = 0;
    Node* current = cll.getHead();
    do {
        result[i++] = current->getData();
        current = current->getNext();
    } while (current != cll.getHead());

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}