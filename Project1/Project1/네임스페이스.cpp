#include<iostream>

namespace MySpace
{
	int exNum;
}
namespace OtherSpace
{
	int exNum;
}

// ���� �������� ��ġ�� �ʰ� ������̴�.
// std:: ���� ������! -> using namespace ����ϸ� �Ǳ� ��.
using namespace std;

// ���־��Ű��� �ֵ鸸 namespace�� ����
using std::cout; // cout�� ���ӽ����̽� ���� ���ڴ�!
using std::wcout; // ���ڿ� 2����Ʈ ¥��
using std::endl; // endl�� ���ӽ����̽� ���� ���ڴ�!

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
	// ���� �����̽�
	// �� �׷��� �̸� ����
	// �ٸ������ ���� ���� �̸��̶� ���� ���� �ִ�.
	// �׷��� ������ ���ӽ����̽� �ȿ� �����ϰ� ::�������� ���� ������ �� �ִ�.
	MySpace::exNum = 10;
	OtherSpace::exNum = 10;

	cout << "�ȳ�" << endl;
	
	//�ѱ� ����
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");


	EX ex;
	ex << 20;

	// �����ϰ� ������ �����ε��� ���ؼ� cout�� �����غ���
}