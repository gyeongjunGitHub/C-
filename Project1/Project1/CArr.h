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

	class iterator; //���� ����
	iterator begin();
	iterator end();

	// innerClass iterator
	// CArr �� innerClass�� ���� iterator�� �����̴�.
	// CArr 16Byte iterator m_i �� ũ�� ���� X.
	// innerCalss�� ���� Ŭ������ private �ʵ忡 ������ �� �ִ�.
	class iterator
	{
	private:	
		CArr* m_pArr;		// �����迭�� �ּ�
		T*		m_pData;	// �������� ó�� �����ּ�
		int		m_iIdx;		// �ε��� ��
		
	public:
		T& operator *()
		{
			// ������ ���ͷ����Ͱ� ������ �ִ� �ּҴ�
			// �����迭�� �޸� ���Ҵ� �� �����迭�� �ּҰ� �޶����� ������ ���ͷ����ͷ� ���� �����ϸ� �����ּ��� �޸𸮴� ����Ǿ��� ������ �������.
			// �Ǵ� end iterator�� ���
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}
			return m_pData[m_iIdx];
		}
		bool operator == (const iterator& _otheriter)
		{
			if (this->m_pArr == _otheriter.m_pArr && this->m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		// ���� & ����

		// ����
		iterator& operator ++ ()
		{
			// end iterator �� ���.
			// iterator�� �ּҰ� ���� m_pData != m_pArr->m_pData �� ���
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}

			// iterator �� ������ �����͸� ����Ű���ִ�.
			if (m_iIdx == m_pArr->returnSize() - 1)
			{
				m_iIdx = -1;
			}
			else
			{
				this->m_iIdx++;
			}

			return *this;
		}
		iterator& operator -- ()
		{
			return *this;
		}

		// ����
		// ��ȯŸ���� ���纻
		// ȣ�� ������ �ʾ����ų� ���� �ʴ´�.
		iterator operator ++(int)//�ƹ��ǹ̾��� int �׳� �̷��� ���� ���������ڷ��ν��Ѵ�
		{

		}

	public:
		iterator() // ������
			:m_pArr(nullptr)
			,m_pData(nullptr)
			,m_iIdx(-1)
		{

		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			:m_pArr(_pArr)
			,m_pData(_pData)
			,m_iIdx(_iIdx)
		{
		}
		~iterator()
		{
		}// �Ҹ���
	};
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

template<typename T>
//        ������� ��ȯŸ��| 
// ��ȯŸ���� �̳�Ŭ������ ��� typename�� �ٿ��־�� �Ѵ�.
typename CArr<T>::iterator CArr<T>::begin()
{
	if (this->m_iCount == 0)
	{
		return iterator(this, this->m_pData, -1); // �����Ͱ� ���� ��� begin() == end(); -1�� end()�� �� ����
	}
	// ������ ����Ű�� ���ͷ����͸� ��ȯ����
	return iterator(this, this->m_pData, 0); // �ӽð�ü ������ �ʿ����.
}

template<typename T>
//        ������� ��ȯŸ��| 
// ��ȯŸ���� �̳�Ŭ������ ��� typename�� �ٿ��־�� �Ѵ�.
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, this->m_pData, -1); // �ӽð�ü ������ �ʿ����.
}

