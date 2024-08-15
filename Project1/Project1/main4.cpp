#include<stdio.h>
#include<wchar.h>
#include<assert.h> // ���� ��� ����

// **************
// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)
// **************

unsigned int GetLength(const wchar_t* string)
{
	int i = 0;
	while (*(string + i) != '\0')
	{
		i++;
	}
	return i;
}
void MyStrCat(wchar_t* string1, unsigned int size, const wchar_t* string2)
{
	//������ üũ ����
	int string1_size = GetLength(string1);
	int string2_size = GetLength(string2);
	printf("%d, %d\n", string1_size, string2_size);
	printf("%d\n", string1_size+string2_size);

	
	if (string1_size + string2_size >= size - 1)//null���� ����  
	{
		assert(nullptr);
	}

	// string2_size + 1 �� �ϴ� ������ null����
	for (int i = 0; i < string2_size + 1; i++)
	{
		string1[string1_size + i] = string2[i];
	}

}
int MyStrCmp(const wchar_t* string1, const wchar_t* string2)
{
	int string1_size = GetLength(string1);
	int string2_size = GetLength(string2);

	printf("string1_size : %d\n", string1_size);
	printf("string2_size : %d\n", string2_size);
	
	//�� ���ڿ��� size�� ���� ���� ���
	//���ڿ��� �Ȱ�����
	//str1�� str2���� ª�� ��� return -1;
	//str1�� str2���� �� ��� return 1;

	int loop_count = string1_size;
	int result = 0;

	if (string1_size < string2_size)
	{
		loop_count = string1_size;
		result = -1;
	}
	else if (string1_size > string2_size)
	{
		loop_count = string2_size;
		result = 1;
	}
	for (int i = 0; i < loop_count; i++) 
	{
		if (string1[i] < string2[i]) {
			return -1;
		}
		else if (string1[i] > string2[i])
		{
			return 1;
		}
	}
	return result;
}

int main()
{
	//����
	wchar_t wc = 65; //wchar_t : 2Byte ���� �ڷ���, char 1Byte ���� �ڷ���.
	wchar_t a = L'a'; //�տ� �빮�� L��
	char c = 'a';

	// ****** //
	// ���ڿ� //
	// ****** //

	char cArr[5] = "abcd"; // ���ڿ� ���������� 'null', 0 �ʿ�
	wchar_t wcArr[10] = L"abvc";

	const char* pcArr = "abcdef";
	//pcArr[1] = 'z'; ���ڵ�� ���� �ȵ�
	// ROM(�ڵ�)���� �ȿ� �ۼ��Ǿ��ִ� abcdef���ڿ��� �ּҸ� ����
	// ���α׷� ���� ���߿� �ڵ尡 �ǽð����� �ٲ��? ���� �ȵ� readOnly �޸� ����
	// const Ű���带 ����ϵ��� �����Ϸ��� ���� ������ ���� ĳ�������� �����ϱ� ��
	 
	//pcArr[1] -> *(p + 1)
	


	char cc[10] = "abc�ѱ�"; // -> �ѱ��� 2Byte�� ��Ƽ����Ʈ �ý��ۿ����� ����� 1Byte�� ��Ÿ�� �ѱ��� 2Byte�̹Ƿ� char�ڷ��������� ��ĭ���� ���� ��� ���� ����

	wchar_t wcc[10] = L"abc�ѱ�"; // -> ������ ���̵����Ʈ ��� 2Byte
	
	int wccLen = wcslen(wcc); // ���ڿ��� ���̸� �˷��ִ� �Լ�


	int myLen = GetLength(wcc);


	
	printf("wccLen �� ���� : %d\n", myLen);

	//���ڿ� �̾���̱� wcscat_s(�̾���� ���� ���ڿ�, bufSize(�� ù��° ���� ���ڿ� size), �̾���� ���ڿ�);

	wchar_t myStr1[20] = L"abc";
	wchar_t myStr2[30] = L"aaaaaac";

	wcscat_s(myStr1, 20, myStr2);

	printf("11%ws\n", myStr1);

	//���� �̾���̱�
	MyStrCat(myStr1, 20, L"hello");
	printf("11111%ws\n", myStr1);

	//���ڿ� �� üũ wcscmp();
	//�� ���ڿ��� �Ϻ��� ������ return 0;
	//�� ���ڿ� abc������ �տ� ���� �쿭�� ������ return -1;
	//�ڿ� ���� �쿭�� ������ return 1;
	//���� �ܾ� ã�� ���� �����غ��� ��
	
	int result = MyStrCmp(L"abc", L"abca");
	printf("�� ��� : %d\n", result);
	


	return 0;
}