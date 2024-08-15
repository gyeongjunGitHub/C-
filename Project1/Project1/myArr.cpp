#include "myArr.h"

void extendMemory(MyArr* m)
{
	//���� �޸� �Ҵ緮 2�� �����ؼ� ���� ����
	int* pNew = (int*)malloc(m->maxCount * 2 * sizeof(int));

	//�� ����
	for (int i = 0; i < m->count; i++)
	{
		pNew[i] = m->pInt[i];
	}

	//���� �޸� �ּ� ����
	free(m->pInt);

	//maxCount ����
	m->maxCount *= 2;

	//�ּ� ���Ҵ�
	m->pInt = pNew;
}
void InitMyArr(MyArr* m)
{
	//ó�� size�� int�� 2��
	m->pInt = (int*)malloc(sizeof(int) * 2);
	m->count = 0;
	m->maxCount = 2;
}
void destroy(MyArr* m)
{
	free(m->pInt);
	m->count = 0;
	m->maxCount = 0;
}
void pushData(MyArr* m, int data)
{
	if (m->count >= m->maxCount)
	{
		extendMemory(m);
	}

	m->pInt[m->count++] = data;
}




void printArr(MyArr* m)
{
	//�迭 �� ���
	printf("�迭 :");
	for (int i = 0; i < m->count; i++)
	{
		printf("%3d", m->pInt[i]);
	}
	printf("\n\n");
}
bool cycle(MyArr* m)
{
	bool check = false;
	for (int i = 0; i < m->count - 1; i++)
	{
		//�� ���ڰ� �� Ŭ ��� ��ġ �ٲٱ�
		if (m->pInt[i] > m->pInt[i + 1])
		{
			check = true;
			int temporaryInt = m->pInt[i + 1];
			m->pInt[i + 1] = m->pInt[i];
			m->pInt[i] = temporaryInt;
		}
	}
	return check;
}
void BubbleSort(MyArr* m)
{
	printArr(m);

	bool check = true;
	while (check)
	{
		check = cycle(m);
	}
	
	printArr(m);

}
