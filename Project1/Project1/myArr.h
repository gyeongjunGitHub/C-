#pragma once
#include<iostream>

//���� �迭 ����
typedef struct MyArr {
	int*	pInt;
	int		count;
	int		maxCount;
}MyArr;


// �ʱ�ȭ �Լ�
void InitMyArr(MyArr* m);

// ���� �Լ�
void destroy(MyArr* m);

// ������ �߰� �Լ�
void pushData(MyArr* m, int data);

// �޸� Ȯ�� �Լ�
//void extendMemory(MyArr* m);

void BubbleSort(MyArr* m);
