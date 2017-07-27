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
#include "tsupod.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Default Constructor
TsuPod::TsuPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;
}

//Secondary Constructor
TsuPod::TsuPod(int _fileSize)
{
     if (_fileSize > MAX_MEMORY || _fileSize <= 0)
     {
         memSize = MAX_MEMORY;
     }
     else
     {
         memSize = memSize + _fileSize;
     }
}

//Destructor
TsuPod::~TsuPod()
{

}

//Function: AddSong. Adds a song into our array.
//Parameters: Takes in a single song, 's', of class Song.
//Output: -1 for NO_MEMORY. -2 for NOT FOUND artist/title. 0 for SUCCESS.
int TsuPod::addSong(Song const &s)
{
    //Checks for missing title, artist, or size too large.
    if (s.getArtist() == "" || s.getSong() == "")
        return NOT_FOUND;
    if (s.getFSize() > MAX_MEMORY || s.getFSize() > getTotalMemory() || s.getFSize() <= 0)
        return NO_MEMORY;

    if (getTotalMemory() >= s.getFSize())
    {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = NULL;

        if (songs == NULL)//If it's the first song...
        {
            songs = temp;
            //Negative value of getFSize to reduce current memSize (512 to start).
            getRemainingMemory(-(temp->s.getFSize()));
            numSongs();//Count new no. of songs.
            return SUCCESS;
        }
        else//If it's not the first song.
        {
            SongNode *target = songs;
            while(target->next != NULL)
                target = target->next;//Finding the end.
            target->next = temp;
            getRemainingMemory(-(temp->s.getFSize()));
            numSongs();//Count new no. of songs.
            return SUCCESS;
        }
    }
}

//Function: removeSong. Removes a song from our array of songs.
//Paramaters: A single song, 's', of class Song.
//Output: 0 for SUCCESS, -2 for NOT_FOUND.
int TsuPod::removeSong(Song const &s)
{
    SongNode *previous = songs;
    SongNode *current = songs->next;

    if(songs->s == s)
    {
        getRemainingMemory(songs->s.getFSize());
        songs = songs->next;
        delete previous;
        numSongs();
        return SUCCESS;
    }
    else
    {
        while (current != NULL)
        {
            if (current->s == s)
            {
                getRemainingMemory(current->s.getFSize());
                previous->next = current->next;
                delete current;
                numSongs();
                return SUCCESS;
            }
            else
            {
                previous = current;
                current = current -> next;
            }
        }
    }
    return NOT_FOUND;
}

//Function: showSongList. Shows the linked list of songs currently stored.
//Parameters: None.
//Output: None.
void TsuPod::showSongList()
{
    SongNode *target = songs;
    int i = 0;
    cout << "---Current Stored Songs---" << endl;

    while (target != NULL)
    {
        if (target->s.getFSize() > 0)
        {
            cout << i+1 << " - " << target->s.getArtist() << " - " << target->s.getSong()
            << " - " << target->s.getFSize() << "MB" << endl;
        }

    i++;
    target = target->next;
    }

    cout << "---End of Current Stored Songs---" << endl << endl;
}

//Function: Shuffle. Shuffles the linked list of songs into random order.
//Parameters: None.
//Output. None.
int TsuPod::shuffle()
{
    //Seed random number.
    srand(time(NULL));
    int rand1 = rand() % numSongs();

    SongNode *p1 = songs;
    SongNode *p2 = songs;

    srand(time(NULL));
    int rand2 = rand() % numSongs();

    for (int i = 0; i < rand1; i++)
    {
        p1 = p1->next;
    }

    for (int j = 0; j < rand2; j++)
    {
        p2 = p2->next;
    }

    Song temp = p1->s;
    p1->next = p2->next;
    p2->s = temp;
}

//Function: sortSongList. Sorts the list of songs
//by Artist, then Title, then Size.
//Parameters: None.
//Output: None
void TsuPod::sortSongList()
{
    for (SongNode *index = songs; index->next !=  NULL; index = index->next)
    {
        for (SongNode *target = index->next; target != NULL; target = target->next)
        {
            if(index->s > target->s)
            {
                swap(index->s, target->s);
            }
        }
    }
}

//Function: getRemainingMemory. Returns the remaining memory in the tsuPod.
//Parameters: None.
//Output: memSize (int) with the added (or subtracted) value (int).
void TsuPod::getRemainingMemory(int value)//Negative when adding a song.
{
    memSize += value;
}

//Function: numSongs. Returns the number of songs within the linked list.
//Parameters: None.
//Output: numSongs (int) of songs.
int TsuPod::numSongs()
{
    int numSongs = 0;
    SongNode *p = songs;
    while (p!=NULL)
    {
        numSongs++;
        p = p->next;
    }
    return numSongs;
}
