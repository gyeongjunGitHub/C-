#include<stdio.h>
#include"CArr.h"


// ���ø� 
// typeName ��� class�� ��� ��
// �������� �ڷ����� ���� �� �ִ� �Լ��� Ʋ.
// ����� ���� ȣ������ ������ �Լ��� ���α׷� ���� �������� ����
// T�� �ڷ��� �ڸ�
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

	// �Լ� ���ø�.
	// Add�� �Լ��� �ƴ�. �Լ� ���ø�(Ʋ)�̴�.
	// �������� �ڷ����� ��� ������ �Լ� Ʋ.
	int i = Add<int>(10, 30);

	// Ŭ���� ���ø� 
	// �ڹ� ���׸� �̶� ����� �����ΰ� 
	// List<String> myList = new ArrayList(); �䷱���� String Ÿ���� �����Ѵ� ����Ʈ�̴�.
	// Ÿ���� ������ ������ ��û�ؾ� ���ø��� ���� Ŭ������ ������.

	// int Ÿ�� �����迭
	CArr<int> carr;

	// float Ÿ�� �����迭
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