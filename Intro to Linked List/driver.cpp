#include "List1.h"
#include "node.h" //Including out List1.h and node.h files for use.
using namespace std;



int main()
{
	List doubly; // Creating an empty list to use for our main function.

	int *i = new int;
	*i = 1; // Creating a new variable for our while loop to have the program work continuously until the user exits the program.

	cout << "Welcome to the Linked List!" << endl; // Friendly Introduction for the user.


	while(*i == 1) //Beginning of the while loop.
	{
		cout << "Select an Option" << endl; // Beginning of the selection of options, a menu show casing what the user can do.
		cout << "1. Insert a new value at the end of the list" << endl;
		cout << "2. Delete a specific number in the list" << endl;
		cout << "3. Display the List of numbers" << endl;
		cout << "4. Compute and return the sum of the values in the list" << endl;
		cout << "5. Compute and return the average of the values in the list" << endl;
		cout << "6. Exit the program" << endl;
		cout << endl;

		cout << "Select an Option: ";
		char choice; // Creating a variable "Choice" and have the user enter an input for which menu option they would like to select.
		cin >> choice;

		cout << endl;

		switch(choice) // Implementing a switch statement so that a specific action can be performed based on the users input.
		{
		case '1': // Insert at end function
			ElementType x;
			cout << "Enter a value: " << endl;
			cin >> x;
			cout << "\n";
			doubly.InsertAtEnd(x);
			break;
		case '2': // Deletion function
			ElementType a;
			cout << "Number you wish to delete: " << endl;
			cin >> a;
			doubly.Delete(a);
			break;
		case '3': // Display function
			cout << "Current Linked List: ";
			doubly.Display();
			cout << endl;
			break;
		case '4': // Sum of the List Function
			cout << "Sum of the List is: " << doubly.Sum() << endl;
			break;
		case '5': // Average of the List Function
			cout << "Average of the List is: " << doubly.Average() << endl;
			break;
		case '6': // Sets the loop variable equal to 0, breaking the while loop and exiting the program.
			*i = 0;
			break;
		default:
			cout << "Please Enter one of the options provided" << endl;
			break;
		}

		cout << endl;

	}
}
