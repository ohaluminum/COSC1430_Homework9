#include <iostream>

#ifndef SpecialArray_H
#define SpecialArray_H

template<typename T>
class SpeialArray
{
private:
	T** 2DArr;
	int numRow;
	int numCol;

public:

	//Default constructor: sets the array pointer to null and both numbers of rows and columns to zero.
	SpecialArray()
	{
		2DArr = nullptr;
		numRow = 0;
		numCol = 0;
	}

	//Overloaded constructor: takes two integer parameters for the numbers of rows and columns in an input file.
	SpecialArray(int row, int col)
	{
		numRow = row;
		numCol = col;

		2DArr = new T*[numRow];

		int** a = new int* [rowCount];
		for (int i = 0; i < rowCount; ++i)
			a[i] = new int[colCount];
	}

	//Destructor: properly release the memory allocated to the array.
	~SpecialArray()
	{
		delete[][] 2DArr;
		2DArr = nullptr;
	}







};

A function called readFile to read the elements in from an input fileand store them in your 2D dynamic array.This function will take the ifstream variable as a parameter(assume the variable already has an associated file open-- I have open / closed the file in main / unit tests, so you will not need to worry about that.).
A function called max with empty argument list that returns the value of the maximum element in the array.
A function called min with empty argument list that returns the value of minimum element in the array.
A function called sort with empty argument list which sorts each row in the array(as in, each individual row will be sorted from smallest to largest, with each element staying in its original row and each row staying in its original position).
A function called print with empty argument list which prints / cout's the contents of the 2D dynamic array to the display. Elements in a row should be separated by spaces, and each row should be on a new line (just like in the input file).
A function called saveToFile with empty argument list which outputs the contents of the 2D dynamic array, formatted as above, to a file called "output.txt".


#endif

