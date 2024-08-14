#include<stdio.h>

void ex01(const int* exNum);
int main()
{
	//포인터

	int i = 0;
	int* p;
	p = &i;

	char* pChar = nullptr; //nullptr -> 아무것도 없다 0

	//포인터 변수 자체의 크기는 자료형과 상관없이 동일하다.
	//64bit 운영체제에서의 포인터 변수 크기는 8Byte이다. 32bit -> 4Byte

	// const -> 상수
	// r-value : 상수
	// l-value : 상수 아닌 수

	const int i1 = 100; // i1은 상수

	int* p1 = (int*) & i1;

	*p1 = 200;



	// ========================== //
	// const 포인터 사용 법 2가지 //
	// ========================== //
	
	// 1. const 포인터 : 포인터 변수가 가르키고 있는 값을 변경 할 수 없음. 포인터의 기능 제한. 원본에 접근하여 값을 변경하는 행위를 제한
	int a = 0; 
	const int* pInt = &a; // *pInt = 100; 불가능
	a = 100; //가능.

	// 2. 포인터 const : 포인터 변수 자체가 상수화 됨.
	int b = 0;
	int* const p2Int = &a; // p2Int = &a;불가능
	

	const int* const p3Int = nullptr; // 포인터 변수 자체 상수화, 포인터 변수가 가리키는 값 상수화.

	int const* p4Int = nullptr; // -> 1번. 에 해당 그지같네
	

	// 대용량 데이터여서 값을 복제할 수 없다.
	// 주소값을 주면 다른 함수에서 복제하지 않아도 된다.
	// 읽는건 괜찮은데 값을 변형하는 것을 원하지 않는다.
	// const 키워드를 사용하면 좋다. (const int* exNum)

	int exNum = 1000;
	ex01(&exNum); // 단축키 Ctrl + Shift + Space 함수 원형 출력


	// =========== //
	// void 포인터 //
	// =========== //
	// 원본으로 접근 했을 때 어떤 형태로 읽을지 정하지 않은 포인터 변수 이다.
	// 정하지 않았기 때문에 int, float, double, long long 등 어떤 자료형의 변수라도 다 받을 수 있다.
	// 하지만 접근해서 어떤 자료형으로 읽어들일지 정해지지 않았기 때문에
	// * 로 접근하여 값을 읽을 수 없다.
	// int* p1 = &a; -> p1++; 주소++ 연산을 수행 할 수 없다. ex) int* 는 p++ 시 4Byte씩 증가 void는 정해지지 않았으므로 불가능.

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
	//exNum = 100; 불가능.
	int* pInt = (int*)exNum; // 이렇게 해서 강제 바꿔버려 값 변경이 가능하긴 함.;;

	// 따라서 const 키워드는 절대적인 건 아니고 함수 작성자의 의도를 보여주는 키워드 정도
	// 의도 : 이 값의 주소에 접근하여 값을 조회하지만. 값을 변경하지는 않겠다.
}