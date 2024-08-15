#include<stdio.h>
#include<iostream>
// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)

int main()
{
	//malloc()
	//동적 할당
	// 1. 런타임 중에 동적 메모리 할당 가능
	// 2. 사용자가 직접 관리해야함(해제)

	int* pInt = (int*)malloc(100); // 힙 영역에다가 100Byte를 할당 후 주소값 리턴, 반환 타입이 void*임. (int*)로 강제캐스팅

	*pInt; // 힙 메모리 영역 100Byte의 시작점.
	
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
		// free 메모리 해제
		free(pInt1);
	}
	return 0;
}