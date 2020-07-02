#include <iostream>
#include "node.h"
#ifndef LIST1
#define LIST1

using namespace std;


typedef int ElementType;



class List
{

    public:

        List();  //Create an empty list

        bool Empty(); // return true if the list is empty, otherwise return false

        void InsertAtEnd(ElementType x); //insert a value x on the end of the list

        void Delete(ElementType x); //if value x is in the list, remove x

        void Display(); //Display the data values in the list in the order inserted

        int Sum(); // Compute and return the sum of the values in the list

        int Average(); // Compute and return the average of the values in the list

    private:

        node * first; // Default first value of the list.

        node * last; // Creating a last variable to help with the implementation of the InsertAtEnd Function.



};

#endif

