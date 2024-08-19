#include<iostream>

namespace MySpace
{
	int exNum;
}
namespace OtherSpace
{
	int exNum;
}

// 나는 변수명이 겹치지 않게 만들것이다.
// std:: 쓰기 귀찮다! -> using namespace 사용하면 되긴 함.
using namespace std;

// 자주쓸거같은 애들만 namespace를 해제
using std::cout; // cout만 네임스페이스 없이 쓰겠다!
using std::wcout; // 문자열 2바이트 짜리
using std::endl; // endl만 네임스페이스 없이 쓰겠다!

class EX 
{
public:
	EX& operator <<(int _idata)
	{
		printf("%d", _idata);
		return *this;
	}
};
int main()
{
	// 네임 스페이스
	// 말 그래도 이름 공간
	// 다른사람이 지은 변수 이름이랑 같은 수도 있다.
	// 그렇기 때문에 네임스페이스 안에 선언하고 ::스코프를 통해 접근할 수 있다.
	MySpace::exNum = 10;
	OtherSpace::exNum = 10;

	cout << "안녕" << endl;
	
	//한글 설정
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");


	EX ex;
	ex << 20;

	// 간단하게 연산자 오버로딩을 통해서 cout을 구현해보자
}