#pragma once

class CArr
{

//필드
//사실 defalut 접근자는 private이다.
private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	// 생성자
	CArr();

	// 소멸자
	~CArr();

	// pushBack 함수
	void PushBack(int _Data);

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
	int& operator[](int index);
};