#pragma once

#include<assert.h>

// Ctrl + R + R 동일 이름 모두 바꾸기?
template<typename T>
class CArr
{

//필드
//사실 defalut 접근자는 private이다.
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	// 생성자
	CArr();

	// 소멸자
	~CArr();

	// pushBack 함수
	// template으로 바꾼 시점부터 어떤 자료형이든 다 받을 수 있다.
	// 크기가 큰 자료형을 받아오는 경우 pushBack 내부의 지역 변수로 값을 복사하여 배열에 저장하는 경우 비 효율적이다.
	// 따라서 참조 변수나 주소값을 받아오는게 좋다.
	void PushBack(const T& _Data);

	// resize 함수
	// 기존 C스타일로 만들었을 때와 다르게 resize함수를 단독으로 사용할 수 있게 바뀜
	// 기존 방식대로 100개의 데이터를 추가하려 한다면 2개 데이터를 집어넣고 다시 늘리고 또 데이터를 집어넣고 늘리고 반복. 성능 떨어짐 메모리 할당 삭제 반복.
	// 단독으로 호출시 한번에 100개 까지 size를 한번에 늘려 불필요한 과정이 사라져 성능 증가.
	void resize(int _iResizeCount);

	// 연산자 기능 추가
	// int num = cArr[3]; 을 가능하게 하기 위해
	// cArr[1] = 100; 도 가능하도록 int* 타입으로 선언
	// 하지만 반환 타입이 주소값이여서 *cArr[1] = 100; 이렇게 적어야함
	// 그래서 레퍼런스 변수 를 사용
	T& operator[](int index);

	int returnSize();
};

// new 키워드는 동적 할당
// 1. CArr 자료형 크기 만큼 메모리 할당
// 2. CArr 자료형 인걸 컴파일러가 인지하고 생성자를 통해 초기값 세팅까지
//CArr* cTest = new CArr;

// CArr 자료형을 확인하고 해당 클레스의 소멸자를 통해 삭제
//delete cTest;


// 중요사항
// 클레스 템플릿을 만들 때
// 템플릿의 함수 들은 cpp파일이 아니라 헤더 파일에 존재해야한다.


// 스코프
// 템플릿 생성자
template<typename T>
CArr<T>::CArr()
// 멤버 변수들
	:m_pData(nullptr)  //int* m_pInt;
	, m_iCount(0)
	, m_iMaxCount(2)
{
	// new 동적할당 키워드, C에서는 malloc
	m_pData = new T[2]; // T 자료형 2개 크기 메모리 할당
}


template<typename T>
CArr<T>::~CArr()
{
	// int 자료형 일 때는 delete
	// int[] 자료형 일 때는 delete[]
	// 메모리 해제
	delete[] m_pData;
}

template<typename T>
void CArr<T>::PushBack(const T& _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		//재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 늘리려는 사이즈가 maxCount 보다 작거나 같으면 예외 처리 (의미없음X)
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. resize size 만큼 동적 할당
	T* pNew = new T[_iResizeCount];

	// 2. 기존 데이터를 새로운 공간으로 복사
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간 메모리 해제
	delete[] m_pData;

	// 4. 새로 할당된 공간 가르키기
	m_pData = pNew;

	// 5. maxCount 변경
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int index)
{
	return m_pData[index];
}

template<typename T>
int CArr<T>::returnSize()
{
	return m_iCount;
}
