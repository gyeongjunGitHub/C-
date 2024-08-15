#pragma once

//가변배열 형태 선언
typedef struct myArr 
{
	int*	pInt;
	int		count;
	int		maxCount;
}myARR;

//Ctrl + +키 + . -> 함수 원형 생성 단축키

//초기화
void InitArr(myARR* m);

//메모리 해제
void ReleaseArr(myArr* m);

//메모리 공간 확장
//void Reallocate(myArr* m);
//main()에서 불러 쓸 수도 있으니 숨기고 싶으면 헤더파일에서는 작성하지 않아도 된다.

//데이터 추가 함수
void PushData(myArr* m, int data);