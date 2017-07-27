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
#include "TsuPod.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Default Constructor
TsuPod::TsuPod()
{
    memSize = 0;
    numSongs = 0;
}

//Secondary Constructor
TsuPod::TsuPod(int _fileSize)
{
     if (_fileSize > MAX_SIZE)
     {
         memSize = MAX_SIZE;
     }

     else
     {
         memSize = memSize + _fileSize;
     }
}

//Destructor
TsuPod::~TsuPod()
{
    memSize = 0;
    numSongs = 0;
}

//Function: AddSong. Adds a song into our array.
//Parameters: Takes in a single song, 's', of class Song.
//Output: Either -1 (Failure), or 1 (Success).
int TsuPod::addSong(Song s)
{
    //Check for remaining storage space.
    getTotalMemory();
    getRemainingMemory();
    //Failure if size exceeds 256MB (max).
    if (s.getFSize() < 0 || (memSize + s.getFSize()) > MAX_SIZE)
    {
        return FAILURE;
    }
    //Failure if missing artist or title.
    if (s.getArtist() == "" || s.getSong() == "")
    {
        return FAILURE;
    }

    else
    {
        for(int i = 0; i < MAX_SONGS; i++)
        {
            if(songs[i].getFSize() == 0)
            {
                songs[i] = s;
                numSongs++;
                return SUCCESS;
            }
        }
    }

}

//Function: removeSong. Removes a song from our array of songs.
//Paramaters: A single song, 's', of class Song.
//Output: 1 for SUCCESS, -1 for FAILURE.
int TsuPod::removeSong(Song s)
{
    getTotalMemory();
    for(int i = 0; i < MAX_SONGS; i++)
    {
        if(songs[i] == s)
            {
                songs[i] = songs[numSongs-1];
                numSongs--;
                getRemainingMemory();
                return SUCCESS;
            }
        else
            return FAILURE;
    }
}

//Function: showSongList. Shows the array of songs currently stored.
//Parameters: None.
//Output: None.
void TsuPod::showSongList()
{
    cout << "---Current Stored Songs---" << endl;
    for (int i = 0; i < numSongs; i++)
    {
        if (songs[i].getFSize() > 0)
        {
            cout << i+1 << " - " << songs[i].getArtist() << " - " << songs[i].getSong()
            << " - " << songs[i].getFSize() << "MB" << endl;
        }
    }
    cout << "---End of Current Stored Songs---" << endl << endl;
}

//Function: Shuffle. Shuffles the array of songs into random order.
//Parameters: None.
//Output. None.
void TsuPod::shuffle()
{
    //Seed random number.
    srand(time(NULL));
    for (int j = 0; j < numSongs; j++)
    {
        int index1 = rand() % numSongs;
        int index2 = rand() % numSongs;
        Song temp = songs[index1];
        songs[index1] = songs[index2];
        songs[index2] = temp;
    }

}

//Function: sortSongList. Sorts the list of songs
//by Artist, then Title, then Size.
//Parameters: None.
//Output: None
void TsuPod::sortSongList()
{
    for (int i = 0; i < numSongs - 1; i++)
    {
        for (int j = i+1; j < numSongs; j++)
        {
            if (songs[i].getArtist() == songs[j].getArtist())
            {
                if(songs[i].getSong() == songs[j].getSong())
                {
                    if (songs[i].getFSize() == songs[j].getFSize())
                    {
                    }
                    else
                    {
                        if(songs[i].getFSize() > songs[j].getFSize())
                        {
                            swap(songs[i], songs[j]);
                        }
                        if(songs[i].getFSize() < songs[j].getFSize())
                        {
                        }
                    }
                }
                else
                {
                    if (songs[i].getSong() > songs[j].getSong())
                    {
                        swap(songs[i], songs[j]);
                    }
                    if(songs[i].getSong() < songs[j].getSong())
                    {
                    }
                }
            }
            else
            {
                if (songs[i].getArtist() > songs[j].getArtist())
                {
                    swap(songs[i], songs[j]);
                }
                if (songs[i].getArtist() < songs[j].getArtist())
                {
                }
            }
            }
        }
}

//Function: getTotalMemory. Gets the total used amount of memory.
//Parameters: None.
//Output: memSize (int), the total in MB of all stored songs.
int TsuPod::getTotalMemory()
{
    memSize = 0;
    for (int k = 0; k < numSongs; k++)
    {
        if (songs[k].getFSize() > 0)
        {
            memSize = songs[k].getFSize() + memSize;
        }
    }

    return memSize;
}

//Function: getRemainingMemory. Returns the remaining memory in the tsuPod.
//Parameters: None.
//Output: MAX SIZE (const int) minus the memCounter (int) used.
int TsuPod::getRemainingMemory()
{
    memSize = 0;
    for (int i = 0; i < numSongs; i++)
    {
        if (songs[i].getFSize() > 0)
        {
            memSize = memSize + songs[i].getFSize();
        }
    }

    return MAX_SIZE - memSize;
}
