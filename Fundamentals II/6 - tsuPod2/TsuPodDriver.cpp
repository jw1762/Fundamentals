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
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "TsuPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    TsuPod t;
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    Song s1("Beatles", "Hey Jude1", 4);
    cout << "Testing Get functions..." << endl;
    cout << s1.getArtist() << endl;
    cout << s1.getSong() << endl;
    cout << s1.getFSize() << endl;

    cout << "\nTesting Set functions..." << endl;
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
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    Song s2("Beatles", "Ruby Tuesday", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    Song s3("AWOLNATION", "Sail", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("AWOLNATION", "Not Your Fault", 7);
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

    t.showSongList();
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    cout << "Testing shuffle..." << endl;
    t.shuffle();
    t.showSongList();
    cout << "Testing shuffle again..." << endl;
    t.shuffle();

    t.showSongList();
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    cout << "Testing sortSongList..." << endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "Removing S2. delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "Removing S3. delete result = " << result << endl;

    t.showSongList();
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    result = t.removeSong(s1);
    cout << "Removing S1. delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "Removing S5. delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "Removing S4. delete result = " << result << endl;

    t.showSongList();
    cout << t.getTotalMemory() << "MB used." << endl;
    cout << t.getRemainingMemory() << "MB remaining." << endl << endl;

    result = t.addSong(s5);
    cout << "Adding S5. add result = " << result << endl;

    result = t.addSong(s5);
    cout << "Adding S5 again. add result = " << result << endl;

    t.showSongList();
    cout << "Remaining Memory = " << t.getRemainingMemory() << "MB" << endl;
    cout << "Total Used Memory = " << t.getTotalMemory() << "MB" << endl;

    system("PAUSE");
    return 0;
}
