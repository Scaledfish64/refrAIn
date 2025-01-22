#include <iostream>
#include <string>
#include "midifile/include/MidiFile.h"

using namespace std;
using namespace smf;

int main() {
    MidiFile midiFile;

    string midifilePath;
    bool goodFile = false;
    string currentInput;

    while (!goodFile) {
        cout << "Enter midi file path: ";
        cin >> midifilePath;

        if (!midiFile.read(midifilePath)) {
            cerr << "Error reading MIDI file! Check Path" << endl;
            continue;
        }


        cout << "The selected midi file is " << midiFile.getFilename() << endl << "Proceed? (y/else) :";
        cin >> currentInput;
        if (currentInput == "y") {
            goodFile = true;
        } 

    }

    int trackCount = midiFile.getTrackCount();

    for (int track = 0; track < trackCount; ++track) {
        int eventCount = midiFile.getEventCount(track);
        cout << "Track " << track << " has " << eventCount << " events:" << endl;
    }

    return 0;
}
