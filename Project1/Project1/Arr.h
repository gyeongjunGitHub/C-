#pragma once

//�����迭 ���� ����
typedef struct myArr 
{
	int*	pInt;
	int		count;
	int		maxCount;
}myARR;

//Ctrl + +Ű + . -> �Լ� ���� ���� ����Ű

//�ʱ�ȭ
void InitArr(myARR* m);

//�޸� ����
void ReleaseArr(myArr* m);

//�޸� ���� Ȯ��
//void Reallocate(myArr* m);
//main()���� �ҷ� �� ���� ������ ����� ������ ������Ͽ����� �ۼ����� �ʾƵ� �ȴ�.

//������ �߰� �Լ�
void PushData(myArr* m, int data);