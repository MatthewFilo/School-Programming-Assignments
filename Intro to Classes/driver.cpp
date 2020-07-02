#include "Sphere.h"
//"Include Sphere.h" Duplicate Test
#include "Sphere.h"

int main() // Int Main declaration to say that this is where we are running the true program.
{

   Sphere unitSphere; // Declaring two objects from the class to test out the functions.

   Sphere mySphere(5.1);

cout<<unitSphere<<endl; // Testing of the << operator to ensure that the display function and overloading are working.

mySphere.setRadius(4.5); // Use of the setRadius function to test capabilities of changing the radius value.

// Testing out of individual functions to make sure that if needed, only one function can be found instead of all.
cout<<mySphere.getDiameter();
cout<<mySphere.getVolume();
cout<<mySphere.getArea();
cout<<mySphere.getCircumfrence();
cout<<mySphere.getRadius();

return 0;

} //end main()
