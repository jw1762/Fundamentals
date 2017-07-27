#include <iostream>
#include <iomanip>

#include "tsuPod.h"

using namespace std;

int main()
{

    initTsuPod();
    cout << "tsuPod initilized. " << endl;

    showSongList();
    cout << endl;

    //Read-in some songs.
    cout << "Now adding 8 songs. 3 will fail to be added." << endl;

    int retCode = addSong("Sail", "AWOLNATION", 5);
    cout << "Successful add. Return code: " << retCode << endl;

    retCode = addSong("Paint It, Black", "The Rolling Stones", 3);
    cout << "Successful add. Return code: " << retCode << endl;

    retCode = addSong("When You Were Young", "The Killers", 7);
    cout << "Successful add. Return code: " << retCode << endl;

    retCode = addSong("Missing Artist", "", 5);
    cout << "Missing artist. Failed add. Return code: " << retCode << endl;

    retCode = addSong("", "Missing Title", 5);
    cout << "Missing title. Failed add. Return code: " << retCode << endl;

    retCode = addSong("Oversized", "Memory", 30);
    cout << "File size too large. Failed add. Return code: " << retCode << endl;

    retCode = addSong("Where is My Mind?", "The Pixies", 2);
    cout << "Successful add. Return code: " << retCode << endl;

    retCode = addSong("Last Nite", "The Strokes", 2);
    cout << "Successful add. Return code: " << retCode << endl << endl;

    showSongList();
    cout << endl;

    //Song Removal Test.
    retCode = removeSong("Last Nite");
    cout << "Removing 'Last Nite'. Return code for removeSong: " << retCode << endl;

    retCode = removeSong("No song is here.");
    cout << "Attempted removal of song that is not there. Return code: " << retCode << endl << endl;

    showSongList();
    cout << endl;

    cout << "Shuffling songs." << endl;
    shuffle();
    cout << endl;

    showSongList();
    cout << endl;

    //Addding more songs. Half will be added and half will be denied.
    retCode = addSong("Pumped Up Kicks", "Foster the People", 5);
    cout << "Adding song. Return code: " << retCode << endl;

    retCode = addSong("Like a Boss", "The Lonely Island", 2);
    cout << "Adding song. Return code: " << retCode << endl;

    retCode = addSong("Holiday", "Green Day", 1);
    cout << "Adding song. Storage now at 25MB. Return code: " << retCode << endl;

    retCode = addSong("The Real Slim Shady", "Eminem", 4);
    cout << "Failed to add song. File will cause storage to exceed 25MB. Return code: " << retCode << endl << endl;

    showSongList();
    cout << endl;

    cout << "Shuffling songs again..." << endl;
    shuffle();
    cout << endl;

    showSongList();
    cout << endl;

    clearMemory();
    cout << "Deleting all songs. clearMemory." << endl;
    showSongList();

    cin.get();
    return 0;
}
