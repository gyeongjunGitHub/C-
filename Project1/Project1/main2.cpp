#include<stdio.h>
#include "common.h"

// 1. 지역변수
// 2. 전역변수 - Data영역
// 3. 정적변수(static) - Data영역
// 4. 외부변수(extern) - Data영역

// 1. 스택영역(함수?)
// 2. 데이터영역
// 3. 읽기전용(코드, ROM);
// 4. 힙 영역

// 전역변수
int q = 0; //Data 영역 프로그램 시작할 때 만들어지고, 프로그램 종료시 사라짐


//분할 구현
//main2.cpp든 func.cpp든 어딘가에는 구현되어 있어야함
#include "func.h" // 실제 코드는 func.cpp에 구현되어 있음 LINK과정에서 연결

//분할 구현시 전역변수에서 어떤 문제가 생기냐?

//정적변수
//해당 파일 안에서만 유효
//다른 파일에 같은 이름의 변수가 있어도 ㄱㅊ
//Java랑 비슷
static int staticNum = 0;

//extern
//헤더 파일에서는 초기화 X, 이런 녀석이 존재한다.
//어떤 cpp파일이든 상관없이 LINK 시점에 반드시 선언 및 초기화가 되어있어야함
int shit;

void adsa()
{
	// 함수가 스택에서 해제 시
	// i가 사라지지 않음 
	// 프로그램 종료시 사라짐

	
	static int i = 0; //함수가 호출될 때 마다 i=0이 아님 최초 실행시에만 초기화.
	++i;
	if (i == 6) {
		printf("호출 된 횟수가 6");
	}


}


int main() 
{
	
	shit = 100;
	int result = Add(10, 20);
	/*adsa();
	adsa();
	adsa();
	adsa();
	adsa();
	adsa();*/



}