// Title: Lab 1 - FileProcessing.cpp
//
// Purpose: To take input from user and to open, read, and close input file. Then send each line to
// Formatting.cpp to format as CSV. Then open output file and write formatted lines to that file.
//
// Class: CSC 2430 Winter 2022
// Author: Christian Case Wright
// The following code is from my authorship with the exception of the
// code provided by the instructors of this course.

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

#include "Formatting.h"
#include "FileProcessing.h"


// Operates in a loop so multiple files can be processed.
// On each iteration, reads name of input and output files from user and opens them
// Then calls ProcessFile to do the actual file processing
// - If user enters a blank line for the input file, loop ends
// - If either file cannot be opened, loop restarts
//
// Parameters:
//      none
// Returns:
//      nothing


void ProcessFiles()
{
    // declares if and of stream
    ifstream in;
    ofstream out;

    // Declares string variables that hold the input from user (i.e. Presidents.json)
    string inputFile;
    string outputFile;

    // Asks for user input and runs program as long as user does not enter a blank

    do
    {

        //clears input and output files
        inputFile.clear();
        outputFile.clear();

        // verifies files are closed at the beginning of the iteration of the loop
        in.close();
        out.close();

        cout << "Input File Name:";
        getline(cin, inputFile);

        // ends loop if user doesn't input anything
        if(inputFile.empty())
            break;

        // sets boolean variables (used to verify if files are open)
        bool iOpen = false;
        bool oOpen;

        // checks to see if file entered is a json file otherwise continues with asking for output file
        if (inputFile.find(".json") == string::npos) {

            cout << "The file you entered " << inputFile << " is not in json format.\n";

        }
        else
        {
            // trys to open input file, if it  can't, loops and asks for a new input
            in.open(inputFile);
            if (!in.is_open()) {
                cout << "Error opening " << inputFile << ".\n";

                iOpen = false;
            }
            else
            {
                // takes output file name and verifies it can open
                iOpen = true;

                cout << "Output File Name:";
                getline(cin, outputFile);

                // ends loop if user doesn't input anything
                if(outputFile.empty())
                    break;

                out.open(outputFile);
                if (!out.is_open())
                {
                    cout << "Error opening " << outputFile << ".\n";

                    oOpen = false;
                }
                else
                {
                    oOpen = true;
                }

            }
        }

        // checks to make sure both input and output files are open then runs the program
        if(iOpen && oOpen)
        {
            // initializes variables
            string line;
            int totalAge = 0;
            int age, minAge = 99999, maxAge = 0, lines = 0;

            // prints csv header to the file
            out << CSVHeader() << endl;



            // gets each line and sends it to FormatAsCSV to format the prints to file line by line
            while(getline(in, line))
            {
                out << FormatAsCSV(line) << endl;


                // converts age to int and finds minimum and maximum age
                age = std::stoi(GetAge(line));
                if(age < minAge)
                {
                    minAge = age;
                }
                if (age > maxAge)
                {
                    maxAge = age;
                }

                totalAge += age;
                lines += 1;


            }

            cout << "Minimum Age: " << minAge << endl;
            cout << "Maximum Age: " << maxAge << endl;
            cout << "Average Age: " << totalAge / lines << endl;


        }
    }
    while(!inputFile.empty() || !outputFile.empty());

}
