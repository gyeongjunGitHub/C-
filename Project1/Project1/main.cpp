#include<stdio.h>

// #define ��ó��
// ������ �� �ܰ迡�� HUNGRY��� ������ ã�� 1�� �ٲ� �� �� ������ ����

//16������ ǥ�� -> �տ� 0x �� ����
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

void ex01(); //�ڷ���
void ex02(); //�Ǽ���
void ex03();
void ex04(); //��Ʈ������
void ex05(); //�Լ�
void ex06(); //����Լ�


int main() {
	// �ڷ���, ������
	//ex01 ();
	
	//�Ǽ���
	//ex02();

	// bool
	//ex03();

	// define
	// ��Ʈ������
	//ex04();

	//ex05();
	//int exName = 0;
	{
		int exName = 10;

		exName; // ���������� �������� ���� �켱������ ����.
	}

	// ���� ���� �ּ� : Ctrl + K, C
	// ���� ���� �ּ� ��ü : Ctrl + K, U
	// Alt + Drag
	// ����� F5, �ߴ��� F9, ���� ���پ� ���� F10, �Լ� ���� F11
	// ����� �� ���� Shift F5

	//����Լ�
	//ex06();

	return 0;
}
void ex01() {
	// ���� byte  1byte = 8bit
	// ������ : char(1), short(2), int(4), long(4), long long(8) ...
	// �Ǽ��� : float(4), double(8)

	// ��� ���� �� ����� ǥ���ϰڴ�.
	unsigned int i = 0;

	// ������ ǥ���ϰڴ�.
	signed int j = 0;

	char c = 256; // �ڷ��� ������ �ʰ��ϸ� 0 -> 255 = 00000000 256 = 1 00000000 1�� �������� ������ 8�ڸ� 0 �̹Ƿ� 0
	c = 0;
	c = -1;
	printf("%d", c);

	//2���� ��� ����
	// 1 000 0000
	//MSB �ֻ�����Ʈ ��ȣ��Ʈ
	// 1 + (-1)

	//   0 000 0001
	// + 1 111 1111
	//--------------
	// 1 0 000 0000
	//�� ���� 1�� 8�ڸ� �ʰ������Ƿ� ���� ��
	// 0 000 0001 �� 1 111 1111 �� ������ �� 0�� �����Ƿ� 
	// -1 = 1 111 1111 �̴�.

	//unsigned char c = 255; -> c = -1 �̴�

	// 2�� ������ (���� ���� ã��)
	// 0 -> 1��, 1 -> 0���� �ٲ� �� 1�� �����ش�.
}
void ex02() {
	//�Ǽ���

	// int i = 4 + 4.0;
	// 4.0 �� �Ǽ����� -> ������ 4�� ����ȯ �� ����

	//�ε��Ҽ���
	// ��ȣ��Ʈ | ������Ʈ | ������Ʈ
	// float 32bit �̹Ƿ� double���� �� �ڼ���
	// double 64bit �̹Ƿ� float���� �� �ڼ��ϰ� ����
	// 32bit ���� 1bit ��ȣ��Ʈ 8bit ������Ʈ 23bit ������Ʈ
	// ��Ȯ�� ���� ǥ�� ���� ���� ����
	
	// ������ ����, �Ǽ��� �Ǽ����� �����ϵ�, ¿�� ���� ��� ����ȯ ���������
	float f = 10.25f + (float)20;

}
void ex03() {
	//bool 1Byte
	bool isTrue = true;
}
void ex04() {
	// ��Ʈ ������
	// <<, >> �� ����Ʈ ���� 2�� ����, �� ����Ʈ 1/2�� ����
	char c = 1;
	c <<= 3; //�������� 3�� ����Ʈ 2*2*2 8�� ����

	// ��Ʈ �� (&), ��Ʈ ��(|), XOR(^), ����(~)
	// ���� ǥ�� �� �ַ� ���
	// 32bit ���� 32������ ǥ�� �� �� ����
	unsigned int isStatus = 0;

	//����� ���¸� ����ڴ�.
	isStatus |= HUNGRY;

	//tired ���¸� ����ڴ�.
	isStatus |= TIRED;


	//����üũ
	if (isStatus & HUNGRY) 
	{
		// �����
	}
	if (isStatus & TIRED)
	{
		// �ǰ���
	}

	//Ư�� �ڸ��� ��Ʈ ���� XOR ���
	isStatus &= ~HUNGRY; // ����(~) ���ְ� ��Ʈ ��(&)���� ����

}
void ex05() {
	int result = Add(10, 20);
	printf("%d", result);
}
void ex06()
{
	int result = Fibonacci(8);
	printf("%d\n", result);

	//��� ������ ���� �ʹ� ���� ȣ����
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