#include<vector> // �����迭 ǥ�� ���̺귯�� ���ø�
#include<list> // ������ ����Ʈ ǥ�� ���̺귯�� ���ø�
#include<iostream>

// std �ȿ� �����Ǿ� ����
using std::vector;
using std::list;

int main()
{
	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt[0] = 30;
	vecInt.data(); //�����迭 ���޸� �����ּ�
	vecInt.size(); //m_iCount
	vecInt.capacity(); // m_maxCount

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	// iterator
	// list ���ʿ� �����Ǿ� �ִ� Ŭ���� inner class;
	list<int>::iterator iter;

	iter = listInt.begin(); //list ���� �������߿� ù��° ��带 ����Ű���ִ�.

	// �����ʹ� �ƴ����� ������ operator�� ���� ������ ó�� ������ ���Ҵ�.
	int Data = *iter;

	std::cout << Data << std::endl;

	return 0;
}