#include<stdio.h>

typedef struct my_st {
	int a;
	float b;
}MYST;
int main()
{
	//����ü�� ������
	MYST s = {};
	
	MYST* pST = &s;


	// �� �Ʒ� �Ѵ� �Ȱ���
	(*pST).a = 100;
	(*pST).b = 100.11f;

	pST->a = 101;
	pST->b = 10.123123f;

	return 0;
}