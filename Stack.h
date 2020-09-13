#pragma once
class Stack
{
	int max_size;
	int current_size;
	struct elem
	{
		char Data;
		elem* next;
	}*stack = new elem;
public:
	Stack(int size);
	void push(char Data);
	char pop();
	int getCurrentSize();
	~Stack();
};

