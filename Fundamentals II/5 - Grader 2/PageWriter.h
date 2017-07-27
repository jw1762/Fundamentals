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
#ifndef PAGEWRITER_H
#define PAGEWRITER_H

#include <cstring>
#include <fstream>
#include <sstream>

class PageWriter
{
    private:
        std::string fName;
        std::string title;
    public:
        std::ofstream outFile;
        PageWriter(std::string, std::string); //Default Constructor
        ~PageWriter();
        void newPage(std::string, std::string);
        void printStart();
        void header(int, std::string);
        void paragraph(std::string);
        void link(std::string, std::string);
        void blankLine();
        void horizontalLine(int, int);
        void printEnd();
};

#endif
