/*************************************************/
/* mental.blok.2020@gmail.com                    */
/*************************************************/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

int pop[57];

class Mhash {
  static const char syms[];
  static const int sz18_7 = 262144;
  static const int sz16_7 = 65536;
  static uint8_t bc18[sz18_7];
  static uint8_t bc16[sz16_7];
  static uint32_t ind18_7[sz18_7];

  static uint32_t ind18_7_1[sz18_7];
  static uint32_t ind18_7_2[sz18_7];
  static uint32_t ind18_7_3[sz18_7];
  static uint32_t ind18_7_4[sz18_7];
  static uint32_t ind18_7_5[sz18_7];
  static uint32_t ind18_7_6[sz18_7];
  static uint32_t ind18_7_7[sz18_7];

  static uint32_t ind16_7_1[sz18_7];
  static uint32_t ind16_7_2[sz18_7];
  static uint32_t ind16_7_3[sz18_7];
  static uint32_t ind16_7_4[sz18_7];
  static uint32_t ind16_7_5[sz18_7];
  static uint32_t ind16_7_6[sz18_7];
  static uint32_t ind16_7_7[sz18_7];
  int cnts16[8];
  int cnts18[8];
public:
  Mhash();
  void testHash();
  void timeHash(int nIter);
  void generate();
  void pN(uint64_t b, int n);
  void mentalHash(const uint64_t & b7, int & rHash);
  static const int NDECK = 52;
  static const int KSZ = 133784560;
  static const uint64_t ONE = 1ULL;
};

// int Mhash::cnts16[] = { 1, 16, 120, 560, 1820, 4368, 8008, 11440 }:
// int Mhash::cnts18[] = { 1, 18, 153, 816, 3060, 8568, 18564, 31824 }:

const char Mhash::syms[] = "23456789TJQKAtjqka";
uint8_t Mhash::bc18[sz18_7];
uint8_t Mhash::bc16[sz16_7];
uint32_t Mhash::ind18_7[sz18_7];

uint32_t Mhash::ind18_7_1[sz18_7];
uint32_t Mhash::ind18_7_2[sz18_7];
uint32_t Mhash::ind18_7_3[sz18_7];
uint32_t Mhash::ind18_7_4[sz18_7];
uint32_t Mhash::ind18_7_5[sz18_7];
uint32_t Mhash::ind18_7_6[sz18_7];
uint32_t Mhash::ind18_7_7[sz18_7];

uint32_t Mhash::ind16_7_1[sz18_7];
uint32_t Mhash::ind16_7_2[sz18_7];
uint32_t Mhash::ind16_7_3[sz18_7];
uint32_t Mhash::ind16_7_4[sz18_7];
uint32_t Mhash::ind16_7_5[sz18_7];
uint32_t Mhash::ind16_7_6[sz18_7];
uint32_t Mhash::ind16_7_7[sz18_7];

/* Explanation of the Switch Statement created by the Mhash::generate() method

The output of generate is saved to the switch.cpp file. Then, this file
 is included in this class to do the actual hashing.

The switch statement in switch.cpp is used to calculate a unique hash
 value (rHash) for a 7-card hand based on the pattern of bits set in
 the 64-bit integer b7. Here's a detailed breakdown:

Switch on kind

The variable kind is determined by the number of bits set in different
 parts of b7. It effectively categorizes the bit patterns into cases.

Case Structure

Each case represents a unique combination of bits set in three slices
 of b7 (lower 18 bits, middle 18 bits, and upper bits). For example,
 case 0 represents a pattern where the upper bits have 7 bits set,
 and both the middle and lower bits have none.


Bit Projection and Index Calculation

For each case, the bits are projected out of b7 and assigned to variables
 p0, p1, and p2 using bitwise operations. These projections isolate
 specific slices of bits.

The corresponding indices (ind18_7, ind16_7_x) are then used to calculate
 the final hash value rHash. These indices map the bit patterns to
 unique values.

Total Count and Offset

The totCnt (total count) for each case is calculated based on the number
 of combinations possible for the given bit pattern. This ensures that
 each hash value is unique.

An offset is added to rHash to account for the cumulative count of
 previous cases, ensuring uniqueness across all cases.

Return and Default

After calculating rHash, the function returns. If kind does not match
 any case, the default case prints an error message and exits the program.

This switch statement is a critical part of the hashing function, ensuring
 that each unique 7-card hand is hashed to a unique value efficiently.

A number of diagnostic statements are turned off by testing for zero. These were
used to debug the program by printing auxiliary information about the cases.
*/

void Mhash::generate()
{
  int cumCnt = 0;
  cout << "  switch(kind) { // based on how many bits in each bite" << endl;
  for (int i = 0; i < 512; i++) {
    int totCnt = 1;
    int a = i / 64;
    int b = (i / 8) % 8;
    int c = i % 8;
    if (a + b + c != 7) continue;
    int caseNum = (a * 8) + b;
    if (a) {
      totCnt *= cnts18[a];
    }
    if (b) {
      totCnt *= cnts18[b];
    }
    if (c) {
      totCnt *= cnts16[c];
    }
    cout << "  case " << caseNum << ": // " << setw(3) << a
      << setw(2) << b << setw(2) << c;
    cout << "   (" << (a ? cnts18[a] : 1)
      << " * " << (b ? cnts18[b] : 1) << " * " << (c ? cnts16[c] : 1)
      << ")  totCnt = " << totCnt << endl;
    if (a) {
      cout << "    p0 = b7     & m0; // ";
      pN(0x3800fULL, 52);
      cout << endl;
    }
    if (b) {
      cout << "    p1 = b7>>18 & m0; // ";
      pN(0x3800fULL<<18, 52);
      cout << endl;
    }
    if (c) {
      cout << "    p2 = b7>>36;      // ";
      pN(0x0e00fULL<<36, 52);
      cout << endl;
    }

    if (a && !b && !c) cout << "    rHash = ind18_7[p0] + " << cumCnt << ";"
        << endl;

    if (!a && b && !c) cout << "    rHash = ind18_7[p1] + " << cumCnt << ";"
        << endl;

    if (!a && !b && c) cout << "    rHash = ind18_7[p2] + " << cumCnt << ";"
        << endl;

    if (0 && !a && b && c) cout << "    // rHash = ind18_7[p2] + (ind18_7[p1] * "
      << cnts16[c] << ") + " << cumCnt << ";" << endl;


    if (!a && b && c) cout << "    rHash = ind18_7[p2] + ind16_7_" << c
      << "[p1] + " << cumCnt << ";" << endl;
    if (0) cout << "    if (0&& rHash != fHash) cout << setw(10) << "
      << "fHash << setw(10)\n" << "      << rHash << setw(3) << kind << \""
      << setw(3) << a << setw(3) << b << setw(3) << c << "\" << endl;" << endl;


    if (0 && a && !b && c) cout << "    // rHash = ind18_7[p2] + (ind18_7[p0] * "
      << cnts16[c] << ") + " << cumCnt << ";" << endl;

    if (a && !b && c) cout << "    rHash = ind18_7[p2] + ind16_7_" << c
      << "[p0] + " << cumCnt << ";" << endl;
    if (0) cout << "    if (0&& rHash != fHash) cout << setw(10) << "
      << "fHash << setw(10)\n" << "      << rHash << setw(3) << kind << \""
      << setw(3) << a << setw(3) << b << setw(3) << c << "\" << endl;" << endl;


    if (0 && a && b && !c) cout << "    // rHash = ind18_7[p1] + (ind18_7[p0] * "
      << cnts18[b] << ") + " << cumCnt << ";" << endl;

    if (a && b && !c) cout << "    rHash = ind18_7[p1] + ind18_7_" << b
      << "[p0] + " << cumCnt << ";" << endl;
    if (0) cout << "    if (0&& rHash != fHash) cout << setw(10) << "
      << "fHash << setw(10)\n" << "      << rHash << setw(3) << kind << \""
      << setw(3) << a << setw(3) << b << setw(3) << c << "\" << endl;" << endl;


    if (0 && a && b && c) cout << "    // rHash = ind18_7[p2] + (ind18_7[p1] * "
      << cnts16[c] << ") + (ind18_7[p0] * " << (cnts18[b] * cnts16[c])
      << ") + " << cumCnt << ";" << endl;

    if (a && b && c) cout << "    rHash = ind18_7[p2] + ind16_7_" << c
      << "[p1] + (ind18_7[p0] * " << (cnts18[b] * cnts16[c])
      << ") + " << cumCnt << ";" << endl;
    if (0) cout << "    if (0 && rHash != fHash) cout << setw(10) << "
      << "fHash << setw(10)\n" << "      << rHash << setw(3) << kind << \""
      << setw(3) << a << setw(3) << b << setw(3) << c << "\" << endl;" << endl;


    cumCnt += totCnt;
    cout << "    return;\n" << endl;
  }
  cout << "  default:\n    cout << \"Bad case label in switch!\" << endl;\n"
    << "    exit(0);\n  }" << "    // cumCnt = " << cumCnt << endl;
}

void Mhash::pN(uint64_t b, int n)
{
  for (int i = 0; i < n; i++) {
    int c = (b&1);
    cout << (c?syms[i%13]:'.');
    b >>= 1;
  }
}

unsigned char hashCnt[Mhash::KSZ];

void Mhash::timeHash(int nIter)
{
  cout << "Mhash::timeHash(" << nIter << ")" << endl;
  for (int i = 0; i < KSZ; i++) {
    hashCnt[i] = 0;
  }
  int h7 = 0;
  for (int i = 0; i < nIter; i++) {
    uint64_t b0 = 0;
    int i0, i1, i2, i3, i4, i5, i6;
    for (i0 =    0; i0 < NDECK-6; i0++) {
      uint64_t b1 = b0 | (ONE<<i0);
      for (i1 = i0+1; i1 < NDECK-5; i1++) {
        uint64_t b2 = b1 | (ONE<<i1);
        for (i2 = i1+1; i2 < NDECK-4; i2++) {
          uint64_t b3 = b2 | (ONE<<i2);
          for (i3 = i2+1; i3 < NDECK-3; i3++) {
            uint64_t b4 = b3 | (ONE<<i3);
            for (i4 = i3+1; i4 < NDECK-2; i4++) {
              uint64_t b5 = b4 | (ONE<<i4);
              for (i5 = i4+1; i5 < NDECK-1; i5++) {
                uint64_t b6 = b5 | (ONE<<i5);
                for (i6 = i5+1; i6 < NDECK-0; i6++) {
                  uint64_t b7 = b6 | (ONE<<i6);
                  mentalHash(b7, h7);
                  hashCnt[h7]++;
                }
              }
            }
          }
        }
      }
    }
  }
  
  /* The number of instances of each hash value should be exactly equal to the number of
  times we iterate through the the timing loop. Flag any instances where this does not hold true.
  */
  int errCnt = 0;
  cout << "Sanity test:" << endl;
  for (int i = 0; i < KSZ; i++) {
    if (hashCnt[i] != nIter) {
      if (errCnt < 10) {
        pN(i, 18);
        cout << "  Hash: " << setw(10) << i << " count: " << setw(4) << endl;
      }
      errCnt++;
    }
  }
  if (errCnt) cout << "errCnt: " << errCnt << endl;
}

void Mhash::testHash()
{
  for (int i = 0; i < KSZ; i++) {
    hashCnt[i] = 0;
  }
  uint64_t b0 = 0;
  int i0, i1, i2, i3, i4, i5, i6;
  int h7 = 0;
  for (i0 =    0; i0 < NDECK-6; i0++) {
    uint64_t b1 = b0 | (ONE<<i0);
    for (i1 = i0+1; i1 < NDECK-5; i1++) {
      uint64_t b2 = b1 | (ONE<<i1);
      for (i2 = i1+1; i2 < NDECK-4; i2++) {
        uint64_t b3 = b2 | (ONE<<i2);
        for (i3 = i2+1; i3 < NDECK-3; i3++) {
          uint64_t b4 = b3 | (ONE<<i3);
          for (i4 = i3+1; i4 < NDECK-2; i4++) {
            uint64_t b5 = b4 | (ONE<<i4);
            for (i5 = i4+1; i5 < NDECK-1; i5++) {
              uint64_t b6 = b5 | (ONE<<i5);
              for (i6 = i5+1; i6 < NDECK-0; i6++) {
                uint64_t b7 = b6 | (ONE<<i6);
                mentalHash(b7, h7);
                hashCnt[h7]++;
              }
            }
          }
        }
      }
    }
  }
#if 1
  int errCnt = -1, prevCnt = -1;
  cout << "Sanity test:" << endl;
  for (int i = 0; i < KSZ; i++) {
    if (hashCnt[i] != prevCnt) {
      if (errCnt < 10) {
        pN(i, 18);
        if (i) cout << "  Hash: " << setw(10) << i << " count: " << setw(4)
          << int(hashCnt[i]) << " vs " << setw(4) << prevCnt << endl;
      }
      errCnt++;
      prevCnt = hashCnt[i];
    }
  }
  if (errCnt) cout << "errCnt: " << errCnt << endl;
  if (0) for (uint32_t b = 0; b < sz18_7; b++) {
    if (bc18[b] == 7) {
      pN(b, 18);
      cout << setw(8) << b << setw(8) << ind18_7[b] << endl;
    }
  }
#endif
#if 0
  for (int i = 0; i < 57; i++) {
    if (pop[i]) cout << setw(2) << i << setw(10) << pop[i] << endl;
  }
#endif
}

Mhash::Mhash()
{
  for (int i = 0; i < 57; i++) {
    pop[i] = 0;
  }
  for (int i = 0; i < 8; i++) {
    cnts16[i] = cnts18[i] = 0;
  }
  for (uint32_t b = 0; b < sz16_7; b++) {
    int sCnt = 0;
    for (int s = 0; s < 16; s++) {
      if (b&(ONE<<s)) sCnt++;
    }
    if (sCnt > 7) continue;
    if (sCnt == 8) {
      pN(b, 16); cout << setw(6) << cnts16[sCnt] << endl;
    }
    bc16[b] = sCnt;
    cnts16[sCnt]++;
  }
#if 0
  for (int i = 0; i < 8; i++) {
    cout << cnts16[i] << ", ";
  }
  cout << endl;
#endif
  for (uint32_t b = 0; b < sz18_7; b++) {
    int sCnt = 0;
    for (int s = 0; s < 18; s++) {
      if (b&(ONE<<s)) sCnt++;
    }
    if (sCnt > 7) continue;
    bc18[b] = sCnt;
    ind18_7[b] = cnts18[sCnt];
    cnts18[sCnt]++;
  }
#if 0
  for (int i = 0; i < 8; i++) {
    if (0) cout << cnts18[i] << ", ";
  }
  if (0) cout << endl;
#endif
  for (int i = 0; i < sz18_7; i++) {
    ind18_7_1[i] = ind18_7[i] * cnts18[1];
    ind18_7_2[i] = ind18_7[i] * cnts18[2];
    ind18_7_3[i] = ind18_7[i] * cnts18[3];
    ind18_7_4[i] = ind18_7[i] * cnts18[4];
    ind18_7_5[i] = ind18_7[i] * cnts18[5];
    ind18_7_6[i] = ind18_7[i] * cnts18[6];
    ind18_7_7[i] = ind18_7[i] * cnts18[7];
  }
  for (int i = 0; i < sz18_7; i++) {
    ind16_7_1[i] = ind18_7[i] * cnts16[1];
    ind16_7_2[i] = ind18_7[i] * cnts16[2];
    ind16_7_3[i] = ind18_7[i] * cnts16[3];
    ind16_7_4[i] = ind18_7[i] * cnts16[4];
    ind16_7_5[i] = ind18_7[i] * cnts16[5];
    ind16_7_6[i] = ind18_7[i] * cnts16[6];
    ind16_7_7[i] = ind18_7[i] * cnts16[7];
  }
}

void Mhash::mentalHash(const uint64_t & b7, int & rHash)
{
  const uint64_t m0 = 0x3ffffULL; // mask for projecting out 18 bits
  uint64_t p0, p1, p2;
  uint8_t nb0 = bc18[b7     & 0x3ffffULL];
  uint8_t nb1 = bc18[b7>>18 & 0x3ffffULL];
  uint8_t nb2 = bc18[b7>>36];
  int kind = nb1 | (nb0 << 3);
#if 0
  int fHash;
  if (nb0 > 7 || kind > 56) {
    cout << setw(2) << kind << " ";
    pN(b7, 52);
    cout << setw(2)<< nb0 << nb1 << nb2 << endl;
    exit(0);
  }
  pop[kind]++;
#endif
#include "switch.cpp"
}

/* Testing information. The frequency of reaching each case in the hash switch
 1    144144
 2    668304
 3   1485120
 4   1713600
 5   1028160
 6    297024
 7     31824
 8    144144
 9   1415232
10   5012280
11   8225280
12   6609600
13   2467584
14    334152
16    668304
17   5012280
18  13109040
19  14981760
20   7490880
21   1310904
24   1485120
25   8225280
26  14981760
27  10653696
28   2496960
32   1713600
33   6609600
34   7490880
35   2496960
40   1028160
41   2467584
42   1310904
48    297024
49    334152
56     31824
*/
