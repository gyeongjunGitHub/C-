#include<stdio.h>
#include"CArr.h"

int main()
{
	CArr cTest;
	
	for (int i = 0; i < 10; i++)
	{
		cTest.PushBack(i);
	}

	cTest[9] = 123456;
	printf("%d\n", cTest[9]);

	return 0;
}