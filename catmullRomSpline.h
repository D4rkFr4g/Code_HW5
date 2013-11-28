/****************************************************** 
* Project:         CS 116A Homework #4
* File:            catmullRomSpline.h
* Purpose:         Implement a curve drawing algorithm
* Start date:      11/17/13 
* Programmer:      Zane Melcho 
* 
****************************************************** 
*/

#include "cvec.h"

using namespace std;

class catmullRomSpline
{
	// This class calculates the interpolation of a catmull rom spline

public:
	static Cvec3 interpolate(Cvec3 *splineArray, int index, float time);
	static Cvec3 firstDerivative();

private:
	static Cvec3 derivedVector;
};