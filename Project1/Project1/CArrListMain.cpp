#include<stdio.h>
#include"CArr.h"


// 템플릿 
// typeName 대신 class를 적어도 됨
// 여러가지 자료형을 받을 수 있느 함수의 틀.
// 만들어 놓고 호출하지 않으면 함수는 프로그램 내에 존재하지 않음
// T는 자료형 자리
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	//CArr cTest;

	//cTest[9] = 123456;
	//printf("%d\n", cTest[9]);

	// 함수 템플릿.
	// Add는 함수가 아님. 함수 템플릿(틀)이다.
	// 여러가지 자료형이 사용 가능한 함수 틀.
	int i = Add<int>(10, 30);

	// 클레스 템플릿 
	// 자바 제네릭 이랑 비슷한 느낌인걸 
	// List<String> myList = new ArrayList(); 요런느낌 String 타임을 저장한느 리스트이다.
	// 타입이 정해진 버전을 요청해야 템플릿을 통해 클래스가 생성됨.

	// int 타입 가변배열
	CArr<int> carr;

	// float 타입 가변배열
	CArr<float> carrf;

	carr.PushBack(10);
	carr.PushBack(20);
	carr.PushBack(30);

	for (int i = 0; i < carr.returnSize(); i++)
	{
		printf("%d\n", carr[i]);
	}

	return 0;
}