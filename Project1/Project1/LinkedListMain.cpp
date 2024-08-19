#include<stdio.h>
#include"LinkedList.h"
int main()
{
	LinkedList<int> myList;

	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}
	for (int i = 10; i < 20; i++)
	{
		myList.push_front(i);
	}

	return 0;
}