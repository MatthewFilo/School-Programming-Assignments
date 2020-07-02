#include <iostream>
using namespace std;

#ifndef SPHERE // ifndef to ensure functionality incase the sphere.h file is included twice.
#define SPHERE


class Sphere // Class Declaration
{
    public:
        
        // Default Constructor
        Sphere();

        // Explicit Value Constructor
        Sphere(double initradius); // Ensures that the initial value is constructed by an explicit value.

        // Function Prototypes
        float getRadius() const;
        float getDiameter() const;
        float getCircumfrence() const;
        float getArea() const;
        float getVolume() const;

        //Set Function
        void setRadius(float r);

        // Display Function
        void display(ostream & out) const;

        // Non member overloading function
        friend ostream & operator<<(ostream & j, Sphere & sp);

    private: // Private variables to ensure that variable is not used outside class.
        double radius; // Radius set as a private member to ensure that code outside the class does not alter it. s
};

#endif // Ends the .h file, part of functionality with the ifndef.
