#define _CRT_SECURE_NO_WARNINGS
// CurrentTime.cpp
#include "tipeJam.h"
#include <iostream>

using namespace std;

void CurrentTime::getCurrentTime() {
    // Get the current time
    currentTime = chrono::system_clock::now();

    // Convert the current time to a readable format
    currentTimeInTimeT = chrono::system_clock::to_time_t(currentTime);
    currentTimeInfo = localtime(&currentTimeInTimeT);
}

void CurrentTime::writeToFile(const string& fileName) const {
    // Open the file for writing
    ofstream outputFile(fileName);

    if (outputFile.is_open()) {

        outputFile << "Current Time: " << asctime(currentTimeInfo);
        // Write the current time to the file
        cout << "Current Time is: " << asctime(currentTimeInfo) << endl;
        cin.ignore(); //press to continue
        cout << "Exported to " << fileName << endl;
        outputFile.close();
        
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

