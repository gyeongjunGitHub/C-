#include"List.h"
#include<iostream>

void InitList(myList* m)
{
	m->first_node = nullptr;
	m->count = 0;
}
void pushBack(myList* m, int data)
{
	node* pNode = (node*)malloc(sizeof(node));

	pNode->data = data;
	pNode->next_node = nullptr;

	if (m->count == 0)
	{
		m->first_node = pNode;
	}
	else
	{
		node* finalNode = m->first_node;
		while (finalNode->next_node)
		{
			finalNode = finalNode->next_node;
		}

		finalNode->next_node = pNode;
	}
	++m->count;
}
void pushFront(myList* m, int data)
{
	// 메모리 공간 할당
	node* pNode = (node*)malloc(sizeof(node));

	// data추가
	pNode->data = data;
	
	pNode->next_node = m->first_node;
	m->first_node = pNode;

	++m->count;
}
void ReleaseList(myList* m)
{
	node* pdeleteNode = m->first_node;

	while (pdeleteNode)
	{
		node* pNext = pdeleteNode->next_node;
		free(pdeleteNode);
		pdeleteNode = pNext;
	}
}
