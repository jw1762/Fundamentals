/********************************
Jordan Williamson
CS 2308
2/18/2015

A program for storing, adding, shuffling, and deleting songs.
7 Functions are used to accomplish this.
*********************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "tsuPod.h"

const int NUM_SONGS = 8; //Maximum number of songs.
const int MEMORY_SIZE = 25;  //size in MB
const int SUCCESS = 0; //Constant for successful return.

int memoryCounter(); //Function for determining amount of memory used so far.

struct Song
    {
        string artist = "";
        string title = "";
        int fileSize = 0;
    };

Song songs[NUM_SONGS];

/* FUNCTION - void initTsuPod

 Initialize all the slots to blank and 0 size memory

 input parms - none

 output parms - none
*/
void initTsuPod()
{
    for (int i = 0; i < NUM_SONGS; i++)
    {
        songs[i].artist = "";
        songs[i].title = "";
        songs[i].fileSize = 0;
    }
}

/* FUNCTION - int addSong
 * attempts to add a new song to the tsuPod
          o returns a 0 if successful
          o returns -1 if not enough memory to add the song
          o returns -2 for any other error (such as a blank title or artist)

 input parms - Song consisting of a title (string), artist (string), and filesize (int)

 output parms - Will output a 0, or -1, or -2 (int).
*/
int addSong (string newTitle, string newArtist, int size)
{
    //Run memory check to see current total size of stored songs
    //before adding any more.
    memoryCounter();

    //Check if the song is too large, then if the sum of song
    //and current memory size size is over 25MB (also too large).
    if (size > MEMORY_SIZE || (size + memoryCounter()) > MEMORY_SIZE)
    {
        return -1;
    }

    if (newTitle == "" || newArtist == "")
    {
        return -2;
    }

    else
    {
        for (int k = 0; k < NUM_SONGS; k++)
        {
            if (songs[k].fileSize == 0)
            {
                songs[k].title = newTitle;
                songs[k].artist = newArtist;
                songs[k].fileSize = size;
                return SUCCESS;
            }
        }
    }

    //Update the memory count after adding a song.
    memoryCounter();
}

/* FUNCTION - int removeSong
    * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed


input parms - A song title (string).

output parms - Either a 0 (int) or 1 (int).
*/
int removeSong(string title)
{
    for (int j = 0; j < NUM_SONGS; j++)
    {
        if (title == songs[j].title)
        {
            songs[j].title = "";
            songs[j].artist = "";
            songs[j].fileSize = 0;
            return SUCCESS;
        }
    }

    for (int k = 0; k < NUM_SONGS; k++)
    {
        if (title != songs[k].title)
        {
            return -1;
        }
    }
}

/* FUNCTION - void clearMemory
* clears all the songs from memory

input parms - none.

output parms - none.
*/
void clearMemory()
{
    for (int i = 0; i < NUM_SONGS; i++)
    {
        songs[i].artist = "";
        songs[i].title = "";
        songs[i].fileSize = 0;
    }
}

/* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - slot #, Title, Artist, size in MB (one song per line)
    * print "Empty" for any slots that do not contain a song

input parms - none.

output parms - The slot position (int), title (string)
               and size (int) of the songs currently stored.
               Otherwise, slot position (int) and 'Empty.'.
*/
void showSongList()
{
    for (int i = 0; i < NUM_SONGS; i++)
    {
        if (songs[i].artist == "" || songs[i].title == "" || songs[i].fileSize == 0)
            cout << "Slot " << i+1 <<" - Empty." << endl;
        else
            cout << "Slot "<< i+1 << " - " << songs[i].title << " - " << songs[i].artist << " - " << songs[i].fileSize << "MB" << endl;
    }
}

/* FUNCTION - void shuffle
    *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

input parms - none.

output parms - none.
*/
void shuffle()
{
    //Seed random number.
    srand(time(NULL));

    for (int j = 0; j < NUM_SONGS; j++)
    {
    int index1 = rand() % NUM_SONGS;
    int index2 = rand() % NUM_SONGS;
    Song temp = songs[index1];
    songs[index1] = songs[index2];
    songs[index2] = temp;
    }
}

/* FUNCTION - int memoryCounter
    * Calculates current memory used.

input parms - none.

output parms. - Returns the current accumulated
                size (int) of all songs.
*/
int memoryCounter()
{
    int sizeCounter = 0;

    for (int k = 0; k < NUM_SONGS; k++)
    {
        if (songs[k].fileSize > 0)
        {
            sizeCounter = songs[k].fileSize + sizeCounter;
        }
    }
    return sizeCounter;
}
