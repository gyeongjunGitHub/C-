#include<stdio.h>

void ex01(const int* exNum);
int main()
{
	//������

	int i = 0;
	int* p;
	p = &i;

	char* pChar = nullptr; //nullptr -> �ƹ��͵� ���� 0

	//������ ���� ��ü�� ũ��� �ڷ����� ������� �����ϴ�.
	//64bit �ü�������� ������ ���� ũ��� 8Byte�̴�. 32bit -> 4Byte

	// const -> ���
	// r-value : ���
	// l-value : ��� �ƴ� ��

	const int i1 = 100; // i1�� ���

	int* p1 = (int*) & i1;

	*p1 = 200;



	// ========================== //
	// const ������ ��� �� 2���� //
	// ========================== //
	
	// 1. const ������ : ������ ������ ����Ű�� �ִ� ���� ���� �� �� ����. �������� ��� ����. ������ �����Ͽ� ���� �����ϴ� ������ ����
	int a = 0; 
	const int* pInt = &a; // *pInt = 100; �Ұ���
	a = 100; //����.

	// 2. ������ const : ������ ���� ��ü�� ���ȭ ��.
	int b = 0;
	int* const p2Int = &a; // p2Int = &a;�Ұ���
	

	const int* const p3Int = nullptr; // ������ ���� ��ü ���ȭ, ������ ������ ����Ű�� �� ���ȭ.

	int const* p4Int = nullptr; // -> 1��. �� �ش� ��������
	

	// ��뷮 �����Ϳ��� ���� ������ �� ����.
	// �ּҰ��� �ָ� �ٸ� �Լ����� �������� �ʾƵ� �ȴ�.
	// �д°� �������� ���� �����ϴ� ���� ������ �ʴ´�.
	// const Ű���带 ����ϸ� ����. (const int* exNum)

	int exNum = 1000;
	ex01(&exNum); // ����Ű Ctrl + Shift + Space �Լ� ���� ���


	// =========== //
	// void ������ //
	// =========== //
	// �������� ���� ���� �� � ���·� ������ ������ ���� ������ ���� �̴�.
	// ������ �ʾұ� ������ int, float, double, long long �� � �ڷ����� ������ �� ���� �� �ִ�.
	// ������ �����ؼ� � �ڷ������� �о������ �������� �ʾұ� ������
	// * �� �����Ͽ� ���� ���� �� ����.
	// int* p1 = &a; -> p1++; �ּ�++ ������ ���� �� �� ����. ex) int* �� p++ �� 4Byte�� ���� void�� �������� �ʾ����Ƿ� �Ұ���.

	int aa = 0;
	float bb = 0.f;
	double cc = 0;

	void* pVoid = nullptr; 

	pVoid = &aa;
	pVoid = &bb;
	pVoid = &cc;

	

}
void ex01(const int* exNum)
{
	//exNum = 100; �Ұ���.
	int* pInt = (int*)exNum; // �̷��� �ؼ� ���� �ٲ���� �� ������ �����ϱ� ��.;;

	// ���� const Ű����� �������� �� �ƴϰ� �Լ� �ۼ����� �ǵ��� �����ִ� Ű���� ����
	// �ǵ� : �� ���� �ּҿ� �����Ͽ� ���� ��ȸ������. ���� ���������� �ʰڴ�.
}