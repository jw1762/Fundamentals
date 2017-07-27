/****************************************************
File Names: TsuPodDriver.cpp, TsuPod.cpp, TsuPod.h,
Song.h, Song.cpp
Files Included in: tsuPod2_A00643150.zip
Author: Jordan Williamson
Date: 4/7/2015
Problem Number: 6
CS 2308 Spring 2015
Instructor: Priebe, Roger

TsuPod is a smaller version of the iPod. It performs
various functions such as storing songs, sorting, shuffling,
adding, removing, calculating memory. Additionally,
overloaded operators are used for object comparisons.
*****************************************************/
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
    bool operator ==(const Song &rhs);

};
#endif

