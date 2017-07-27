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
#include "song.h"

//Default Constructor
Song::Song()
{
    title = "";
    artist = "";
    fileSize = 0;
}

Song::~Song()
{
    title = "";
    artist = "";
    fileSize = 0;
}


bool Song::operator==(const Song &rhs)
{
    if (artist != rhs.getArtist())
        return false;
    if (title != rhs.getSong())
        return false;
    if (fileSize != rhs.getFSize())
        return false;
    else
        return true;
}

bool Song::operator>(const Song &rhs)
{

    if (getArtist() != rhs.getArtist())
    {
       return getArtist() > rhs.getArtist();
    }
    if (getSong() != rhs.getSong())
    {
        return getSong() > rhs.getSong();
    }
    return getFSize() > rhs.getFSize();
}

bool Song::operator<(const Song &rhs)
{
    if (getArtist() !=rhs.getArtist())
    {
       return getArtist() < rhs.getArtist();
    }

    if (getSong() != rhs.getSong())
    {
        return getSong() < rhs.getSong();
    }
    return getFSize() < rhs.getFSize();
}

std::string Song::getSong() const
    {   return title; };

void Song::setSong(std::string _title)
    {   title = _title; };

std::string Song::getArtist() const
    {   return artist;  };

void Song::setArtist(std::string _artist)
    {   artist = _artist;  };

int Song::getFSize() const
    {   return fileSize;   };

void Song::setFSize(int _fileSize)
{   fileSize = _fileSize;   };
