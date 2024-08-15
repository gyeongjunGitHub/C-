#pragma once
#include<iostream>


typedef struct node {
	int data;
	node* next_node;
}node;

typedef struct myList {
	node*	first_node;
	int		count;
}myList;