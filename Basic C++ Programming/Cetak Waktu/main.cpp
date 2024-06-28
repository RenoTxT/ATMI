// main.cpp
#include "tipeJam.h"


using namespace std;

int main() {
    CurrentTime currentTimeObject;

    // Get the current time
    currentTimeObject.getCurrentTime();

    // Write the current time to a file
    currentTimeObject.writeToFile("current_time.txt");
    
    return 0;
}
