#include "CArr.h"
#include<assert.h>
// new 키워드는 동적 할당
// 1. CArr 자료형 크기 만큼 메모리 할당
// 2. CArr 자료형 인걸 컴파일러가 인지하고 생성자를 통해 초기값 세팅까지
//CArr* cTest = new CArr;

// CArr 자료형을 확인하고 해당 클레스의 소멸자를 통해 삭제
//delete cTest;

// 스코프
CArr::CArr()
	// 멤버 변수들
	:m_pInt(nullptr)  //int* m_pInt;
	,m_iCount(0)
	,m_iMaxCount(2)
{
	// new 동적할당 키워드, C에서는 malloc
	m_pInt = new int[2]; // int 자료형 2개 크기 메모리 할당
}

CArr::~CArr()
{
	// int 자료형 일 때는 delete
	// int[] 자료형 일 때는 delete[]
	// 메모리 해제
	delete[] m_pInt;
}

void CArr::PushBack(int _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		//재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	m_pInt[m_iCount++] = _Data;
}

void CArr::resize(int _iResizeCount)
{
	// 늘리려는 사이즈가 maxCount 보다 작거나 같으면 예외 처리 (의미없음X)
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. resize size 만큼 동적 할당
	int* pNew = new int[_iResizeCount];

	// 2. 기존 데이터를 새로운 공간으로 복사
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. 기존 공간 메모리 해제
	delete[] m_pInt;

	// 4. 새로 할당된 공간 가르키기
	m_pInt = pNew;

	// 5. maxCount 변경
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int index)
{
	return m_pInt[index];
}
