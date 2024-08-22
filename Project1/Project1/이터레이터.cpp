#include<vector> // 가변배열 표준 라이브러리 템플릿
#include<list> // 연결형 리스트 표준 라이브러리 템플릿
#include<iostream>

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

	iter = listInt.begin(); //list 안의 데이터중에 첫번째 노드를 가리키고있다.

	// 포인터는 아니지만 연산자 operator을 통해 포인터 처럼 구현해 놓았다.
	int Data = *iter;

	std::cout << Data << std::endl;

	return 0;
}