#include<stdio.h>

struct st
{

};

class mySt
{
	// private, protected, public


private:
	int c;
	int a;

// 멤버 함수
public:
	void setInt(int i)
	{
		
		this->c = i; // this를 꼭 적어주지 않아도 된다. c = i와 동일
	}

	// 대입 연산자 
	// 만들어주지 않아도 자동으로 생성된다.
	// m1객체와 m2 객체가 있다.
	// m1=m2를 하면 m2의 필드 값들을 m1필드로 복사
	// 대입 연산자 외의 다른 연산자들은 직접 만들어 주어야한다.
	// [ operator= ] 대입연산자.
	// 반환타입 operator=(참조 객체 레퍼런스)
	mySt& operator =(const mySt& _Other)// 값을 참조하는 객체의 값은 변하면 안되므로 const iRef
	{
		a = _Other.a;
		c = _Other.c;

		// this는 주소타임 *this가 원본
		return *this;
	}

	

// 생성자
public:
	// 이니셜라이져, 진정한 초기화 객체가 생성되는 동시에 값 세팅
	mySt()
		: c(100)
		, a(20)
	{
	}

	// 소명자 객체가 사라질 때 호출
	~mySt()
	{
		// free(memory) 등.
	}

};

int main()
{
	// C++의 class

	mySt m;
	m.setInt(3);

	mySt m1;
	mySt m2;

	//대입연산자
	m1 = m2; // m

	{
		// 자료형& 변수명; 레퍼런스 변수 선언.

		// 포인터와 비교해 보자
		// 주소를 받아와 역참조
		int i = 10;
		int* p = &i;
		*p = 100;

		// 레퍼런스변수
		// i의 변수의 주소를 받아서 접근하여 i를 수정한다.
		// 포인터와 똑같이 동작한다.
		// 원본을 참조한다.
		// int* const p = i; 와 똑같다. 다른 변수의 주소값을 가질 수 없다.
		// 장점 : 짧다?, *을 통해 역참조를 할 필요가 없다.

		int& iRef = i; // int* const p = i; 동일.
		iRef = 100; // *i = 100; 동일.

		// const* int p = &i; -> 원본 값을 수정할 수 없다.

		// const int& iRefConst = i; 
		// const int* const p = &i; 둘다 똑같다. 다른 주소를 가질 수 없으며, 원본 값을 변경 할 수 없다.

	}

	return 0;
}