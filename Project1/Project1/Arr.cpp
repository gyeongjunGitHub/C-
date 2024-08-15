#include<iostream>
#include "Arr.h"



void InitArr(myARR* m)
{
	m->pInt = (int*)malloc(sizeof(int) * 2); //int 자료형 2개 8Byte를 할당하겠다.
	m->count = 0;
	m->maxCount = 2;
}
void ReleaseArr(myArr* m)
{
	free(m->pInt);
	m->count = 0;
	m->maxCount = 0;
}
// 메모리 재할당 처음에 넉넉하게 할당하는게 좋다.
void Reallocate(myArr* m)
{
	// 메모리 재할당 기존maxcount 2로 할당할 예정
	int* pNew = (int*)malloc(m->maxCount * 2 * sizeof(int));

	// 기존 데이터 새 메모리 공간으로 복사.
	for (int i = 0; i < m->count; i++)
	{
		pNew[i] = m->pInt[i];
	}

	// 기존 메모리 공간 해제
	free(m->pInt);

	// 새로운 메모리 공간 주소를 pInt에 할당
	m->pInt = pNew;

	// maxCount 2배 증가
	m->maxCount *= 2;
}
void PushData(myArr* m, int data)
{
	// maxCount와 count 비교
	if (m->count >= m->maxCount)
	{
		//재할당
		Reallocate(m);
	}
	
	// 데이터 추가
	m->pInt[m->count++] = data;
}
