#include "employee.h"
#include "employeetypes.cpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int staffsize = 6;
	employee *employeedata[staffsize] = // Initializing the employee database with the amount of employees
	{
			// Initialization of the staff throughout parameters which we provide.
			new Owner("Filo"),
			new Chef("Corey", "Italian", 2),
			new Chef("Steven", "American", 3),
			new Waiter("Conner", 5, 4),
			new Waiter("Chad", 7, 5),
			new Waiter("Dylan", 2, 6)
	};

	// Initializing the tip percentages for each of the waiters as well as the overall monthly profit
	float tip1;
	float tip2;
	float tip3;
	float profit;

	int k = 2; //Variable to count which monthly report it is.

	// Beginning of the Display of the employee's
	cout << "Employee List: \n" << endl;

	for(int i = 0; i<staffsize; i++) // Looping through the employee data base array to display each employee
	{
		cout << employeedata[i]->getname() << " - " << employeedata[i]->gettype() << ":	";
		cout << "Salary: $" << employeedata[i]->getsalary() << endl;

		if(employeedata[i]->gettype() == 'O') // Based on employee types, we will display different qualities about the chef.
		{
			cout << "\n";
		}

		if(employeedata[i]->gettype() == 'C')
		{
			cout << "  Specialty: " << ((Chef*)employeedata[i])->getspecialty() << "\n" << endl;
		}

		if(employeedata[i]->gettype() == 'W')
		{
			cout << "  Years Worked: " << ((Waiter*)employeedata[i])->getyearsworked() << "\n" << endl;
		}
	}


	cout << endl; // End of the beginning display

	cout<< "Press 0 to exit the program \n" << endl;
	cout << "End Of Month 1 Report: " << endl; // Beginning of the end of month display

	cout << endl;


loop: // We introduce an assembly like loop to simplify the looping of asking the user for the monthly profits.

// Asking the user for input on what the monthly profit was
	cout << "Enter the amount of profit earned this month: $";
	cin >> profit;

	// Math for the tips based on the waiters, tip1 going to waiter 1, tip 2 going to waiter 2 and tip 3 going to waiter 3.
	tip1 = (profit * 1000) / 6000;
	tip2 = (profit * 1500) / 6000;
	tip3 = (profit * 1700) / 6000;

	cout << endl;

	if(profit > 0) // If there was profit made this month, this display will show.
	{
		for(int i = 0; i < 3; i++) // We introduce a for loop since the first three employees output the same displays.
		{
			cout << employeedata[i]->getname() << " - " << employeedata[i]->gettype() << endl;
			cout << "	Salary for this Month: $" << employeedata[i]->getsalary();
			cout << " || Profit Share for this Month: $" << employeedata[i]->getshare()*100 << "%";
			cout << " || Overall Pay for This Month: $" << employeedata[i]->calculate_salary(profit) << endl;
		}

		// Here we individually display each of the waiters as they have a certain float value that belongs to them depending on which waiter they were.
		// We could have made an array of floats so that way we could output the code more efficiently, but this way is simpler so we went with this route.
		cout << employeedata[3]->getname() << " - " << employeedata[3]->gettype() << endl;
		cout << "	Waiter 1 Monthly Salary: $" << employeedata[3]->getsalary();
		cout << " || Tips for the Month: $" << tip1;
		cout << " || Overall Pay for the Month: $" << employeedata[3]->calculate_salary(tip1);
		cout << endl;

		cout << employeedata[4]->getname() << " - " << employeedata[4]->gettype() << endl;
		cout << "	Waiter 2 Monthly Salary: $" << employeedata[4]->getsalary();
		cout << " || Tips: $ " << tip2;
		cout << " || Overall Pay for the Month: $" << employeedata[4]->calculate_salary(tip2);
		cout << endl;

		cout << employeedata[5]->getname() << " - " << employeedata[5]->gettype() << endl;
		cout << "	Waiter 3 Monthly Salary: $" << employeedata[5]->getsalary();
		cout << " || Tips : $" << tip3;
		cout << " || Overall Pay for the Month: $" << employeedata[5]->calculate_salary(tip3) << endl;
		cout << endl;


		cout << "End of Month " << k << " Report: \n" << endl; // End of the monthly report.
		k += 1;
		if(k > 12)
		{
			k = 1;
		}

		goto loop; // At the end of the condition that there was profit made, the loop will restart.
	}

	if(profit == 0) // If there was no monthly profit made, the employer realizes he should search for a new staff and not continue on with this one :).
	{
		cout << "There was absolutely no profit made this month...Time for a new staff!" << endl;
	}

	if(profit < 0)
	{
		cout << "We actually lost money this month... Find a new staff or you'll go bankrupt in two weeks.";
		goto loop;
	}


	return 0; // End of main function.

}
