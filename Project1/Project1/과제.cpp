#include<stdio.h>
#include"myArr.h"


int main()
{
	// 1. �����迭 ����

	MyArr m;
	InitMyArr(&m);

	int myNum[10] = { 7,4,5,1,3,2,6,8,9,0 };
	for (int i = 0; i < 10; i++)
	{
		pushData(&m, myNum[i]);
	}
	BubbleSort(&m);

	destroy(&m);

	// 2. �����迭 �ȿ� ���� ������ ��������


	return 0;
}