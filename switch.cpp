  switch(kind) { // based on how many bits in each bite
  case 0: //   0 0 7   (1 * 1 * 11440)  totCnt = 11440
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + 0;
    return;

  case 1: //   0 1 6   (1 * 18 * 8008)  totCnt = 144144
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_6[p1] + 11440;
    return;

  case 2: //   0 2 5   (1 * 153 * 4368)  totCnt = 668304
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_5[p1] + 155584;
    return;

  case 3: //   0 3 4   (1 * 816 * 1820)  totCnt = 1485120
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_4[p1] + 823888;
    return;

  case 4: //   0 4 3   (1 * 3060 * 560)  totCnt = 1713600
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_3[p1] + 2309008;
    return;

  case 5: //   0 5 2   (1 * 8568 * 120)  totCnt = 1028160
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p1] + 4022608;
    return;

  case 6: //   0 6 1   (1 * 18564 * 16)  totCnt = 297024
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + 5050768;
    return;

  case 7: //   0 7 0   (1 * 31824 * 1)  totCnt = 31824
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + 5347792;
    return;

  case 8: //   1 0 6   (18 * 1 * 8008)  totCnt = 144144
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_6[p0] + 5379616;
    return;

  case 9: //   1 1 5   (18 * 18 * 4368)  totCnt = 1415232
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_5[p1] + (ind18_7[p0] * 78624) + 5523760;
    return;

  case 10: //   1 2 4   (18 * 153 * 1820)  totCnt = 5012280
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_4[p1] + (ind18_7[p0] * 278460) + 6938992;
    return;

  case 11: //   1 3 3   (18 * 816 * 560)  totCnt = 8225280
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_3[p1] + (ind18_7[p0] * 456960) + 11951272;
    return;

  case 12: //   1 4 2   (18 * 3060 * 120)  totCnt = 6609600
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p1] + (ind18_7[p0] * 367200) + 20176552;
    return;

  case 13: //   1 5 1   (18 * 8568 * 16)  totCnt = 2467584
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + (ind18_7[p0] * 137088) + 26786152;
    return;

  case 14: //   1 6 0   (18 * 18564 * 1)  totCnt = 334152
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_6[p0] + 29253736;
    return;

  case 16: //   2 0 5   (153 * 1 * 4368)  totCnt = 668304
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_5[p0] + 29587888;
    return;

  case 17: //   2 1 4   (153 * 18 * 1820)  totCnt = 5012280
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_4[p1] + (ind18_7[p0] * 32760) + 30256192;
    return;

  case 18: //   2 2 3   (153 * 153 * 560)  totCnt = 13109040
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_3[p1] + (ind18_7[p0] * 85680) + 35268472;
    return;

  case 19: //   2 3 2   (153 * 816 * 120)  totCnt = 14981760
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p1] + (ind18_7[p0] * 97920) + 48377512;
    return;

  case 20: //   2 4 1   (153 * 3060 * 16)  totCnt = 7490880
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + (ind18_7[p0] * 48960) + 63359272;
    return;

  case 21: //   2 5 0   (153 * 8568 * 1)  totCnt = 1310904
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_5[p0] + 70850152;
    return;

  case 24: //   3 0 4   (816 * 1 * 1820)  totCnt = 1485120
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_4[p0] + 72161056;
    return;

  case 25: //   3 1 3   (816 * 18 * 560)  totCnt = 8225280
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_3[p1] + (ind18_7[p0] * 10080) + 73646176;
    return;

  case 26: //   3 2 2   (816 * 153 * 120)  totCnt = 14981760
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p1] + (ind18_7[p0] * 18360) + 81871456;
    return;

  case 27: //   3 3 1   (816 * 816 * 16)  totCnt = 10653696
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + (ind18_7[p0] * 13056) + 96853216;
    return;

  case 28: //   3 4 0   (816 * 3060 * 1)  totCnt = 2496960
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_4[p0] + 107506912;
    return;

  case 32: //   4 0 3   (3060 * 1 * 560)  totCnt = 1713600
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_3[p0] + 110003872;
    return;

  case 33: //   4 1 2   (3060 * 18 * 120)  totCnt = 6609600
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p1] + (ind18_7[p0] * 2160) + 111717472;
    return;

  case 34: //   4 2 1   (3060 * 153 * 16)  totCnt = 7490880
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + (ind18_7[p0] * 2448) + 118327072;
    return;

  case 35: //   4 3 0   (3060 * 816 * 1)  totCnt = 2496960
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_3[p0] + 125817952;
    return;

  case 40: //   5 0 2   (8568 * 1 * 120)  totCnt = 1028160
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_2[p0] + 128314912;
    return;

  case 41: //   5 1 1   (8568 * 18 * 16)  totCnt = 2467584
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p1] + (ind18_7[p0] * 288) + 129343072;
    return;

  case 42: //   5 2 0   (8568 * 153 * 1)  totCnt = 1310904
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_2[p0] + 131810656;
    return;

  case 48: //   6 0 1   (18564 * 1 * 16)  totCnt = 297024
    p0 = b7     & m0; // 2345...........456..................................
    p2 = b7>>36;      // ....................................QKA2.........QKA
    rHash = ind18_7[p2] + ind16_7_1[p0] + 133121560;
    return;

  case 49: //   6 1 0   (18564 * 18 * 1)  totCnt = 334152
    p0 = b7     & m0; // 2345...........456..................................
    p1 = b7>>18 & m0; // ..................789T...........9TJ................
    rHash = ind18_7[p1] + ind18_7_1[p0] + 133418584;
    return;

  case 56: //   7 0 0   (31824 * 1 * 1)  totCnt = 31824
    p0 = b7     & m0; // 2345...........456..................................
    rHash = ind18_7[p0] + 133752736;
    return;

  default:
    cout << "Bad case label in switch!" << endl;
    exit(0);
  }    // cumCnt = 133784560
