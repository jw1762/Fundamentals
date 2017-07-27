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
#ifndef TSUPOD_H
#define TSUPOD_H

#include "Song.h"

class TsuPod
{
private:
    int memSize; //Total memory size used.
    int numSongs; //Current number of songs.
    static const int MAX_SIZE = 256;//In MB.
    static const int MAX_SONGS = 25;//Total max allowed songs.
    Song songs[MAX_SONGS]; //Array of songs.
public:
    TsuPod();//Constructor
    ~TsuPod();//Destructor
    TsuPod(int);
    int addSong(Song s);
    int removeSong(Song s);
    void shuffle();
    void showSongList();
    void sortSongList();
    int getTotalMemory();
    int getRemainingMemory();

    static const int SUCCESS = 1;
    static const int FAILURE = -1;
};

#endif
