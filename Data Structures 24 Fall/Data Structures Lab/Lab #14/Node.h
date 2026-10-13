#pragma once

class Node
{
	int key;
	int value;
	Node* next;
public:

	Node(int x, int y)
	{
		key = x;
		value = y;
		next = nullptr;
	}

	void set_key(int x)
	{
		key = x;
	}
	void set_value(int y)
	{
		value = y;
	}

	int get_key()
	{
		return key;
	}
	int get_value()
	{
		return value;
	}
	void set_Next(Node* ptr)
	{
		next = ptr;
	}
	Node* get_Next()
	{
		return next;
	}
};