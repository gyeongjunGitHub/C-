#include<stdio.h>

// #define 전처리
// 컴파일 전 단계에서 HUNGRY라는 구문을 찾아 1로 바꿔 준 뒤 컴파일 시작

//16진수로 표현 -> 앞에 0x 가 붙음
#define HUNGRY 1	// 0x1
#define TIRED  2    // 0x2
#define STATUS 4    // 0x4
#define AAAAAA 8    // 0x8
#define AAASSS 16   // 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800,

#define A1 0x1
#define A2 0x2
#define A3 0x4
#define A4 0x8

#define A5 0x10
#define A6 0x20
#define A7 0x40
#define A8 0x80

#define A9 0x100
#define A10 0x200
#define A11 0x400
#define A12 0x800


int Add(int a, int b);
int Fibonacci(int num);
int Fibonacci_re(int num);

void ex01(); //자료형
void ex02(); //실수형
void ex03();
void ex04(); //비트연산자
void ex05(); //함수
void ex06(); //재귀함수


int main() {
	// 자료형, 정수형
	//ex01 ();
	
	//실수형
	//ex02();

	// bool
	//ex03();

	// define
	// 비트연산자
	//ex04();

	//ex05();
	//int exName = 0;
	{
		int exName = 10;

		exName; // 지역변수가 전역변수 보다 우선순위가 높다.
	}

	// 지정 구문 주석 : Ctrl + K, C
	// 지정 구문 주석 해체 : Ctrl + K, U
	// Alt + Drag
	// 디버그 F5, 중단점 F9, 구문 한줄씩 수행 F10, 함수 진입 F11
	// 디버깅 중 종료 Shift F5

	//재귀함수
	//ex06();

	return 0;
}
void ex01() {
	// 단위 byte  1byte = 8bit
	// 정수형 : char(1), short(2), int(4), long(4), long long(8) ...
	// 실수형 : float(4), double(8)

	// 양수 음수 중 양수만 표현하겠다.
	unsigned int i = 0;

	// 음수만 표현하겠다.
	signed int j = 0;

	char c = 256; // 자료형 범위를 초과하면 0 -> 255 = 00000000 256 = 1 00000000 1이 삐져나와 나머지 8자리 0 이므로 0
	c = 0;
	c = -1;
	printf("%d", c);

	//2진수 양수 음수
	// 1 000 0000
	//MSB 최상위비트 부호비트
	// 1 + (-1)

	//   0 000 0001
	// + 1 111 1111
	//--------------
	// 1 0 000 0000
	//맨 앞의 1은 8자리 초과했으므로 없는 값
	// 0 000 0001 과 1 111 1111 을 더했을 때 0이 나오므로 
	// -1 = 1 111 1111 이다.

	//unsigned char c = 255; -> c = -1 이다

	// 2의 보수법 (음의 정수 찾기)
	// 0 -> 1로, 1 -> 0으로 바꾼 후 1을 더해준다.
}
void ex02() {
	//실수형

	// int i = 4 + 4.0;
	// 4.0 은 실수형임 -> 정수형 4로 형변환 후 연산

	//부동소수점
	// 부호비트 | 지수비트 | 가수비트
	// float 32bit 이므로 double보다 덜 자세함
	// double 64bit 이므로 float보다 더 자세하게 가능
	// 32bit 에서 1bit 부호비트 8bit 지수비트 23bit 가수비트
	// 정확한 값을 표현 못할 수도 있음
	
	// 정수는 정수, 실수는 실수끼리 연산하되, 쩔수 없을 경우 형변환 명시적으로
	float f = 10.25f + (float)20;

}
void ex03() {
	//bool 1Byte
	bool isTrue = true;
}
void ex04() {
	// 비트 연산자
	// <<, >> 좌 시프트 숫자 2배 증가, 우 시프트 1/2로 감소
	char c = 1;
	c <<= 3; //왼쪽으로 3번 시프트 2*2*2 8배 증가

	// 비트 곱 (&), 비트 합(|), XOR(^), 반전(~)
	// 상태 표현 시 주로 사용
	// 32bit 상태 32가지를 표현 할 수 있음
	unsigned int isStatus = 0;

	//배고플 상태를 만들겠다.
	isStatus |= HUNGRY;

	//tired 상태를 만들겠다.
	isStatus |= TIRED;


	//상태체크
	if (isStatus & HUNGRY) 
	{
		// 배고픔
	}
	if (isStatus & TIRED)
	{
		// 피곤함
	}

	//특정 자리만 비트 제거 XOR 사용
	isStatus &= ~HUNGRY; // 반전(~) 해주고 비트 곱(&)연산 수행

}
void ex05() {
	int result = Add(10, 20);
	printf("%d", result);
}
void ex06()
{
	int result = Fibonacci(8);
	printf("%d\n", result);

	//재귀 문제가 있음 너무 많이 호출함
	int result2 = Fibonacci_re(8);
	printf("%d", result2);
}


// 1 1 2 3 5 8 13 21 ...
int Fibonacci_re(int num) 
{
	if (num <= 2)
	{
		return 1;
	}

	return Fibonacci_re(num - 2) + Fibonacci_re(num - 1);

}
int Fibonacci(int num) {

	if(num <= 2)
	{
		return 1;
	}

	int firstNum = 1;
	int secondNum = 1;
	int sum = 0;

	for (int i = 0; i < num-2; i++) 
	{
		sum = firstNum + secondNum;
		firstNum = secondNum;
		secondNum = sum;
	}
	
	return sum;
}
int Add(int a, int b) 
{
	return a + b;
}