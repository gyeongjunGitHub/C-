#include "CArr.h"
#include<assert.h>
// new Ű����� ���� �Ҵ�
// 1. CArr �ڷ��� ũ�� ��ŭ �޸� �Ҵ�
// 2. CArr �ڷ��� �ΰ� �����Ϸ��� �����ϰ� �����ڸ� ���� �ʱⰪ ���ñ���
//CArr* cTest = new CArr;

// CArr �ڷ����� Ȯ���ϰ� �ش� Ŭ������ �Ҹ��ڸ� ���� ����
//delete cTest;

// ������
CArr::CArr()
	// ��� ������
	:m_pInt(nullptr)  //int* m_pInt;
	,m_iCount(0)
	,m_iMaxCount(2)
{
	// new �����Ҵ� Ű����, C������ malloc
	m_pInt = new int[2]; // int �ڷ��� 2�� ũ�� �޸� �Ҵ�
}

CArr::~CArr()
{
	// int �ڷ��� �� ���� delete
	// int[] �ڷ��� �� ���� delete[]
	// �޸� ����
	delete[] m_pInt;
}

void CArr::PushBack(int _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	// ������ �߰�
	m_pInt[m_iCount++] = _Data;
}

void CArr::resize(int _iResizeCount)
{
	// �ø����� ����� maxCount ���� �۰ų� ������ ���� ó�� (�ǹ̾���X)
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. resize size ��ŭ ���� �Ҵ�
	int* pNew = new int[_iResizeCount];

	// 2. ���� �����͸� ���ο� �������� ����
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. ���� ���� �޸� ����
	delete[] m_pInt;

	// 4. ���� �Ҵ�� ���� ����Ű��
	m_pInt = pNew;

	// 5. maxCount ����
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int index)
{
	return m_pInt[index];
}
