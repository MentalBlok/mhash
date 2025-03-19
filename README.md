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

Summary provided by Copilot:

Understanding the Code

The Mhash.cpp file implements a perfect seven-card hash function. Here's a breakdown of the key components to make the code easier to understand:

Initialization and Constants

The file starts by including necessary headers and defining constants such as sz18_7 and sz16_7, which represent the sizes of various arrays used in the hashing process.
The Mhash class contains multiple static arrays and methods, with syms providing a representation of card symbols.

Mhash Class Constructor

The constructor initializes arrays and counts the number of bits set to 1 in 16-bit and 18-bit slices. It populates the bc16 and bc18 arrays with these counts and prepares indices for hashing by counting combinations.

Generate Method

The generate method creates switch cases based on the number of bits set in each slice. It prints out the switch cases for different combinations of bit slices and calculates the total count for each case.

pN Method

The pN method prints a representation of the bit pattern using card symbols. It helps visualize which cards are included in a given bit pattern.

timeHash and testHash Methods

These methods test the hashing function by iterating over all possible 7-card combinations from a 52-card deck. They verify that each unique hand is hashed to a unique value and count occurrences to ensure correctness.

mentalHash Method

The mentalHash method performs the actual hashing of a 7-card hand. It projects bits out of the 64-bit integer, determines the number of set bits, and uses a switch statement (included from switch.cpp) to calculate the hash value.
By following this structure, the code ensures that each unique 7-card hand is hashed efficiently and accurately, making it suitable for fast analysis of poker games.

