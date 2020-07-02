#include <iostream>
#include <cstdlib>

#ifndef bst
#define bst

using namespace std;

class binarysearchtree
{
	private:
		// Creating a node structure that will be used in the BST for each individual data piece.
		struct node
		{
			node* left;
			node* right;
			char data;
		};
		node* root; // Declaring the root node so that the other data members will have something to branch off of.
		
	public:
		binarysearchtree()
		{
			root = 0; // setting an explicit value so that the root starts off with a null byte, etc. nothing in it when the class is constructed.
		}

		bool empty() const // This function will check to make sure that the BST is empty by checking if the root is equal to nothing.
		{
			return root == NULL;
		}

		void insert(char); // Insert nodes function
		void printpreorder(); // This will print the preordered BST
		void preordertrav(node*); // This will traverse the BST in preorder
		void searchbst(char); // This will search the BST for an individual function.
		void deletenode(char); // This will be used to delete a node off the BST
		int count(); // This is used as part of our leafcount function
		int leafcount(node*); // This will be used to count the number of leaves in the BST
		void nodesibling(char); // This will tell you the sibiling of a node.


};

/*
1. Insert node(s)
2. Traverse Preorder
3. Search BST
4. Delete node
5. Leaf Count
6. Sibling of a node
7. Quit
*/
#endif