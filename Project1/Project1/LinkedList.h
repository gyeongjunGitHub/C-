#pragma once

// C++에서의 구조체는 class와 거의 유사하다.
// default public
template<typename T>
struct Node
{
	T			data;
	Node<T>*	prevNode; // <T>부분 굳ㅈ이 적지 않아도 됨
	Node<T>*	nextNode; // <T>부분 굳ㅈ이 적지 않아도 됨

	//C++의 구조체도 생성자를 만들 수 있다.
	// 기본 생성자
	Node()
		:data() // 아무 값도 적지 않으면 기본.
		,prevNode(nullptr)
		,nextNode(nullptr)
	{

	}

	// 오버로딩 생성자 JAVA랑 비슷하노
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
	Node<T>*	m_pHead;	//머리
	Node<T>*	m_pTail;	//꼬리
	int			m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
public:
	LinkedList();	// 생성자
	~LinkedList();	// 소멸자
};

template<typename T>
inline void LinkedList<T>::push_back(const T& _data)
{
	//노드 생성 동적할당.
	Node<T>* pNewNode = new Node<T>(_data, m_pTail, nullptr);

	// 처음 입력되 데이터
	if (m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pTail = pNewNode;
	}
	else
	{
		//마지막 노드에 추가
		//서로 연결이 되어야함

		// 제일 마지막이였던 노드의 nextNode 세팅
		m_pTail->nextNode = pNewNode;

		// 새로 생성된 노드의 prevNode 세팅
		//pNewNode->prevNode = m_pTail;

		m_pTail = pNewNode;
	}

	++m_iCount;
}

template<typename T>
inline void LinkedList<T>::push_front(const T& _data)
{
	//노드 생성 동적할당.
	Node<T>* pNewNode = new Node<T>(_data, nullptr, m_pHead);

	// 처음 입력되 데이터
	if (m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pTail = pNewNode;
	}
	else
	{
		// 머리였던 오드의 prevNode를 세팅
		m_pHead->prevNode = pNewNode;

		// 머리 노드 교체
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

