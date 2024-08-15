#include<stdio.h>
#include<wchar.h>
#include<assert.h> // 에러 출력 가능

// **************
// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)
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
	//사이즈 체크 먼저
	int string1_size = GetLength(string1);
	int string2_size = GetLength(string2);
	printf("%d, %d\n", string1_size, string2_size);
	printf("%d\n", string1_size+string2_size);

	
	if (string1_size + string2_size >= size - 1)//null문자 까지  
	{
		assert(nullptr);
	}

	// string2_size + 1 을 하는 이유는 null포함
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
	
	//두 문자열의 size가 같지 않을 경우
	//문자열이 똑같은데
	//str1이 str2보다 짧을 경우 return -1;
	//str1이 str2보다 길 경우 return 1;

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
	//문자
	wchar_t wc = 65; //wchar_t : 2Byte 문자 자료형, char 1Byte 문자 자료형.
	wchar_t a = L'a'; //앞에 대문자 L씀
	char c = 'a';

	// ****** //
	// 문자열 //
	// ****** //

	char cArr[5] = "abcd"; // 문자열 마지막에는 'null', 0 필요
	wchar_t wcArr[10] = L"abvc";

	const char* pcArr = "abcdef";
	//pcArr[1] = 'z'; 이코드는 말이 안됨
	// ROM(코드)영역 안에 작성되어있는 abcdef문자열의 주소를 참조
	// 프로그램 실행 도중에 코드가 실시간으로 바뀐다? 말이 안됨 readOnly 메모리 영역
	// const 키워드를 사용하도록 컴파일러가 막음 하지만 강제 캐스팅으로 가능하긴 함
	 
	//pcArr[1] -> *(p + 1)
	


	char cc[10] = "abc한글"; // -> 한글을 2Byte임 멀티바이트 시스템에서는 영어는 1Byte로 나타냄 한글은 2Byte이므로 char자료형에서는 두칸차지 거의 사용 하지 않음

	wchar_t wcc[10] = L"abc한글"; // -> 때문에 와이드바이트 사용 2Byte
	
	int wccLen = wcslen(wcc); // 문자열의 길이를 알려주는 함수


	int myLen = GetLength(wcc);


	
	printf("wccLen 의 길이 : %d\n", myLen);

	//문자열 이어붙이기 wcscat_s(이어붙임 당할 문자열, bufSize(맨 첫번째 인자 문자열 size), 이어붙일 문자열);

	wchar_t myStr1[20] = L"abc";
	wchar_t myStr2[30] = L"aaaaaac";

	wcscat_s(myStr1, 20, myStr2);

	printf("11%ws\n", myStr1);

	//직접 이어붙이기
	MyStrCat(myStr1, 20, L"hello");
	printf("11111%ws\n", myStr1);

	//문자열 비교 체크 wcscmp();
	//두 문자열이 완벽히 같으면 return 0;
	//두 문자열 abc순으로 앞에 것이 우열이 높으면 return -1;
	//뒤에 것이 우열이 높으면 return 1;
	//사전 단어 찾는 순서 생각해보면 됨
	
	int result = MyStrCmp(L"abc", L"abca");
	printf("비교 결과 : %d\n", result);
	


	return 0;
}