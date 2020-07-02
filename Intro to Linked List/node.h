/*
 * node.h
 *
 *  Created on: Mar 21, 2020
 *      Author: admin
 */

#include <iostream>

#ifndef NODE
#define NODE

using namespace std;


typedef int ElementType;

class node // Creating a class called node so we have the structure of a node.
{
public:

	node(); // Default value constructor.

	node(ElementType data1, node *next1, node *prev1); // Explicit value constructor

	ElementType data;
    node * next; // Pointer to the next node in the Doubly Linked List
    node* prev; // Pointer to the previous node in the Doubly Linked List
};

#endif
