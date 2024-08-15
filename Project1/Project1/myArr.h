#pragma once
#include<iostream>

//가변 배열 선언
typedef struct MyArr {
	int*	pInt;
	int		count;
	int		maxCount;
}MyArr;


// 초기화 함수
void InitMyArr(MyArr* m);

// 해제 함수
void destroy(MyArr* m);

// 데이터 추가 함수
void pushData(MyArr* m, int data);

// 메모리 확장 함수
//void extendMemory(MyArr* m);

void BubbleSort(MyArr* m);
