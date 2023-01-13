/**
	@file hw5.cpp
	@author Eric Goldfien
	@date July 21, 2014
	@brief this is my submission for HW5, this file contains main
	this program creates multiple Point2D and TPoint2D objects and adds them
	to a Points object which stores them, the Points object is then added to 
	a file called points.txt
*/

#include <iostream>
#include "Points.h"
#include "FileSystem.h"
#include <string>


int main()
{

	//Create points for storage
	Point2D p(1, 2);
	Point2D p2(12.432, 5.67);
	TPoint2D<std::string> p3(12.12, 23.23, "red");
	TPoint2D<int> p4(999.987, 111.123, 5);
	TPoint2D<char> p5(54345, 123432, 'B');
	TPoint2D<int> p6(1.23, 4.56, 0);
	TPoint2D<TPoint2D<std::string>> p7(11.11, 22.22, TPoint2D<std::string>(1, 2, "blue"));

	//Create a Points object to store all points and all the points in it are copied on the heap
	Points points;
	points += p;
	points += p2;
	points += p3;
	points += p4;
	points += p5;
	points += p6;
	points += p7;
 
	//Open a file called points.txt and add the Points object to it
	OFile fout("points.txt");
	fout << points;

	return 0;
}