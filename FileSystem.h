/**
	@file FileSystem.h
	@author Eric Goldfien
	@date July 21, 2014
	@brief this is the header file for the OFile class
	all functions are declared and defined in this file
*/


#include <iostream>
#include <fstream>
#include <string>


/**
	@class OFile
	@brief contains a file and constructors and destructors auto open and close the file
	keeping in best practices for file writing, overloads << operator for ease of use
*/
class OFile
{

public:

	//Constructor:

	/**Opens a file name with the string passed in as the name, gives error if file can't be opened
		@param filename is the string denoting the name of the file to be opened
	*/
	OFile(std::string filename)
	{
		file.open(filename);
		if (file.fail()) throw std::runtime_error("Error: cannot open file");
	}


	//Operators:

	/**Overloads << outputs any object with << defined to the opened file
		@param p is the object to be added to the file
	*/
	template<typename T>
	OFile& operator<<(const T& p)
	{
		file << p;
		return *this;
	}


	//Destructor:

	/**Closes the file when OFile object deleted from the stack*/
	~OFile() { file.close(); }


private:
	std::ofstream file;
};