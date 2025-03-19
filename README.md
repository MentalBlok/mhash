# mhash
Fast perfect seven card hash function

This program implements a perfect hash function for 64-bit integers where exactly seven of the
lower-order 52 bits are set to 1. These bits might represent the 52-cards in a standard deck.
Therefore, the function can hash each unique 7-card hand to a unique index. This fast hash is
very useful for fast analysis of 7-card poker games like Ultimate Texas Holdem or Casino Holdem.

The hash function is implemented in a switch statement. The program has a method to generate 
this switch statement. This is included to show how the program can be modified to adapt it
to different requirements. I have created a version which is potentially faster, but uses much
more memory. This program slices the 52-bit integer into three slices. The faster algorithm uses
two 26-bit slices.

Mhash::testHash() creates every unique representation of a 52-card hand and hashes the hand.
There are sanity tests included to verify that every hash value is unique.

This is an original algorithm, but it is based on ideas from Paul D. Senzee's Optimized Hand Evaluator
https://github.com/christophschmalhofer/poker/blob/master/XPokerEval/XPokerEval.CactusKev.PerfectHash/fast_eval.cpp
