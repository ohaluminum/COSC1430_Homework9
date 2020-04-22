# COSC1430_Homework9


### Pointer &amp; Dynamic 2D-Array &amp; File Streams &amp; Template Classes &amp; Bubble Sort

:exclamation::grey_exclamation:This Homework shows how to correctly declare and deallocate 2D array!!!

:paperclip:Also show how to do bubble sort and how to detect empty file and throw exception!!! 

> In this homework, you will be using a template class to read in data from an input file and manipulate it. Here is an example of an input file:
```
aa bb cc 
dd ee ff 
gg hh ii 
jj kk ll 
```
> In the above example of an input file, there are 4 rows and 3 elements per row. Input files will store either strings or integers. Rows will be on different lines and all elements will be separated by a space.

#### SpecialArray

> Your template class will be called SpecialArray.

*private:*

- A pointer for a 2D dynamic array. The pointer will be of templated type.

- An integer variable for the number of rows in an input file.

- An integer variable for the number of columns in an input file (AKA the number of elements per row).

*public:*

- A default constructor that sets the array pointer to null and both numbers of rows and columns to zero.

- A constructor which takes two integer parameters for the numbers of rows and columns in an input file.

- A destructor that properly release the memory allocated to the array.

- A function called readFile to read the elements in from an input file and store them in your 2D dynamic array. 

> This function will take the ifstream variable as a parameter (assume the variable already has an associated file open).

> I have open/closed the file in main/unit tests, so you will not need to worry about that.

- A function called max with empty argument list that returns the value of the maximum element in the array.

- A function called min with empty argument list that returns the value of minimum element in the array.

- A function called sort with empty argument list which sorts each row in the array 

> Each individual row will be sorted from smallest to largest, with each element staying in its original row and each row staying in its original position.

- A function called print with empty argument list which print's the contents of the 2D dynamic array to the display. 

> Elements in a row should be separated by spaces, and each row should be on a new line (just like in the input file).

- A function called saveToFile with empty argument list which outputs the contents of the 2D dynamic array, formatted as above, to a file called "output.txt".

#### Main

- You will fill in the code for the measureLines and measureElementsPerLine functions.

> Which count the number of rows in the file and the number of elements per row, respectively. 

> You may assume that all rows will have the same number of elements, and that the ifstream variable will be associated with an open file already when it is passed to these two functions.

- Add throw clause in the above two functions.

> If a file associated with an ifstream variable passed to the above two functions does not exist, they will throw a run_time error which says "File does not exist." 

> If these functions are passed an ifstream variable for an empty file, they will throw a run_time error which says "File is empty."

- Add try-catch construct in the main() as indicated. Do not alter main outside of the areas which are commented for you.
