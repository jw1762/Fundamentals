/********************************
Roger Priebe and Jordan Williamson
CS 2308
2/16/2015

These are the function definitions, and constants that will be used
for the tsuPod project. This file will be included in the driver test program and
the tsuPod.cpp file.

You will write the tsuPod.cpp function implementations and complete the documentation
for the header file.

*********************************/
#ifndef tsuPod_h
#define tsuPod_h

#include <string>

using namespace std;


/* FUNCTION - void initTsuPod

 Initialize all the slots to blank and 0 size memory

 input parms - none

 output parms - none
*/

void initTsuPod ();


/* FUNCTION - int addSong
 * attempts to add a new song to the tsuPod
          o returns a 0 if successful
          o returns -1 if not enough memory to add the song
          o returns -2 for any other error (such as a blank title or artist)

 input parms -

 output parms -
*/

int addSong (string newTitle, string newArtist, int size);



/* FUNCTION - int removeSong
    * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed


input parms -

output parms -
*/

int removeSong (string title);



/* FUNCTION - void clearMemory
* clears all the songs from memory

input parms -

output parms -
*/
void clearMemory();



/* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - slot #, Title, Artist, size in MB (one song per line)
    * print "Empty" for any slots that do not contain a song

input parms -

output parms -
*/

void showSongList ();



/* FUNCTION - void shuffle
    *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

input parms -

output parms -
*/

void shuffle ();

#endif
