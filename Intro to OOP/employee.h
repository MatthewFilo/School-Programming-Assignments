/*
 * employee.h
 *
 *  Created on: Apr 7, 2020
 *      Author: mattf
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef EMPLOYEE
#define EMPLOYEE

class employee { // This class is the basic outline for each employee

	protected: // We get the name, employee type, id, salary and share of profit.
		int employeeid;
		char employeetype;
		int salary;
		float profitshare;
		string name;

	public: // These functions allow us to get the characteristics of the employees so that we can display them in our UI.
		int getid();
		char gettype();
		int getsalary();
		float getshare();
		string getname();

		virtual float calculate_salary(int mod); //This function to calculate salary is virtual so that way when we have different employee types
		// We can effectively calculate this salary by allowing it to be overridden by the class the function is inserted to.
};



#endif
