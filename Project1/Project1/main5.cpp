#include<stdio.h>

typedef struct my_st {
	int a;
	float b;
}MYST;
int main()
{
	//구조체와 포인터
	MYST s = {};
	
	MYST* pST = &s;


	// 위 아래 둘다 똑같음
	(*pST).a = 100;
	(*pST).b = 100.11f;

	pST->a = 101;
	pST->b = 10.123123f;

	return 0;
}