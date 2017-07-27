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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdlib.h>
#include "PageWriter.h"

using namespace std;

int gradeExam(char ansKey[], int QUESTIONS, string studentAnswers[], int numStudents);
int highestScore(int studentScore, int highScore);
int lowestScore(int studentScore, int lowScore);
double averageScore(double meanScore, int numStudents);

int main()
{
    const int QUESTIONS = 10;

    ifstream inFile;
    inFile.open("grades.txt");
    if(!inFile)
    {
        cout << "Missing file. Terminating." << endl;
        return 0;
    }

    PageWriter newPage("grades_report.html", "Grade Report for CS2408");

    newPage.printStart();
    newPage.header(1, "Grade Report for CS2408");
    newPage.header(2, "Student Grades");

    int numStudents = 0;
    char ansKey[QUESTIONS];
    inFile >> ansKey;

    //Given that the average number of students in a class is less than 100,
    //this should be plenty. Unable to make array with an unknown size.
    string studentAnswers[250];

    int studentScore = 0;
    int lowScore = 0;
    int highScore = 10;
    double meanScore = 0;

    int howMany[QUESTIONS+1];//Plus 1, because it is possible to have 0 correct answers.
    for (int i = 0; i < QUESTIONS+1; i++)
    {
        howMany[i] = 0;
    }

//StringStream for use in making new paragraphs.
    stringstream ss;
    string newPara;

    newPage.horizontalLine(75, 10);

//Loop to read in all student answers and count number of students.
    while (!inFile.eof())
    {
        inFile >> studentAnswers[numStudents];

        ss << "Student " << numStudents+1 << " - " << gradeExam(ansKey, QUESTIONS, studentAnswers, numStudents) << endl;
        newPara = ss.str();
        //flush() was not operating correctly. This is an alternative method.
        ss.str(string());
        ss.clear();
        newPage.paragraph(newPara);

        //Assigns variable from grade results.
        studentScore = gradeExam(ansKey, QUESTIONS, studentAnswers, numStudents);

        //Determines how many students have answered a number of questions.
        howMany[studentScore]++;

        //Use previous variable to determine the high/low scores.
        highScore = highestScore(studentScore, highScore);
        lowScore = lowestScore(studentScore, lowScore);

        //Adding up the scores for averaging.
        meanScore += studentScore;
        numStudents++;
    }

    newPage.horizontalLine(50, 5);

//Function call to average the accumulated scores.
    meanScore = averageScore(meanScore, numStudents);

    newPage.outFile << endl;
    newPage.header(3, "Final Report");

    for (int k = QUESTIONS; k >= 0; k--)
    {
        newPage.outFile << k << " - " << howMany[k] << endl;
        newPage.blankLine();
    }

    newPage.outFile << endl;
    newPage.blankLine();
    newPage.outFile << "Highest Score is: " << highScore << endl;
    newPage.blankLine();
    newPage.blankLine();
    newPage.outFile << "Lowest Score is: " << lowScore << endl;
    newPage.blankLine();
    newPage.blankLine();
    newPage.outFile << "Average Score is: " << fixed << setprecision(2) << meanScore << endl;
    newPage.blankLine();

    cout << "All grade data has been written to 'grades_report.html'." << endl;

    inFile.close();

    newPage.blankLine();
    newPage.link("Here's a link to Penny Arcade!", "http://www.penny-arcade.com");
    newPage.horizontalLine(43, 3);
    newPage.printEnd();

    return 0;
}

//Function: gradeExam. Grades each students answers.
//Parameters:  Takes in the char array AnsKey, string array studentAnswers,
//the number of QUESTIONS (int) and the numStudents (int).
//Returns: Number of correct answers (rightAnswer).
int gradeExam(char ansKey[], int QUESTIONS, string studentAnswers[], int numStudents)
{
    int rightAnswer = 0;
    for (int l = 0; l < QUESTIONS; l++)
        {
            if (studentAnswers[numStudents][l] == ansKey[l])
            {
                rightAnswer++;
            }
        }

    return rightAnswer;
}

//Function: highestScore. Returns the students score which is highest.
//Parameters: int studentScore, their current score based off the prior function,
//and the current int highScore of all students.
//Returns: The new highScore out of all students.
int highestScore(int studentScore, int highScore)
{
    if (studentScore >= highScore)
        highScore = studentScore;

    return highScore;
}

//Function: lowestScore. Returns the students score which is lowest.
//Parameters: int studentScore, their current score based off the gradeExam function,
//and the current int lowScore of all students.
//Returns: The new lowScore out of all students.
int lowestScore(int studentScore, int lowScore)
{
    if (studentScore <= lowScore)
        lowScore = studentScore;

    return lowScore;
}

//Function: averageScore. Returns the average score out of all students
//Parameters: int meanScore, the current total of all scores.
//int numStudents, the total number of students/tests.
//Returns: The new average of all students, meanScore (int).
double averageScore(double meanScore, int numStudents)
{
    meanScore = meanScore/numStudents;

    return meanScore;
}
