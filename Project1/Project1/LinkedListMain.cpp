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



	// printf ���� ��ü�� C++��� �Լ�
	// �ٹٲ� end line -> endl
	int i = 100;

	// C�� printf -> cout
	std::cout << "�ȳ�" << i << std::endl;

	
	// C�� scanf_s -> cin
	int input = 0;
	std::cin >> input;

	return 0;
}