#pragma once

class CArr
{

//�ʵ�
//��� defalut �����ڴ� private�̴�.
private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	// ������
	CArr();

	// �Ҹ���
	~CArr();

	// pushBack �Լ�
	void PushBack(int _Data);

	// resize �Լ�
	// ���� C��Ÿ�Ϸ� ������� ���� �ٸ��� resize�Լ��� �ܵ����� ����� �� �ְ� �ٲ�
	// ���� ��Ĵ�� 100���� �����͸� �߰��Ϸ� �Ѵٸ� 2�� �����͸� ����ְ� �ٽ� �ø��� �� �����͸� ����ְ� �ø��� �ݺ�. ���� ������ �޸� �Ҵ� ���� �ݺ�.
	// �ܵ����� ȣ��� �ѹ��� 100�� ���� size�� �ѹ��� �÷� ���ʿ��� ������ ����� ���� ����.
	void resize(int _iResizeCount);

	// ������ ��� �߰�
	// int num = cArr[3]; �� �����ϰ� �ϱ� ����
	// cArr[1] = 100; �� �����ϵ��� int* Ÿ������ ����
	// ������ ��ȯ Ÿ���� �ּҰ��̿��� *cArr[1] = 100; �̷��� �������
	// �׷��� ���۷��� ���� �� ���
	int& operator[](int index);
};