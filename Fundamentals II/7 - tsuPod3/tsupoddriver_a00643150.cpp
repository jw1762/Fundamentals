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
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "tsupod.h"

using namespace std;

int main(int argc, char *argv[])
{
    TsuPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    cout << "Testing Get functions for S1..." << endl;
    cout << s1.getArtist() << endl;
    cout << s1.getSong() << endl;
    cout << s1.getFSize() << endl;

    cout << "\nTesting Set functions for S1..." << endl;
    s1.setArtist("Beatles");
    cout << s1.getArtist() << endl;
    s1.setFSize(20);
    cout << s1.getFSize() << endl;
    s1.setSong("Hey Jude");
    cout << s1.getSong() << endl << endl;

    int result = 0;
    cout << "Testing addSong: " << endl;
    result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    cout << "Adding a few more songs..." << endl;

    Song s2("Beatles", "Ruby Tuesday", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    Song s3("AWOLNATION", "Sail", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    t.showSongList();

    cout << "Testing numSongs counter: " << t.numSongs() << endl;
    cout << "Adding some more songs... 2nd is too large..." << endl;

    Song s4("Eminem", "The Real Slim Shady", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Queen", "", 200);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Queen", "Want to Break Free", 2);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Queen", "Bohemian Rhapsody", 8);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("Queen", "Bohemian Rhapsody", 9);
    result = t.addSong(s8);
    cout << "Add result= " << result << endl;

    cout << "Testing numSongs counter again: " << t.numSongs() << endl;

    t.showSongList();

    cout << "Testing shuffle..." << endl;
    t.shuffle();
    t.showSongList();

    cout << "Testing shuffle again..." << endl;
    t.shuffle();

    t.showSongList();

    cout << "Testing sortSongList..." << endl;
    t.sortSongList();
    t.showSongList();

    cout << "Testing removeSong for 2 and 3." << endl;
    result = t.removeSong(s2);
    cout << "Removing S2. delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "Removing S3. delete result = " << result << endl;

    t.showSongList();

    cout << "Deleting some more..." << endl;

    result = t.removeSong(s1);
    cout << "Removing S1. delete result = " << result << endl;

    result = t.removeSong(s8);
    cout << "Removing S5. delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "Removing S4. delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s1);
    cout << "Adding S5. add result = " << result << endl;

    result = t.addSong(s2);
    cout << "Adding S5 again. add result = " << result << endl;

    t.showSongList();
    cout << "Sorting again..." << endl;
    t.sortSongList();
    t.showSongList();

    system("PAUSE");
    return 0;
}
