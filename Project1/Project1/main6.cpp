#include<stdio.h>
#include<iostream>
// �޸� ����
// ����
// ������
// ROM
// �� ����(�����Ҵ�)

int main()
{
	//malloc()
	//���� �Ҵ�
	// 1. ��Ÿ�� �߿� ���� �޸� �Ҵ� ����
	// 2. ����ڰ� ���� �����ؾ���(����)

	int* pInt = (int*)malloc(100); // �� �������ٰ� 100Byte�� �Ҵ� �� �ּҰ� ����, ��ȯ Ÿ���� void*��. (int*)�� ����ĳ����

	*pInt; // �� �޸� ���� 100Byte�� ������.
	
	free(pInt);


	int iInput = 0;
	scanf_s("%d", &iInput);

	int* pInt1 = nullptr;

	if (iInput == 100)
	{
		//
		pInt1 = (int*)malloc(100);
	}

	if (pInt1 != nullptr)
	{
		// free �޸� ����
		free(pInt1);
	}
	return 0;
}