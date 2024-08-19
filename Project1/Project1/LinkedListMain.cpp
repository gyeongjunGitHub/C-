#include<stdio.h>
#include"LinkedList.h"
#include<iostream>
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



	// printf 문을 대체할 C++출력 함수
	// 줄바꿈 end line -> endl
	int i = 100;

	// C의 printf -> cout
	std::cout << "안녕" << i << std::endl;

	
	// C의 scanf_s -> cin
	int input = 0;
	std::cin >> input;

	return 0;
}