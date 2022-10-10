// Title: Lab 1 - Formatting.cpp
//
// Purpose: To take lines from a fileproccessing that is in json format and converts it to CSV format before returning it
//
// Class: CSC 2430 Winter 2022
// Author: Christian Case Wright
// The following code is from my authorship with the exception of the
// code provided by the instructors of this course.

#include <iostream>
#include <cassert>

#include "Formatting.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


// forward declaration
string PullInfo(const string& jLine);

// Returns CSV header as a string
//
// Parameters:
//      None
// Returns:
//      CSV header
string CSVHeader()
{
    string cHeader = "FirstName,LastName,Age,Height,Nationality";

    return cHeader;
}

// Converts one JSON formatted line to CSV, returning the CSV
// representation as a string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      CSV formatted line
string FormatAsCSV(const string& json)
{
    string cLine;
    string jLine = json;

    // get rid of spaces before sending to pull info
    for(size_t i = 0; i < jLine.length(); i ++)
    {
        if (isspace(jLine[i]))
        {
            jLine.replace(i, 1, "");
        }
    }

    cLine = PullInfo(jLine);

    // get rid of quotations in formatting
    for(size_t i = 0; i < cLine.length(); i ++)
    {
        if(cLine[i] == '"')
        {
            cLine.replace(i,1,"");
        }
    }
    return cLine;
}

// Return the age value stored in a JSON
// formatted line.  The return value is a string
// If age doesn't appear, returns empty string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      age as string, or empty if age doesn't appear

string GetAge(const string& json)
{
    string age;
    size_t position;

    position = json.find(':',json.find("Age"));
    if(position == string::npos)
    {
        age = "";
    }
    else
    {
        age = json.substr(position + 1, json.find('"',position + 2) - position - 1 );
    }

    return age;
}

// Return the json formatted line in csv format as a string
//
// Parameters:
//      jLine - JSON formatted line
// Returns:
//      json formatted line as a string
string PullInfo(const string& jLine)
{
    size_t position;
    string first, last, age, height, nation;
    string cLine;

    position = jLine.find(':',jLine.find("FirstName"));
    if(position == string::npos)
    {
        first = "";
    }
    else
    {
        first = jLine.substr(position + 1, jLine.find('"',position + 2) - position - 1 );
    }

    position = jLine.find(':',jLine.find("LastName"));
    if(position == string::npos)
    {
        last = "";
    }
    else
    {
        last = jLine.substr(position + 1, jLine.find('"',position + 2) - position - 1 );
    }

    position = jLine.find(':',jLine.find("Age"));
    if(position == string::npos)
    {
        age = "";
    }
    else
    {
        age = jLine.substr(position + 1, 3);

        for(size_t i = 0;i < 3; i++ )
        {
            if (!std::isdigit(age[i]))
                age.replace(i,1,"");
        }
    }

    position = jLine.find(':',jLine.find("Height"));
    if(position == string::npos)
    {
        height = "";
    }
    else
    {
        height = jLine.substr(position + 1, 3);

        for(size_t i = 0;i < 3; i++ )
        {
            if (!std::isdigit(height[i]))
                height.replace(i,1,"");
        }
    }

    position = jLine.find(':',jLine.find("Nationality"));
    if(position == string::npos)
    {
        nation = "";
    }
    else
    {
        nation = jLine.substr(position + 2, jLine.find('"',position + 2) - position - 1 );
    }

    cLine = first + ',' + last + ',' + age + ',' + height + ',' + nation;

    return cLine;
}