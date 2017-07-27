/*************************************************************
File Names: tsupoddriver_a00643150.cpp, tsupod.cpp,
tsupod.h song.h, song.cpp
Files Included in: tsupod3_a00643150.zip
Author: Jordan Williamson
Date: 4/21/2015
Problem Number: 7
CS 2308 Spring 2015
Instructor: Priebe, Roger

TsuPod is a smaller version of the iPod. It performs
various functions such as storing songs, sorting, shuffling,
adding, removing, calculating memory. Additionally,
overloaded operators are used for object comparisons.
All songs are stored within a linked list by the use of pointers.
***************************************************************/
#ifndef SONG_H
#define SONG_H

#include <cstring>
#include <sstream>

class Song
{
private:
    std::string title;
    std::string artist;
    int fileSize;
public:
    Song();
    Song(std::string a, std::string t, int s)
    { artist = a; title = t; fileSize = s; };
    ~Song();

    std::string getSong() const;
    std::string getArtist() const;
    int getFSize() const;

    void setSong(std::string _title);
    void setArtist(std::string _artist);
    void setFSize(int _fileSize);

    bool operator >(const Song &rhs);
    bool operator <(const Song &rhs);
    bool operator ==(const Song &rhs);

};
#endif

