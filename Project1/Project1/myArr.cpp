#include "myArr.h"

void extendMemory(MyArr* m)
{
	//기존 메모리 할당량 2배 증가해서 새로 만듦
	int* pNew = (int*)malloc(m->maxCount * 2 * sizeof(int));

	//값 복사
	for (int i = 0; i < m->count; i++)
	{
		pNew[i] = m->pInt[i];
	}

	//기존 메모리 주소 해제
	free(m->pInt);

	//maxCount 증가
	m->maxCount *= 2;

	//주소 재할당
	m->pInt = pNew;
}
void InitMyArr(MyArr* m)
{
	//처음 size는 int형 2개
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
	//배열 값 출력
	printf("배열 :");
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
		//앞 숫자가 더 클 경우 위치 바꾸기
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
