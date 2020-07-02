#include <iostream>
#include <string>
#include "employee.h"
using namespace std;



// Employee.h Functions ************************************************************************************************************
int employee::getid(){ // Get Employee ID function
	return employeeid;
}

char employee::gettype() // Get the type of employee that the employee is
{
	return employeetype;
}

int employee::getsalary() //Get the salary of that employee
{
	return salary;
}

float employee::getshare() // Get the amount of profit shared to that employee.
{
	return profitshare;
}

string employee::getname() // Don't be rude, get the name of that employee!
{
	return name;
}

float employee::calculate_salary(int mod) // Calculates the salary of every employee, does not return anything as the function is virtual and will return salaries with different
{	//Ways of computing those salaries.

}
