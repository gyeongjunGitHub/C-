#include<stdio.h>
#include<iostream>
#include"Arr.h"




int main()
{
	// �����迭
	int a = 10;

	//scanf_s("%d", &a);

	//int arr[a] = {}; �Ұ��� �޸��� ũ�⸦ �� ���� ����. �迭 ������ ������ ����� �� ����.

	//��ü
	myARR m;

	//�ʱ�ȭ
	InitArr(&m);

	//������ ����
	for (int i = 0; i < 10; i++)
	{
		PushData(&m, i);
	}

	for (int i = 0; i < m.count; i++)
	{
		printf("%d\n", m.pInt[i]);
	}
	
	//�޸� ����
	ReleaseArr(&m);
	return 0;
}
