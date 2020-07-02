/****************************************************INSTRUCTIONS*************************************************************************
Write a class called “Sphere” which has the following data members:

- A double variable called “Radius” to denote the radius of the sphere.

The class should have the following function members:

- A default constructor which sets the radius to a default value of 1.0
- An explicit value constructor
- 5 accessor functions namely getRadius(), getDiameter(), getCircumference(), getArea(), getVolume() 
    which returns the respective statistics of the sphere.
- A mutator function to set the value of the data member
- A display function which displays the radius, diameter, volume and area of the sphere on the output object specified by the programmer. 
    This function also acts as a helper function in overloading the “<<” operator
    A non member function overloading the << operator which uses the display member function.
***************************************************************************************************************************************************************************************************
*/


#include "Sphere.h"
#include <math.h> // Including this so that we can properly use PI as part of our calculations.
using namespace std;

// Default Constructor
Sphere::Sphere() // Default constructor to have radius be set to a default value.
    :radius(1.0)
{

}
// Explicit-Value Constructor to ensure that radius is fully initilaized by an Explicit Value.
Sphere::Sphere(double initradius)
{
    if(initradius == 1.0)
    {
    	radius = initradius;
    }
    

}

// Accessor Functions
float Sphere::getRadius() const
{
    printf("\nYour Radius is: "); // Printf statement to make program easily readable when function is called.
	return radius;
}

float Sphere::getDiameter() const
{
	printf("\nYour Diameter with Radius %.3f is: ", radius); // Printf statement to make program easily readable when function is called.
      return(2 * radius); // Math to receive the Diameter.
}

float Sphere::getCircumfrence() const
{
	printf("\nYour Circumfrence with Radius %.3f is: ", radius); // Printf statement to make program easily readable when function is called.
    return(2 * M_PI * radius); // Math to receive the Circumfrence
}

float Sphere::getArea() const
{
	printf("\nYour Area with Radius %.3f is: ", radius); // Printf statement to make program easily readable when function is called.
	return(pow(radius, 2) * M_PI); // Math to receive the Area.
}

float Sphere::getVolume() const
{
	printf("\nYour Volume with Radius %.3f is: ", radius); // Printf statement to make program easily readable when function is called.
    return( (1.3333) * M_PI * pow(radius, 3) ); // Math to receive the Volume.
}


//Mutator Function To Set a New Radius of the same object.
void Sphere::setRadius(float r)
{
    printf("\nYou set your new radius to %.3f\n", r); // Printf statement to make program easily readable when function is called.
	radius = r; // Setting radius equal to the new variable which takes an input in it's parameters.
}


// Display And Ostream Operators
ostream & operator<<(ostream & j, Sphere & sp) // Overloading the << Operator
{
  sp.display(j);
  return j;
}

void Sphere::display(ostream & out) const // When << is called within a object of the class, this is what it will
										  // Display.
{
    out << getRadius()
        << getDiameter()
        << getArea()
        << getCircumfrence()
        << getVolume();

}

