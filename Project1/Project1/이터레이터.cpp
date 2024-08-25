#include<vector> // 가변배열 표준 라이브러리 템플릿
#include<list> // 연결형 리스트 표준 라이브러리 템플릿
#include<iostream>
#include"CArr.h"

// std 안에 구현되어 있음
using std::vector;
using std::list;

int main()
{
	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt[0] = 30;
	vecInt.data(); //가변배열 힙메모리 시작주소
	vecInt.size(); //m_iCount
	vecInt.capacity(); // m_maxCount

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	// iterator
	// list 안쪽에 구현되어 있는 클래스 inner class;
	list<int>::iterator iter;
	vector<int>::iterator veciter = vecInt.begin(); // 벡터도 가능

	iter = listInt.begin(); //list 안의 데이터중에 첫번째 노드를 가리키고있다.

	// 포인터는 아니지만 연산자 operator을 통해 포인터 처럼 구현해 놓았다.
	int Data = *iter;
	*iter = 100;

	
	++iter; // 다음 데이터 
	Data = *iter;

	//std::cout << Data << std::endl;

	// 다른 자료형도 iterator가 구현되어 있다면 
	// 내부 구조를 잘 몰라도 iterator를 통해 동일하게 사용 할 수 있다.

	vecInt.erase(veciter); // 해당 인덱스를 삭제하는 함수 iterator를 인자로 넘김
	listInt.erase(iter); // 리스트도 동일

	// list 를 iterator을 통해서 순회
	
	for (iter = listInt.begin(); iter != listInt.end(); iter++)
	{
		// list.end(); 는 마지막 노드보다 하나 더 다음이다.
		// list.end(); 가 만약 마지막 노드라면 마지막 노드의 데이터를 출력 할 수 없다.
		std::cout << *iter << std::endl;
	}

	//내가만든 가변배명

	CArr<int> cArr;
	cArr.PushBack(33);
	CArr<int>::iterator myiter = cArr.begin();

	// *, (++, --)전위 후위, ==, != 구현해보기 
	

	return 0;
}