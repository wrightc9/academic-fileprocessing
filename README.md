# File Processing

## Goal:
Your assignment is to write a C++ program that reads a "people file" in JSON format writes it out to a file in CSV format.  In addition, your program will also find the minimum, maximum, and average ages of the people in the file and display that to the user.

### What is JSON?
JSON (JavaScript Object Notation) is a text format for representing a collection of attribute-value pairs, see *https://en.wikipedia.org/wiki/JSON*.  For this assignment each line of the input file will be written in JSON, and it will represent the following information about a person: first name, last name, age, height, and nationality.  For instance, the actor Tom Holland could be represented the line:

```
{ "FirstName":"Tom", "LastName":"Holland", "Age": 25,  "Height":68,"Nationality":"English"  }
```

You will be able to assume that the JSON is correctly formatted, it contains no line breaks, and only contains string and number values.  But you should not assume all attributes are present, nor should you make any assumptions about the order the attribute-value pairs appear.

Here's a screenshot of the file *Spiderman.json":

![image](https://user-images.githubusercontent.com/58283777/147619188-61003fba-da63-41f3-b8d5-e75ac19bfc41.png)

Note that because the actress Zendaya goes by one name, only the *FirstName* attribute appears.

### What is a CSV file?
A CSV (comma-separated values) file is a text file that uses a comma to separate values. The first line of a CSV file contains the names of the attributes separated by commas.  Each subsequent line contains the values for one record separated by commas.  The order of the values correspond to the order of the attributes in the first line.  The first line of the CSV files you will produce will contain:
```
FirstName,LastName,Age,Height,Nationality
```

The line representing the actor Tom Holland would contain:
```
Tom,Holland,25,68,English
```

Here's a screenshot of "Spiderman.csv" that was produced from "Spiderman.json":

![image](https://user-images.githubusercontent.com/58283777/147619274-3bcb01a6-c543-4564-b3c1-06fc1812d353.png)

Pay attention to how no characters appear between the commas for the last name of Zendaya.

### A sample run   
Here's what a run of your program should look like:

![image](https://user-images.githubusercontent.com/58283777/147398604-626dff7c-5aec-4a06-adb0-f1d10422394d.png)

The program begins by calling a *unit test* (already written for you in function `TestFormatting()`) to check whether the code for converting a line of JSON into a line of CSV is working correctly.
After passing validation successfully, the program enters a loop.  On each loop iteration the user can specify a JSON-formatted file that the person wants to be written to a CSV file.

At the start of the loop, the user is prompted for the name of a JSON-formatted file.  There are special cases that need to e handled:

1) If a blank line is entered, the loop ends and the program terminates. 
2) If the file cannot be opened for reading, an error message is printed and the loop restarts.

If, however, the file can be opened for reading, the program will prompt for the name of an output file.  If the file can be opened, the program will read each line of the input file, format it as CSV, and write it to the output files.   On the other hand, if the file cannot be opened for writing, the program will print an error message and restart the loop to try again.

**Warning**: Remember that the a line in the JSON file might not include all the fields that are used. Like the case of the record containing Zendaya.

### Repo Layout

The supplied repo consists 6 files:

1)  `main.cpp`   This file invokes the *unit test*, and then call the function `ProcessFiles` which you will implement.  This file been fully implemented for you and should not be modified.

2)  `FileProcessing.h`  This file declares the function that launches the core function of the program when called by the `main` program:

```
void ProcessFiles();
```

  This file has been implemented for you and should not be modified.

3)  `FileProcessing.cpp` This file is where you will place all code involved with file handling (prompting user for file names, opening files, closing files, reading a line from a file, writing a line to a file, finding and displaying the min, max and average age, and printing error messages).  Your code should call into the functions declared in `Formatting.h` to format lines into CSV and to get the age of a person.  

  It would be poor style to put all the file handling logic into one C++ function.  Try to isolate some of the logic into at least one subfunction.

4)  `Formatting.h`  This file declares three functions that your code in `FileProcessing.cpp` should use:

```
string CSVHeader();
string FormatAsCSV(string json);
string GetAge(string json);
```

> Best programming practices require modifying the declaration of the `json` parameter for `FormatAsCSV` and `GetAge`.  Given that neither function should modify `json`, change its declaration appropriately.   No other modifications should be made to this file.
  
5)  `Formatting.cpp`  This file contains the implementation of the three functions declared in `Formatting.h`.   Good style here calls for you to define at least two subfunctions for your implementation.  

6) `CMakeList.txt`   CLion uses this file to compile and link a program that can be executed.  This file **should not** be modified.

## What is expected
- Your code ***must*** compile.
- Your code ***must not*** compile with warnings.
- Your program ***must not*** crash.
- Every source file must contain header comments with the following format:
 ```
// Title: Lab 1 - name-of-file.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>
// The following code is from my authorship with the exception of the
// code provided by the instructors of this course.

 ```
- The program will be tested with the given files, and with additional files. Your grade will be calculated based on the screen output and file output. Your outputs must be identical to the given outputs.
- Your code needs to show good programming practices: 
  - appropriate amount of comments for your functions/methods,
  - indentation,
  - meaningful variable names,
  - identifiers convention (CamelCase for functions, camelCase for variables, _camelCase for data members, SNAKE_CASE for constants),
  - header comments, 
  - correct file names, etc. 

Failure to code appropriate will result in strong points penalization.
Check Canvas page: Good Programming Practices for a thorough list of good programming practices that you are expected to follow.

## Grading
| Item |    Points |
|------|----------:|
| Unit Tests are passed: VALIDATION SUCCEEDS |        45 |
| File Reading, opens the file |         5 |
| Validates File Not Found |         5 |
| Validates Incorrect format |         5 |
| Calculates Minimum, Maximum and Average age |        25 |
|Loops to ask for more file names |         5 |
| Stops when entered an empty file name (just hit enter on the Input File Name prompt |        10 |

Deductions
- For each infraction on good programming practices there will be a deduction of 2 points
- If the program has a runtime error (the program crashes) there will be a deduction of 10 points
- If the program does not have comment headers there will be a deduction of 5 points
- If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
- If the program does not follow instructions, for instance if you did not implement `GetAge` function, there will be a deduction of 5 points per ignored instruction

*You* can autograde your own assignment!
1. If you run the program, and it does not pass the unit tests, your grade would be zero
2. If you passed the unit tests (You got the **VALIDATION SUCCEEDS** message), you would have 45 points
3. If your program asks for a file that does not exist, and reports the error without crashing, you have an additional 5 points. If your program crashes, then you would lose 5 points and an additional 10 per the runtime error.
4. If your program asks for a file that is not in JSON format, and reports the error without crashing, you have an additional 5 points. If your program crashes, then you would lose 5 points and an additional 10 per the runtime error.
5. If your program calculates the minimum, maximum and average age correctly, you would have an additional 25 points.
6. If, after processing a file, your program loops and asks for an additional filename and it continues to work correctly, you would get an additional 5 points.
7. If the program stops correctly when the user just hits enter on the Input File Name prompt, you would get the last 5 points.

### Some possible grading scenarios

#### Example 1

```
SEGMENTATION FAULT
```
Grade Analysis:
- This program didn't even show the VALIDATION SUCCEEDS message, grade = 0


#### Example 2

```
VALIDATION SUCCEEDS
Input File Name: FileThatIsNotHERE
ERROR: FileThatIsNotHERE not found
Input File Name: FileNOTinJsonFormat.txt
ERROR: Incorrect file format, please provide a JSON file
Input File Name: presidents.json
Output File Name: presidents.csv
Minimum age: 76
Maximum age: 90
Average age: 79.6
Input File Name: AnotherCorrectJSONfile.json
Output File Name: anotherone.csv
Minimum age: 11
Maximum age: 11
Average age: 11
Input File Name:

```
Grade Analysis
- VALIDATION SUCCEEDS: 45 points
- Validates File Not Found: 5 points
- Validates Incorrect file format: 5 points
- Opens the file correctly: 5 points
- Calculates minimum, maximum and average correctly: 16 (minimum is incorrect)
- Loops to ask for additional file names: 5 points
- Stops when entered an empty file name: 10 points

Final grade: 91

#### Example 3

```
VALIDATION SUCCEEDS
Input File Name: FileThatIsNotHERE
-- CRASHED --
```

Run Again
```
VALIDATION SUCCEEDS
Input File Name: FileNOTinJsonFormat.txt
-- CRASHED --

```

Run Again
```
VALIDATION SUCCEEDS
Input File Name: presidents.json
Output File Name: presidents.csv
Minimum age: 67
Maximum age: 90
Average age: 79.6
Input File Name: AnotherCorrectJSONfile.json
Output File Name: anotherone.csv
Minimum age: 11
Maximum age: 11
Average age: 11
Input File Name:
```
Grade Analysis
- VALIDATION SUCCEEDS: 45 points
- Validates File Not Found: 0 points
- Program crashed: -10
- Validates Incorrect file format: 0 points
- Program crashed: NO ADDITIONAL MARK DOWN
- Opens the file correctly: 5 points
- Calculates minimum, maximum and average correctly: 25
- Loops to ask for additional file names: 5 points
- Stops when entered an empty file name: 10 points

Final grade: 90 - 10 = 80





