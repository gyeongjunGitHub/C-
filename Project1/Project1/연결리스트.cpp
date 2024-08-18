#include<stdio.h>
#include"List.h"
int main()
{

	myList m;
	InitList(&m);

	pushFront(&m, 100);
	pushBack(&m, 200);
	pushFront(&m, 300);

	ReleaseList(&m);
	return 0;
}