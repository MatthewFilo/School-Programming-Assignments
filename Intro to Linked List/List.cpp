#include "List1.h"
#include "node.h"
using namespace std;



List::List()
:first(0),last(0) // Initializing both private variables to zero in order to create an empty list.
{

}



bool List::Empty() // return true if the list is empty, otherwise return false
{
    if(first == 0) // If the first variable in the linked list is null, there are no other variables that come after it, hence our deciding factor.
        return true;
    else
        return false;
}

void List::InsertAtEnd(ElementType x) //insert a value x on the end of the list
{
	node *newnode = new node(x, 0, 0); // We must first intialize a new node with the prev and the next being null, but the data being what the user is storing.

	if(first == NULL) // If the list is empty, we have to declare the new node the first and the last node so that it can be initialized as such.
	{
		first = newnode;
		last = first;

	}

	else // Otherwise the new node will take over the place of the last node.
	{
		newnode->prev = last; // The prev of the new node will be the original last node, as it now points back to it.
		last->next = newnode; // The original last node will now point to the new node rather then to null.
		last = newnode; //The new last variable is the new node, which is now replaced.
	}




}

void List::Delete(ElementType x) //if value x is in the list, remove x
{
	node* ptr; // Declare a new node to scroll through the list of nodes.
	ptr = first; // Set it equal to first so it can start at the first node and go through the rest of them.
	while(ptr != NULL) // If the ptr does not equal null, there are elements in the list, scroll through them.
	{
		if(ptr->data == x) //Once the pointer recognizes the data, it will check for conditions.
		{
			if(ptr == first) // If the data is in the first node, then the new first will be the original first's next, and then it will delete the first.
			{
				first = first->next;
			}

			else //Otherwise the next nodes prev will be the ptr's next.
			{
				ptr->prev->next = ptr->next;
			}

			if(ptr->next != 0) // If the pointer is not equal to 0, then the prev of the next will be the deleted ptr's prev.
			{
				ptr->next->prev = ptr->prev;
			}

			if(ptr == last) // If the data is in the last node, then the new last will be the original last's previous ptr.
			{
				last = last->prev;
			}

			delete ptr; // Delete pointer
		}

		ptr = ptr->next; // Sets the next pointer for the next while loop.
	}
}

void List::Display() //Display the data values in the list in the order inserted
{
	node* ptr;
	ptr = first; // Creating a new pointer and setting it to null.
	if(ptr == NULL) // If first is equal to null, there are no other elements in the list, it will say the list is empty.
	{
		cout<< "The List is Empty" << endl;
	}
	while(ptr != NULL) // While the pointer is not null, it will scroll through the data of the nodes in the list and display them one by one.
	{
		cout << ptr->data << " ";
		ptr = ptr->next; // setting the pointer to the next pointer to be displayed properly.
	}
}

int List::Sum() // Compute and return the sum of the values in the list
{
	node* ptr;
	ptr = first; // Setting a new ptr to the first node of the list.
	int sum = 0; // Initializing a sum integer.

	if(ptr == NULL) //If the first pointer is null, the list is empty and I am returning 0.
		{
			sum = 0;
			return sum;
		}

	while(ptr != NULL) // While the pointer is not null
	{
		sum += ptr->data; // The sum is accumulating from the ptr's data while scrolling through the linked list.
		ptr = ptr->next;
	}

	return sum; // Returning sum.
}

int List::Average() // Compute and return the average of the values in the list
{
	node* ptr;
	ptr = first; // Initializing a new node and setting it to first.
	int sum = 0;
	int count = 0;

	while(ptr != NULL) // This is the same concept as the sum while loop, except this time we increment a count variable to see how many variables are in the list.
	{
		sum += ptr->data;
		count++;
		ptr = ptr->next;
	}

	if(ptr != NULL) // If the first node is null, list is empty, return 0.
	{
		sum = 0;
		return sum;
	}

	int average = sum / count;

	return average; //This will return the sum of the list over how many variables are in the list, thus giving us the average.
}

