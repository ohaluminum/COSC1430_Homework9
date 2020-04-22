#include <iostream>
#include <fstream>

using namespace std;

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

		//How to declare a dynamic 2D Array: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
		2DArr = new T*[numRow];
		for (int i = 0; i < numRow; i++)
		{
			2DArr[i] = new T[numCol];
		}
	}

	//Destructor: properly release the memory allocated to the array.
	~SpecialArray()
	{
		//How to deallocate dynamic 2D Array: http://www.cplusplus.com/forum/beginner/38226/
		for (int i = 0; i < numRow; i++)
		{
			delete[] 2DArr[i];
		}

		delete[] 2DArr;
		2DArr = nullptr;
	}

	/*
	 *A function called readFile to read the elements in from an input file and store them in your 2D dynamic array.
	 *This function will take the ifstream variable as a parameter (assume the variable already has an associated file open)
	 *I have open/closed the file in main/unit tests, so you will not need to worry about that.
   	 */
	void readFile(ifstream inFS)
	{
		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol; j++)
			{
				inFS >> 2DArr[i][j];
			}
		}
	}

	//A function called max with empty argument list that returns the value of the maximum element in the array.
	T max()
	{
		T max = 2DArr[0][0];

		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol; j++)
			{
				if (2DArr[i][j] > max)
				{
					max = 2DArr[i][j];
				}
			}
		}
		return max;
	}

	//A function called min with empty argument list that returns the value of minimum element in the array.
	T min()
	{
		T min = 2DArr[0][0];

		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol; j++)
			{
				if (2DArr[i][j] < min)
				{
					min = 2DArr[i][j];
				}
			}
		}
		return min;
	}

	/*
	 *A function called sort with empty argument list which sorts each row in the array
	 *For example, each individual row will be sorted from smallest to largest,
	 *with each element staying in its original row and each row staying in its original position.
	 */
	void sort()
	{
		T temp;

		for (int x = 0; x < numRow; x++)
		{
			for (int y = 0; y < numCol - 1; y++)
			{
				for (int z = 0; z < numCol - 1 - y; z++)
				{
					if (2DArr[x][z] > 2DArr[x][z + 1])
					{
						temp = 2DArr[x][z];
						2DArr[x][z] = 2DArr[x][z + 1];
						2DArr[x][z + 1] = temp;
					}	
				}
			}
		}
	}

	/*
	 *A function called print with empty argument list which print's the contents of the 2D dynamic array to the display. 
	 *Elements in a row should be separated by spaces, and each row should be on a new line (just like in the input file).
     */
	void print()
	{
		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol - 1; j++)
			{
				cout << 2DArr[i][j] << " ";
			}
			cout << 2DArr[i][numCol - 1] << endl;
		}
	}

	//A function called saveToFile with empty argument list which outputs the contents of the 2D dynamic array, formatted as above, to a file called "output.txt".
	void saveToFile()
	{
		ofstream outFS;
		outFS.open("output.txt");

		for (int i = 0; i < numRow; i++)
		{
			for (int j = 0; j < numCol - 1; j++)
			{
				outFS << 2DArr[i][j] << " ";
			}
			outFS << 2DArr[i][numCol - 1] << endl;
		}

		outFS.close();
	}
};



#endif

