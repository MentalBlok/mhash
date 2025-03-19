/*************************************************/
/* mental.blok.2020@gmail.com                    */
/*************************************************/

#include <iomanip>
#include <iostream>
#include <getopt.h>
#include "Mhash.h"

using namespace std;

void printUsage() {
    cout << "-g  Generate the switch statement that does the hash" << endl;
    cout << "-t  Test the hash function in a tight loop N times." << endl;
}

int main(int argc, char **argv) {
    bool generateSwitchStatement = false;
    int numIterations = 0;
    int option = 0;

    while ((option = getopt(argc, argv, "gt:")) != -1) {
        switch (option) {
            case 'g':
                generateSwitchStatement = true;
                break;
            case 't':
                try {
                    numIterations = stoi(optarg);
                } catch (const invalid_argument& e) {
                    cerr << "Invalid number of iterations: " << optarg << endl;
                    return 1;
                }
                break;
            case '?':
            default:
                printUsage();
                return 1;
        }
    }

    Mhash mhash;
    if (generateSwitchStatement) {
        mhash.generate();
        return 0;
    }
    if (numIterations > 0) {
        mhash.timeHash(numIterations);
        return 0;
    }
    mhash.testHash();
    return 0;
}
