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
#ifndef TSUPOD_H
#define TSUPOD_H
#include "song.h"

//TsuPod class declaration
class TsuPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;

      struct SongNode
      {
         Song s;
         SongNode *next;
      };

      SongNode *songs;  //the head pointer

      int memSize;

   public:
      TsuPod();
      TsuPod(int size);
      ~TsuPod();

      int addSong(Song const &s);
      int removeSong(Song const &s);
      int shuffle();
      void showSongList();
      void sortSongList();

      int getTotalMemory() {
         return memSize;
      }
      void getRemainingMemory(int value);
      int numSongs();
};

#endif
