#include<stdio.h>
#include<iostream>
#include"Arr.h"




int main()
{
	// 가변배열
	int a = 10;

	//scanf_s("%d", &a);

	//int arr[a] = {}; 불가능 메모리의 크기를 알 수가 없다. 배열 개수는 변수를 사용할 수 없다.

	//객체
	myARR m;

	//초기화
	InitArr(&m);

	//데이터 삽입
	for (int i = 0; i < 10; i++)
	{
		PushData(&m, i);
	}

	for (int i = 0; i < m.count; i++)
	{
		printf("%d\n", m.pInt[i]);
	}
	
	//메모리 해제
	ReleaseArr(&m);
	return 0;
}
