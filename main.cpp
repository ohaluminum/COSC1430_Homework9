#include "SpecialArray.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int measureElementsPerLine(ifstream& inFile) {
   // Add your code here.
}

int measureLines(ifstream& inFile) {
   // Add your code here.
}

int main()
{
	int numOfLines, numOfElements;
	string fileName, dataType;
	cin >> fileName >> dataType;
   ifstream inFile(fileName);

   // Add try statement below
   
   
	numOfElements = measureElementsPerLine(inFile);
	inFile.close();
	inFile.open(fileName);
	numOfLines = measureLines(inFile);
	inFile.close();

   if (dataType == "int"){
      SpecialArray<int> specialArray(numOfLines, numOfElements);
      inFile.open(fileName);
	   specialArray.readFile(inFile);
	   inFile.close();
   	specialArray.print();
   	specialArray.sort();
   	cout << "\nSorted outputs: \n";
   	specialArray.print();
   }
	else if (dataType == "string"){
      SpecialArray<string> specialArray(numOfLines, numOfElements);
      inFile.open(fileName);
	   specialArray.readFile(inFile);
   	inFile.close();   
   	specialArray.print();
   	specialArray.sort();
   	cout << "\nSorted outputs: \n";
   	specialArray.print();
	}

	// Add catch statement below
	
	

	return 0;
}