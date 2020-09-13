#include <iostream>
#include <Windows.h>
#include <process.h>
#include <conio.h>
#include "Stack.h"

using std::cout;
using std::cin;
using std::endl;

CRITICAL_SECTION cs;

void Add_items(void* stack)
{
	Stack& st = *(Stack*)stack;
	std::string Text;
	cout << "Enter text: ";
	cin >> Text;
	EnterCriticalSection(&cs);
	for (char l : Text)
	{
		st.push(l);
	}
	LeaveCriticalSection(&cs);
	_endthread();
}

void PrintAndEmpty(void* stack)
{

	Stack& st = *(Stack*)stack;
	cout << "Text: ";
	EnterCriticalSection(&cs);
	while (st.getCurrentSize() != 0)
	{
		cout << st.pop();
	}
	cout << endl;
	LeaveCriticalSection(&cs);
	_endthread();
}

void Menu(Stack& stack)
{
	//cout << _getch() << endl;
	int choice;
	bool stop = false;
	system("cls");
	cout << "1) Add item" << endl
		 << "2) Delete item" << endl
		 << "3) Exit" << endl;
	while (!stop)
	{
		cin>>choice;
		try
		{
			switch (choice)
			{
			case 1:
				_beginthread(Add_items, 0, (void*)&stack);
				Sleep(10000);
				break;
			case 2:
				_beginthread(PrintAndEmpty, 0, (void*)&stack);
				Sleep(1000);
				break;
			case 3:
				stop = true;
				break;
			default:
				cout << "Incorect input" << endl;
			}
		}
		catch (const char* Exception)
		{
			cout << Exception << endl;
		}

	}
	
}

int main()
{
	InitializeCriticalSection(&cs);
	int StackSize;
	cout << "Enter the stack size: ";
	cin >> StackSize;
	Stack stack(StackSize);
	Menu(stack);
	DeleteCriticalSection(&cs);
	return 0;
}