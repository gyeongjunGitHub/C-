#pragma once
#include<iostream>


typedef struct node {
	int data;
	struct node* next_node;
}node;

typedef struct myList {
	node*	first_node;
	int		count;
}myList;

void InitList(myList* m); 

void pushBack(myList* m , int data);
void pushFront(myList* m , int data);

void ReleaseList(myList* m);
