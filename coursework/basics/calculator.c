// This program calculates the volume of a sphere given its radius.
#include <stdio.h> // Importing the standard input-output library
#include <stdlib.h> // Importing the standard library for memory allocation and other functions
#define Pi 3.14159 // Defining the value of Pi as a constant

double SphereVolume(double radius); // Declare the function, its type, its input and that type before main()

int main() // Program Starts
{
double radius = -1, volume = 0; // Defines the initial variables as doubles
printf("input the radius\n"); // Terminal asks for an input 
while (radius < 0) scanf("%lf", &radius); //Terminal waits for a double input and assigns it to radius in mem
if(radius == 0) volume = 0.0; // nonzero check
else volume = SphereVolume(radius); // run the function defined below
printf("The volume of the sphere is %f\n", volume);
return 0;
}

double SphereVolume(double radius)
{
    return(1.333333*Pi*radius*radius*radius);
}