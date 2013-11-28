/****************************************************** 
* Project:         CS 116A Homework #4
* File:            catmullRomSpline.cpp
* Purpose:         Implement a curve drawing algorithm
* Start date:      11/17/13 
* Programmer:      Zane Melcho 
* 
****************************************************** 
*/

#include "catmullRomSpline.h"

Cvec3 catmullRomSpline::derivedVector = Cvec3(0,0,0);

/*-----------------------------------------------*/
Cvec3 catmullRomSpline::interpolate(Cvec3 *splineArray, int index, float time)
{
	/* PURPOSE:		Calculates the position of an interpolated point between two catmull rom control points 
		RECEIVES:   splineArray - Array of Cvec3's that make up the spline
						index - Current position in the spline array
						time - Current time in interpolation
		RETURNS:    Cvec3 of current interpolated position
		REMARKS:		Precondition: Should not pass an index more than 2 from the end of the array
	*/

	Cvec3 pointBefore = splineArray[index - 1];
	Cvec3 point = splineArray[index];
	Cvec3 pointAfter = splineArray[index+1];
	Cvec3 pointPlusTwo = splineArray[index+2];

	Cvec3 d = ((pointAfter - pointBefore) * (1.0/6)) + point;
	Cvec3 e =  ((pointPlusTwo - point) * (-1.0/6)) + pointAfter;

	Cvec3 f = (point * (1 - time)) + (d * time);
	Cvec3 g = (d * (1 - time)) + (e * time);
	Cvec3 h = (e * (1 - time)) + (pointAfter * time);
	Cvec3 m = (f * (1 - time)) + (g * time);
	Cvec3 n = (g * (1 - time)) + (h * time);
	Cvec3 final = (m * (1 - time)) + (n * time);


	// Calculate first derivative
	derivedVector = (point * -3 * pow(time, 2)) + (pointAfter * 3 * pow(time, 2)) + (point * 6 * time) -
		(point * 3) - (d * 9 * pow(time,2)) + (d * 3) - (e * 9 * pow(time, 2)) + (e * 6 * time);

	return final;
}
/*-----------------------------------------------*/
/*-----------------------------------------------*/
Cvec3 catmullRomSpline::firstDerivative()
{
	/* PURPOSE:		Returns the first derivative of an interpolated point between two catmull rom control points 
		REMARKS:		Precondition: interpolate function must run before value is retreived
	*/

	return derivedVector;
}
/*-----------------------------------------------*/