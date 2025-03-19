/*************************************************/
/* mental.blok.2020@gmail.com                    */
/*************************************************/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include "Mhash.h"

using namespace std;

int main(int argc, char **argv)
{
  int gen = 0;
  int nIter = 0;
  char ch = 0;
  while ((ch = getopt(argc, argv, "g t: ? ")) != EOF) {
    switch (ch) {
    case '?':
      printf("-g  Generate the switch statement that does the hash\n");
      printf("-t: Test the hash function in a tight loop N times.\n");
      exit(0);
    case 'g':
      gen++;
      break;
    case 't':
      sscanf(optarg, "%d", &nIter);
      break;
    default:
      break;
    }
  }
  Mhash mhash;
  if (gen) {
    mhash.generate();
    exit(0);
  }
  if (nIter) {
    mhash.timeHash(nIter);
    exit(0);
  }
  mhash.testHash();
  return 0;
}
