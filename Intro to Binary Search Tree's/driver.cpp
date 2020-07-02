#include "bst.h"
#include <iostream>


int main()

{

    binarysearchtree bintree; // Create a new object from the binarysearch tree class

    char option; // Create an option variable for the user

    char character, searchitem, deleteitem, sibnode; // Initializing values for the user's input screen.

     

    cout << "Welcome to the Binary Search Tree!" << endl;

    cout << " 1. Insert node(s) in BST." << endl;
    cout << " 2. Traverse Preorder." << endl;
    cout << " 3. Search BST." << endl;
    cout << " 4. Delete node." << endl;
    cout << " 5. Leaf Count." << endl;
    cout << " 6. Sibling of a node." << endl;
    cout << " 7. Quit." << endl;

    while (1)
    {

        //Prompt the user to enter the choice.

        cout << "Enter an option: ";

        cin >> option;

        switch (option) // Switch statement that will execute a function based on the user's decision.
        {
        case '1': // This will execute the insert node function
            int nodenum; // This is so we can insert multiple nodes if the user wants to.
            cout << "How many nodes would you like to enter?" << endl;
            cin >> nodenum; // User enters number of nodes.

            for (int i = 0; i < nodenum; i++) // For loop that will iterate the function over and over until it reaches it's limit.
            {
                cout << "\nEnter A Node into the BST: ";
                cin >> character;
                bintree.insert(character);
            }
            break;

        case '2': // This will print the preorder transverse
            bintree.printpreorder();
            break;

        case '3': // This will execute the search function
            cout << "\nEnter item you want to search ";
            cout << "for: ";
            cin >> searchitem;
            bintree.searchbst(searchitem);
            break;

        case '4': // This will execute the delete function.
            cout << "\nEnter item you want to delete: ";
            cin >> deleteitem;
            bintree.deletenode(deleteitem);
            break;

        case '5': // This will execute the Leaf search function
            int leaves;
            leaves = bintree.count();
            cout << "There are " << leaves << " leaves in the bintree." << endl;
            break;

        case '6': // This will execute the sibling node function
            cout << "\nEnter item you want to find the sibling of: ";
            cin >> sibnode;
            bintree.nodesibling(sibnode);
            break;

        case '7': // This will end the program
            cout << "Thank you for using the Binary Search Tree!" << endl;
            return 0;

        default: // This is the default value for if something other then what is prompted is entered.
            cout << "Enter a listed option!\n" << endl;
            break;

        }

    }

}