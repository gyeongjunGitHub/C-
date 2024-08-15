#include<iostream>
#include "Arr.h"



void InitArr(myARR* m)
{
	m->pInt = (int*)malloc(sizeof(int) * 2); //int �ڷ��� 2�� 8Byte�� �Ҵ��ϰڴ�.
	m->count = 0;
	m->maxCount = 2;
}
void ReleaseArr(myArr* m)
{
	free(m->pInt);
	m->count = 0;
	m->maxCount = 0;
}
// �޸� ���Ҵ� ó���� �˳��ϰ� �Ҵ��ϴ°� ����.
void Reallocate(myArr* m)
{
	// �޸� ���Ҵ� ����maxcount 2�� �Ҵ��� ����
	int* pNew = (int*)malloc(m->maxCount * 2 * sizeof(int));

	// ���� ������ �� �޸� �������� ����.
	for (int i = 0; i < m->count; i++)
	{
		pNew[i] = m->pInt[i];
	}

	// ���� �޸� ���� ����
	free(m->pInt);

	// ���ο� �޸� ���� �ּҸ� pInt�� �Ҵ�
	m->pInt = pNew;

	// maxCount 2�� ����
	m->maxCount *= 2;
}
void PushData(myArr* m, int data)
{
	// maxCount�� count ��
	if (m->count >= m->maxCount)
	{
		//���Ҵ�
		Reallocate(m);
	}
	
	// ������ �߰�
	m->pInt[m->count++] = data;
}
