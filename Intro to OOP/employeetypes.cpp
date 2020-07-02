#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

// Employee Classes ****************************************************************************************************************

class Owner : public employee // The Derived Class to specify the Owner inherited by the base employee class.
{
	// The owner does not have any unique characteristics about him, so we do not need a private section for him.
	public: // Basic information about the employee.
		Owner(string newname)
		{
			employeetype = 'O';
			salary = 15000;
			profitshare = .60;
			employeeid = 1;
			name = newname;
		}

		float calculate_salary(int mod) // Use of the virtual calculate_salary function returning the type of salary for the owner.
		{
			return salary + (mod * profitshare);
		}
};

class Waiter : public employee // Derived Class to specify the Waiter inherited by the base employee class.
{
	private: // Private section for years worked as a Waiter as no outside class should be able to access this other then the Waiter's themselves.
		int yearsworked;

	public: //Basic information about the waiter.
		Waiter(string newname, int years, int id)
		{
			employeetype = 'W';
			salary = 3000;
			profitshare = 0;
			employeeid = id;
			name = newname;
			yearsworked = years;
		}

		int getyearsworked() // This function is to display the years worked by the Waiter from the private section of the Waiter Class.
		{
			return yearsworked;
		}

		float calculate_salary(int mod) // Use of the virtual function as now we have a different return value then the other classes.
		{
			return salary + mod;
		}
};

class Chef : public employee // Derived Class to specify the Chef inherited by the base employee class.
{
	private: // Private section for the specialty of the Chef as no other class should be accessing this other then the chef's themselves.
		string specialty;

	public: // Basic information about the chef
		Chef(string newname, string newspecialty, int id)
		{
			employeetype = 'C';
			salary = 10000;
			profitshare = .20;
			employeeid = id;
			name = newname;
			specialty = newspecialty;
		}

		float calculate_salary(int mod) // Virtual function used to calculate the salary of the Chef.
		{
			return salary + (mod * profitshare);
		}

		string getspecialty() // This function is to display the chef's specialty from the private string of the Chef class.
		{
			return specialty;
		}
};
