#include<vector> // �����迭 ǥ�� ���̺귯�� ���ø�
#include<list> // ������ ����Ʈ ǥ�� ���̺귯�� ���ø�
#include<iostream>
#include"CArr.h"

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
	vector<int>::iterator veciter = vecInt.begin(); // ���͵� ����

	iter = listInt.begin(); //list ���� �������߿� ù��° ��带 ����Ű���ִ�.

	// �����ʹ� �ƴ����� ������ operator�� ���� ������ ó�� ������ ���Ҵ�.
	int Data = *iter;
	*iter = 100;

	
	++iter; // ���� ������ 
	Data = *iter;

	//std::cout << Data << std::endl;

	// �ٸ� �ڷ����� iterator�� �����Ǿ� �ִٸ� 
	// ���� ������ �� ���� iterator�� ���� �����ϰ� ��� �� �� �ִ�.

	vecInt.erase(veciter); // �ش� �ε����� �����ϴ� �Լ� iterator�� ���ڷ� �ѱ�
	listInt.erase(iter); // ����Ʈ�� ����

	// list �� iterator�� ���ؼ� ��ȸ
	
	for (iter = listInt.begin(); iter != listInt.end(); iter++)
	{
		// list.end(); �� ������ ��庸�� �ϳ� �� �����̴�.
		// list.end(); �� ���� ������ ����� ������ ����� �����͸� ��� �� �� ����.
		std::cout << *iter << std::endl;
	}

	//�������� �������

	CArr<int> cArr;
	cArr.PushBack(33);
	CArr<int>::iterator myiter = cArr.begin();

	// *, (++, --)���� ����, ==, != �����غ��� 
	

	return 0;
}