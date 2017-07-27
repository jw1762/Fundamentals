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
#include "Song.h"

//Default Constructor
Song::Song()
{
    title = "";
    artist = "";
    fileSize = 0;
}

////Secondary Constructor
//Song::Song(string a, string t, int s)
//{
//    if (artist == "" || title == "")
//    {
//        return FAILURE;
//    }
//    if (s < 0)
//    {
//        return FAILURE;
//    }
//    else
//    {
//        artist = a;
//        title = t;
//        fileSize = s;
//        return SUCCESS;
//    }
//}

Song::~Song()
{
    title = "";
    artist = "";
    fileSize = 0;
}
//
//bool Song::operator >(Song const &rhs)
//   {
//      return (title < rhs.title);
//   }

bool Song::operator ==(const Song &rhs)
{
       if (rhs.title == title &&
           rhs.artist == artist &&
           rhs.fileSize == fileSize)
           {
               return true;
           }
           else
           return false;
}

bool Song::operator >(const Song &rhs)
{
    if (artist < rhs.artist)
    {
        if (title < rhs.title)
        {
            if (fileSize < rhs.fileSize)
            {
                return true;
            }
        }
    }
    return false;
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
