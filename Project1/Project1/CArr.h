#pragma once

#include<assert.h>

// Ctrl + R + R ���� �̸� ��� �ٲٱ�?
template<typename T>
class CArr
{

//�ʵ�
//��� defalut �����ڴ� private�̴�.
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	// ������
	CArr();

	// �Ҹ���
	~CArr();

	// pushBack �Լ�
	// template���� �ٲ� �������� � �ڷ����̵� �� ���� �� �ִ�.
	// ũ�Ⱑ ū �ڷ����� �޾ƿ��� ��� pushBack ������ ���� ������ ���� �����Ͽ� �迭�� �����ϴ� ��� �� ȿ�����̴�.
	// ���� ���� ������ �ּҰ��� �޾ƿ��°� ����.
	void PushBack(const T& _Data);

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
	T& operator[](int index);

	int returnSize();
};

// new Ű����� ���� �Ҵ�
// 1. CArr �ڷ��� ũ�� ��ŭ �޸� �Ҵ�
// 2. CArr �ڷ��� �ΰ� �����Ϸ��� �����ϰ� �����ڸ� ���� �ʱⰪ ���ñ���
//CArr* cTest = new CArr;

// CArr �ڷ����� Ȯ���ϰ� �ش� Ŭ������ �Ҹ��ڸ� ���� ����
//delete cTest;


// �߿����
// Ŭ���� ���ø��� ���� ��
// ���ø��� �Լ� ���� cpp������ �ƴ϶� ��� ���Ͽ� �����ؾ��Ѵ�.


// ������
// ���ø� ������
template<typename T>
CArr<T>::CArr()
// ��� ������
	:m_pData(nullptr)  //int* m_pInt;
	, m_iCount(0)
	, m_iMaxCount(2)
{
	// new �����Ҵ� Ű����, C������ malloc
	m_pData = new T[2]; // T �ڷ��� 2�� ũ�� �޸� �Ҵ�
}


template<typename T>
CArr<T>::~CArr()
{
	// int �ڷ��� �� ���� delete
	// int[] �ڷ��� �� ���� delete[]
	// �޸� ����
	delete[] m_pData;
}

template<typename T>
void CArr<T>::PushBack(const T& _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// �ø����� ����� maxCount ���� �۰ų� ������ ���� ó�� (�ǹ̾���X)
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. resize size ��ŭ ���� �Ҵ�
	T* pNew = new T[_iResizeCount];

	// 2. ���� �����͸� ���ο� �������� ����
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ���� �޸� ����
	delete[] m_pData;

	// 4. ���� �Ҵ�� ���� ����Ű��
	m_pData = pNew;

	// 5. maxCount ����
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int index)
{
	return m_pData[index];
}

template<typename T>
int CArr<T>::returnSize()
{
	return m_iCount;
}
