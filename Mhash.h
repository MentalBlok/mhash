/*************************************************/
/* mental.blok.2020@gmail.com                    */
/*************************************************/

#ifndef Chem_H_
#define Chem_H_

using namespace std;

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

#endif /*Chem_H_*/
