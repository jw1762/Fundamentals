/****************************************************
File Name: prog2_A00643150.cpp

Author: Jordan Williamson
Date: 2/9/2015
Problem Number: 2
CS 2308 Spring 2015
Instructor: Priebe

A program consisting of 4 functions which reads grades from
a file input and compares them with the answer key, then finds
the average, highest, lowest, and grades for all students.
*****************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int gradeExam(char ansKey[], int QUESTIONS, string studentAnswers[], int numStudents);

int highestScore(int studentScore, int highScore);
int lowestScore(int studentScore, int lowScore);
double averageScore(double meanScore, int numStudents);

int main()
{
    const int QUESTIONS = 10;

    ifstream inFile;
    ofstream outFile;
    inFile.open("grade_data.txt");
    outFile.open("grade_report.txt");

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

    int howMany[QUESTIONS+1];
    for (int i = 0; i < QUESTIONS+1; i++)
    {
        howMany[i] = 0;
    }

//Loop to read in all student answers and count number of students.
    while (!inFile.eof())
    {
        inFile >> studentAnswers[numStudents];
        outFile << "Student " << numStudents+1 << " - " << gradeExam(ansKey, QUESTIONS, studentAnswers, numStudents) << endl;

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

//Function call to average the accumulated scores.
    meanScore = averageScore(meanScore, numStudents);

    outFile << endl;
    outFile << "Final Report" << endl;
    outFile << "------------\n" << endl;
    for (int k = QUESTIONS; k >= 0; k--)
    {
        int j = 0;
        outFile << k << " - " << howMany[k] << endl;
        j++;
    }

    outFile << endl;
    outFile << "Highest Score is: " << highScore << endl;
    outFile << "Lowest Score is: " << lowScore << endl;
    outFile << "Average Score is: " << meanScore << endl;

    cout << "All grade data has been written to 'grade_report.txt'." << endl;

    inFile.close();
    outFile.close();

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
