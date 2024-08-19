#pragma once

// C++������ ����ü�� class�� ���� �����ϴ�.
// default public
template<typename T>
struct Node
{
	T			data;
	Node<T>*	prevNode; // <T>�κ� ������ ���� �ʾƵ� ��
	Node<T>*	nextNode; // <T>�κ� ������ ���� �ʾƵ� ��

	//C++�� ����ü�� �����ڸ� ���� �� �ִ�.
	// �⺻ ������
	Node()
		:data() // �ƹ� ���� ���� ������ �⺻.
		,prevNode(nullptr)
		,nextNode(nullptr)
	{

	}

	// �����ε� ������ JAVA�� ����ϳ�
	Node(const T& _data, Node<T>* _prevNode, Node<T>* _nextNode)
		:data(_data)
		,prevNode(_prevNode)
		,nextNode(_nextNode)
	{

	}
};

// default private
template<typename T>
class LinkedList
{
private:
	Node<T>*	m_pHead;	//�Ӹ�
	Node<T>*	m_pTail;	//����
	int			m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
public:
	LinkedList();	// ������
	~LinkedList();	// �Ҹ���
};

template<typename T>
inline void LinkedList<T>::push_back(const T& _data)
{
	//��� ���� �����Ҵ�.
	Node<T>* pNewNode = new Node<T>(_data, m_pTail, nullptr);

	// ó�� �Էµ� ������
	if (m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pTail = pNewNode;
	}
	else
	{
		//������ ��忡 �߰�
		//���� ������ �Ǿ����

		// ���� �������̿��� ����� nextNode ����
		m_pTail->nextNode = pNewNode;

		// ���� ������ ����� prevNode ����
		//pNewNode->prevNode = m_pTail;

		m_pTail = pNewNode;
	}

	++m_iCount;
}

template<typename T>
inline void LinkedList<T>::push_front(const T& _data)
{
	//��� ���� �����Ҵ�.
	Node<T>* pNewNode = new Node<T>(_data, nullptr, m_pHead);

	// ó�� �Էµ� ������
	if (m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pTail = pNewNode;
	}
	else
	{
		// �Ӹ����� ������ prevNode�� ����
		m_pHead->prevNode = pNewNode;

		// �Ӹ� ��� ��ü
		m_pHead = pNewNode;
	}

	++m_iCount;
}

template<typename T>
LinkedList<T>::LinkedList()
	:m_pHead(nullptr)
	,m_pTail(nullptr)
	,m_iCount(0)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		Node<T>* pNext = pDeleteNode->nextNode;
		delete pDeleteNode;
		pDeleteNode = pNext;
	}
}

