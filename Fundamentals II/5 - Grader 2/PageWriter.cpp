/****************************************************
File Names: driver.cpp, PageWriter.cpp, PageWriter.h
Files Included in: grader2_A00643150.zip
Author: Jordan Williamson
Date: 3/25/2015
Problem Number: 5
CS 2308 Spring 2015
Instructor: Priebe, Roger

This program creates a .html file of student grades,
averages, and more. It accomplishes this by the use of
several functions, a class called PageWriter, and
StringStream. Which is amazing.
*****************************************************/
#include "PageWriter.h"

using namespace std;

//Constructor
PageWriter::PageWriter(string rcvFName, string rcvTitle)
{
    fName = rcvFName;
    title = rcvTitle;
    outFile.open(fName.c_str());
}

//Destructor
PageWriter::~PageWriter()
{
    outFile.close();
}

//Function: printStart. Prints the beginning HTML text to a webpage.
//Paramaters: None.
//Returns: None.
void PageWriter::printStart()
{
    outFile << "<html>" << endl;
    outFile << "<head>" << endl;
    outFile << "<title>" << title << "</title>" << endl;
    outFile << "</head>" << endl << endl;
}

//Function: header. Makes a header for the webpage.
//Parameters: hSize (int), the desired header size. hText(string),
//the text of the header to be displayed.
//Returns: None.
void PageWriter::header(int hSize, string hText)
{
    outFile << "<h" << hSize << ">" << hText << "</h" << hSize << ">" << endl;
}

//Function: printParagraph. Prints out the HTML and paragraph.
//Paramaters: paraStream, a string consisting of our student scores, etc.
//Returns: None.
void PageWriter::paragraph(string pStream)
{
    outFile << "<p>" << pStream << "</p>";
}

//Function: link. Creates a hyperlink on the webpage.
//Parameters: linkText, the displayed text for the hyperlink.
//target, the URL for the link.
//Returns: None.
void PageWriter::link(string linkText, string target)
{
    outFile << "<a href=\"" << target << "\">" << linkText << "</a>" << endl;
}

//Function: blankLine. Creates a blank line on the webpage.
//Parameters: None.
//Returns: None.
void PageWriter::blankLine()
{
    outFile << "<br>" << endl;
}

//Function: horizontalLine. Creates a horizontal line on the webpage.
//Parameters: pctWidth (int). Percentage of the desired width.
//numPixels (int). Number of desired pixels.
//Returns: None.
void PageWriter::horizontalLine(int pctWidth, int numPixels)
{
    outFile << "<hr style=\"width: " << pctWidth << "%;" << "height: " << numPixels << "px;\">" << endl;
}

//Function: printEnd. Prints out the ending HTML for the webpage.
//Paramaters: None.
//Returns: None.
void PageWriter::printEnd()
{
    outFile << "</body>" << endl;
    outFile << "</html>" << endl;
}
