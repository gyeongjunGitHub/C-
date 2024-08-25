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

	class iterator; //전방 선언
	iterator begin();
	iterator end();

	// innerClass iterator
	// CArr 과 innerClass로 만든 iterator는 별개이다.
	// CArr 16Byte iterator m_i 의 크기 포함 X.
	// innerCalss는 상위 클래스의 private 필드에 접근할 수 있다.
	class iterator
	{
	private:	
		CArr* m_pArr;		// 가변배열의 주소
		T*		m_pData;	// 데이터의 처음 시작주소
		int		m_iIdx;		// 인덱스 값
		
	public:
		T& operator *()
		{
			// 기존에 이터레이터가 가지고 있던 주소는
			// 가변배열이 메모리 재할당 시 가변배열의 주소가 달라지기 때문에 이터레이터로 값을 참조하면 기존주소의 메모리는 해재되었기 때문에 쓸모없다.
			// 또는 end iterator일 경우
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}
			return m_pData[m_iIdx];
		}
		bool operator == (const iterator& _otheriter)
		{
			if (this->m_pArr == _otheriter.m_pArr && this->m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		// 전위 & 후위

		// 전위
		iterator& operator ++ ()
		{
			// end iterator 일 경우.
			// iterator의 주소값 변경 m_pData != m_pArr->m_pData 일 경우
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}

			// iterator 가 마지막 데이터를 가리키고있다.
			if (m_iIdx == m_pArr->returnSize() - 1)
			{
				m_iIdx = -1;
			}
			else
			{
				this->m_iIdx++;
			}

			return *this;
		}
		iterator& operator -- ()
		{
			return *this;
		}

		// 후위
		// 반환타입은 복사본
		// 호출 시점이 늦어지거나 하지 않는다.
		iterator operator ++(int)//아무의미없는 int 그냥 이렇게 쓰면 후위연산자로인식한다
		{

		}

	public:
		iterator() // 생성자
			:m_pArr(nullptr)
			,m_pData(nullptr)
			,m_iIdx(-1)
		{

		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			:m_pArr(_pArr)
			,m_pData(_pData)
			,m_iIdx(_iIdx)
		{
		}
		~iterator()
		{
		}// 소멸자
	};
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

template<typename T>
//        여기까지 반환타입| 
// 반환타입이 이너클레스인 경우 typename을 붙여주어야 한다.
typename CArr<T>::iterator CArr<T>::begin()
{
	if (this->m_iCount == 0)
	{
		return iterator(this, this->m_pData, -1); // 데이터가 없는 경우 begin() == end(); -1을 end()로 볼 예정
	}
	// 시작을 가리키는 이터레이터를 반환해줌
	return iterator(this, this->m_pData, 0); // 임시객체 변수명 필요없음.
}

template<typename T>
//        여기까지 반환타입| 
// 반환타입이 이너클레스인 경우 typename을 붙여주어야 한다.
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, this->m_pData, -1); // 임시객체 변수명 필요없음.
}

