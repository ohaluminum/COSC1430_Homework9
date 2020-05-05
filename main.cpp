#include "SpecialArray.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
 *You will fill in the code for the measureLines and measureElementsPerLine functions, 
 *which count the number of rows in the file and the number of elements per row, respectively.
 *You may assume that all rows will have the same number of elements, 
 *and that the ifstream variable will be associated with an open file already when it is passed to these two functions.
 *
 *Add throw clause in the above two functions.
 *In particular, if a file associated with an ifstream variable passed to the above two functions does not exist, 
 *they will throw a run_time error which says "File does not exist." 
 *If these functions are passed an ifstream variable for an empty file, 
 *they will throw a run_time error which says "File is empty."
 */
int measureElementsPerLine(ifstream& inFile) 
{
    string line;
    int elementPerLine = 0;
    istringstream inSS;
    string subline;

    if (!inFile.is_open())
    {
        throw runtime_error("File does not exist.");
    }

    if (inFile.peek() == EOF)
    {
        throw runtime_error("File is empty.");
    }
    
    getline(inFile, line);
    inSS.str(line);

    while (inSS >> subline) 
    {
        elementPerLine++;
    }

    return elementPerLine;
}

int measureLines(ifstream& inFile) 
{
    string line;
    int numLine = 0;

    if (!inFile.is_open())
    {
        throw runtime_error("File does not exist.");
    }

    if (inFile.peek() == EOF)
    {
        throw runtime_error("File is empty.");
    }

    while (!inFile.eof())
    {
        getline(inFile, line);
        numLine++;
    }

    return numLine;
}

int main()
{
    int numOfLines, numOfElements;
    string fileName, dataType;
    cin >> fileName >> dataType;
    ifstream inFile(fileName);

    try
    {
        numOfElements = measureElementsPerLine(inFile);
        inFile.close();
        inFile.open(fileName);
        numOfLines = measureLines(inFile);
        inFile.close();

        if (dataType == "int") 
        {
            SpecialArray<int> specialArray(numOfLines, numOfElements);
            inFile.open(fileName);
            specialArray.readFile(inFile);
            inFile.close();
            specialArray.print();
            specialArray.sort();
            cout << "\nSorted outputs: \n";
            specialArray.print();
        }
        else if (dataType == "string") 
        {
            SpecialArray<string> specialArray(numOfLines, numOfElements);
            inFile.open(fileName);
            specialArray.readFile(inFile);
            inFile.close();
            specialArray.print();
            specialArray.sort();
            cout << "\nSorted outputs: \n";
            specialArray.print();
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }

	return 0;
}
