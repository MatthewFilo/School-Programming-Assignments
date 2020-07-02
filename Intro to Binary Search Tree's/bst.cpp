#include <iostream>
#include "bst.h"
using namespace std;

void binarysearchtree::insert(char ndata) // This function is used to insert data members into the BST
{
	node* tree = new node; // We will create a new node called tree
	node* parent; // We will create a new node called parent.

	tree->data = ndata; // The new node tree will hold the data of the value we passed into the parameter.
	tree->left = NULL; // Since it is a new node, the left and right data members of the new node will be null until further specified.
	tree->right = NULL;
	parent = NULL; // The parent of this node will also be null until further specified

	if (empty()) // First we must check that the BST is not empty, for if it is, our new node will be the root.
	{
		root = tree;
	}

	else // If the BST is not empty, then we must perform the other operation.
	{
		node* curr; // We create a current node object and set it equal to root.
		curr = root;

		while (curr)
		{
			parent = curr; // while we go through the BST, we will set the parent node equal to our current node.

			if (tree->data > curr->data) // If the data provided by the new data is bigger then the current node's data
			{
				curr = curr->right; // It is equal to the right subtree of the current node.
			}

			else
			{
				curr = curr->left; // Otherwise it is equal to the left subtree of the current node.
			}
		}

		if (tree->data < parent->data) // If the data of the new node is less then the parent node's data, then it goes to the left of the parent node.
		{
			parent->left = tree;
		}

		else // Otherwise the data will go into the right side of the parent node.
		{
			parent->right = tree;
		}
	}
}

void binarysearchtree::searchbst(char searchitem) // This function is to search the BST for a certain data value.
// In this function, we create a new node that will scan through the tree by going left if the data value is smaller then what is already in the tree, or right if the value is bigger then the BST
// It will keep going until it hits null or it finds the item.
{
	node* ptr = root; // We create a new node called ptr and set it equal to the root.

	while (ptr != NULL && ptr->data != searchitem) // We go through the BST as long as the ptr does not equal null or does not equal the item we are looking for.
	{
		if (searchitem < ptr->data) // If the search item is less then the data in the BST, the tree will keep going through to the left.
		{
			ptr = ptr->left;
		}

		else // Otherwise it will go to the right and keep comparing until it reaches a point where it is smaller then the data in the ptr, or until it hits null.
		{
			ptr = ptr->right;
		}
	}

	if (ptr != NULL) // If the ptr does not hit null, that means we found the object
	{
		cout << searchitem << " Found!" << endl;;
	}

	else // Otherwise if the pointer does hit null, that means the object was not found in the tree.
	{
		cout << "That item is not in the BST" << endl;
	}
}

void binarysearchtree::deletenode(char del) // This is the function to delete a node out of the BST.
{
	node* ptr, *parent; // These are nodes to hold the parent node and temp node
	node* repplaceparent, *replacenode; // These are nodes that are meant to replace the parent node and the node to replace
	node* child; // This is the node for the child node.
	
	int isnodeleft = 0;
	parent = NULL; // We will set the parent node equal to NULL

	ptr = root; // We will set our current pointer to the root of the BST and traverse the BST from there.

	while (ptr != NULL && ptr->data != del) // While the pointer is not null or equal to the pointer we are trying to delete
	{
		if (del < ptr->data) // If the char we are trying to delete is less then the data in the BST
		{
			parent = ptr; // We set the parent node equal to the ptr as we are going down a level in the BST
			isnodeleft = 1;
			ptr = ptr->left; // Now the ptr is going to be the left of the current ptr.
		}

		else
		{
			parent = ptr; // Otherwise the parent node is equal to the PTR
			isnodeleft = 0;
			ptr = ptr->right; // And the ptr is equal to the right of itself.
		}
	}

	if (ptr == NULL) // If the ptr reaches a point where it finds itself being null, that means the value provided is not in the BST.
	{
		cout << del << " is not in the BST" << endl;
	}

	if ((ptr->left == NULL) && (ptr->right == NULL)) // If the left and the right of the PTR is null
	{
		if (parent == NULL) // We check to make sure that if the parent is null
		{
			free(ptr); // We free the ptr and set the root equal to null.
			root = NULL;
		}

		else // If those conditions are not met in the previous if statement
		{
			free(ptr); // we free the ptr
			if (isnodeleft) // We will check if the isnodeleft variable was set to 1 "yes" or 0 "no" in the earlier statement.
			{
				parent->left = NULL; // If it was, the left of the parent node is now equal to null
			}
			else
			{
				parent->right = NULL; // Otherwise the right of the parent node is now equal to null.
			}
		}
	}

	else if ((ptr->left == NULL) || (ptr->right == NULL)) // Otherwise if only one (the left or the right) of the ptr is null, we execute this block of code.
	{
		if (ptr->left != NULL) // If the left of the ptr is not null
		{
			child = ptr->left; // We set the child node equal to the left of the ptr.
		}
		else
		{
			child = ptr->right; // Otherwise we set it equal to the right.
		}

		if (parent == NULL) // If the parent node is null
		{
			root = child; // We set the root equal to the child node that we assigned in the previous lines of this code.
			free(ptr); // We then free the ptr.
		}
		else
		{
			if (isnodeleft) // Otherwise if the parent is not null and the isnodeleft is set to 1, then the parent's left node is set to the child node.
			{
				parent->left = child;
			}
			else
			{
				parent->right = child; // Or else if isnodeleft set to 0, we then know that the child node belongs to the parents right node.
			}
			free(ptr);
		}
	}

	else // This is the block of code that if the node that needs to be deleted has left and right child nodes.
	{
		repplaceparent = ptr; // We set the ptr node equal to the replace parent node.
		replacenode = ptr->left;
		isnodeleft = 1; // We start off by setting the leftnode checker equal to 1.

		while (replacenode->right != NULL)
		{
			repplaceparent = replacenode;
			replacenode = replacenode->right; // We go to the right of the replacenode branch.
			isnodeleft = 0;
		}

		ptr->data = replacenode->data; // We assign the data of the replaced node to the ptr node's data.
		if (isnodeleft) // If the isnodeleft variable is set to 1
		{
			ptr->left = replacenode->left; // Then we replace our ptr node's left branch with our replacement node's left branch.
			free(replacenode); // We free up the replacenode since we are done with it.
		}

		else
		{
			repplaceparent->right = replacenode->left; // Otherwise we make the right of the repplaceparent node the left of the replacenode.
			free(replacenode); // We free the replacement node.
		}
	}
}

void binarysearchtree::preordertrav(node* nnode)
{
	if (nnode == NULL) // If the node provided was null, then we just return nothing from the function.
	{
		return;
	}
	cout << nnode->data << "\t\t";

	if (nnode->left != NULL) // If the left part of the node is not null, we print out the data
	{
		cout << nnode->left->data << "\t\t";
	}

	else // Otherwise the section is empty
	{
		cout << "Empty\t\t";
	}

	if (nnode->right != NULL) // If the new node's right branch is not null, we display the data of the right branch.
	{
		cout << nnode->right->data << "\t\t";
	}

	else // Otherwise it's empty.
	{
		cout << "Empty\t\t";

	}
	cout << "\n";

	preordertrav(nnode->left); // We perform the same function on the left of the new node.
	preordertrav(nnode->right); // We perform the same function on the right of the new node.
}

void binarysearchtree::printpreorder() // This function is just to properly display the preorder traversal in a clean-looking form.
{
	cout << "Preorder List:\n";
	cout << "Node info:\tLeft Child:\tRight Child:\n";
	cout << "     \t\t           \t              \n";
	preordertrav(this->root);
}

int binarysearchtree::count()// This function is merely just to return the leafcount from the root node.
{
	return leafcount(root);
}

int binarysearchtree::leafcount(node* root) 
{
	if (root == NULL) // If the root is null, then we return 0
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL) // If the left and the right are empty, then we at least have the root node, so we return 1.
	{
		return 1;
	}
	else
	{
		return leafcount(root->left) + leafcount(root->right); // Otherwise we perform the same function recursively until we reach a null root.
	}
}

void binarysearchtree::nodesibling(char sibling)
{
	node* ptr = root; // Declare a new node ptr as the root 
	node* parent = NULL; // Create a parent node that is NULL

	while (ptr != NULL && ptr->data != sibling) // While the ptr is not null or equal to the parameter passed through
	{
		if (sibling < ptr->data) // If the parameter passed through is less then the current data
		{
			parent = ptr; // Parent is equal the the ptr
			ptr = ptr->left; // and the ptr is now going to it's left branch.
		}

		else // Otherwise the parent is equal to the ptr and the ptr is going to the right branch.
		{
			parent = ptr;
			ptr = ptr->right;
		}
	}

	if (ptr == NULL) // If the ptr is null that means the parameter passed through does not have any siblings.
	{
		cout << sibling << " has no sibling" << endl;
	}

	else if (ptr == root) // If the ptr is the root, that means the root node does not have any siblings.
	{
		cout << "The Root node does not have any siblings\n" << endl;
	}



	if (parent == NULL) // Next comment is explanation.
	{
		cout << "Error occured, no Sibling\n" << endl;
	}

	else if (parent->left == NULL) // These were errors that were occurring throughout debug testing, so we have them here to fix those said errors.
	{
		cout << "Error Occured, No Sibling" << endl;
	}

	else if (parent->left->data == sibling) // If the left of the parent node is equal to the sibling
	{
		if (parent->right != NULL) // And the right node of the parent is not null
		{
			cout << "The sibling of " << sibling << " is " << parent->right->data << endl; // Then we found the sibling and output it
		}



		else // Otherwise we have no siblings.
		{
			cout << sibling << " Has no siblings" << endl;
		}
	}

	else
	{
		if (parent->left != NULL) // Or if the left node is not null
		{
			cout << "The sibling of " << sibling << " is " << parent->left->data << endl; // The we output that sibling.
		}
		else
		{
			cout << sibling << " Has no siblings" << endl;
		}
	}
}