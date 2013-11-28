/****************************************************** 
* Project:         CS 116A Homework #4
* File:            splineReader.h
* Purpose:         Implement a curve drawing algorithm
* Start date:      11/10/13 
* Programmer:      Zane Melcho 
* 
****************************************************** 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "cvec.h"

using namespace std;

// Forward declarations


class splineReader
{
	// This class reads a .txt file that contains spline points
	// in the folowing format:
	// x1-float,z1-float
	// x2-float,z2-float

public:
	static Cvec3* parseSplineFile(string filename, int *numOfObjects);

private:
	static Cvec3 parseCvec(string spline);
	static void printCvec(Cvec3 splinePoint);
};
/*-----------------------------------------------*/
Cvec3* splineReader::parseSplineFile(string filename, int *numOfObjects)
{
	/*	PURPOSE:    	Reads file and assigns spline points to array of Cvec3's 
		RECEIVES:		filename - string address of file to be read location 
		RETURNS:    	Cvec3 array that holds all spline points read from file 
		REMARKS:    	Precondition: filename must be valid
							Precondition: first line is number of points
	*/

	int count = 0;
	Cvec3 *splineArray = NULL;
	ifstream splineFile (filename);
		
	//Process file
	string spline = "";
	if (splineFile.is_open())
	{
		// Setup array
		string numOfPoints = "";
		getline(splineFile, numOfPoints);
		int size = size = atoi(numOfPoints.c_str());
		splineArray = new Cvec3[size];
			
		int index = 0;
		while (getline(splineFile, spline))
		{
			//cout << spline << endl; // Check spline is created correct
			splineArray[index] = parseCvec(spline);
			//printCvec(splineArray[index]); // Check Cvec is stored correct
			index++;
			count++;
		}
		splineFile.close();
	}
	else
		cout << "Could not open " << filename << endl;

	*numOfObjects = count;

	return splineArray;
}
/*-----------------------------------------------*/
Cvec3 splineReader::parseCvec(string spline)
{
	/* PURPOSE:			Converts string into Cvec3 
		RECEIVES:   	spline - string that contains Cvec coordinates 
		RETURNS:    	Cvec3 that contains parsed points of the spline
		REMARKS:			Precondition:	string format must be x1-float,z1-float
	*/
		
	float x = 0;
	float z = 0;
	
	// Split into two tokens
	string delimiter = ",";
	unsigned int comma = spline.find(delimiter);
	if (comma != -1)
	{
		string tokenX = spline.substr(0, comma);
		string tokenZ = spline.substr(comma + 1);
	
		// Convert tokens to floats
		x = atof(tokenX.c_str());
		z = atof(tokenZ.c_str());
	}
	else
	   cout << "Bad line: Using <0, 0, 0>" << endl;

	return Cvec3(x, 2, z);
}
/*-----------------------------------------------*/
void splineReader::printCvec(Cvec3 splinePoint)
{
	/* 	PURPOSE:	Prints the Cvec3 
		RECEIVES:	splinePoint - The Cvec3 to be printed. 
	*/

	float x = splinePoint[0];
	float y = splinePoint[1];
	float z = splinePoint[2];

	cout << "<" << x << ", " << y << ", " << z << ">" << endl;
}
