// main.cpp
// Finley McIlwaine
// COSC2030 Lab 9
// 12/10/2018
// Sorting using tally via stl map

#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using std::ifstream;
using std::ofstream;
using std::map;
using std::string;

void tallyWords(map<string, int>& wordTally, ifstream& infile);
void printSortedWords(map<string, int>& wordTally, ofstream& outfile);

int main()
{
	string infileName  = "example.txt";   // input file name
	string outfileName = "output.txt";    // output file name
	map<string, int> wordTally;           // tally map
	ifstream infile(infileName);          // input file stream
	ofstream outfile(outfileName);        // output file stream

	tallyWords(wordTally, infile);        // tally the words in the input file
	infile.close();                       // close infile stream

	printSortedWords(wordTally, outfile); // print the sorted words to the output file
	outfile.close();                      // close the outfile stream
}

// pre:  wordTally is an empty std::map and infile has not been read from
// post: wordTally contains word keys with values being how many times they occured while reading infile
void tallyWords(map<string, int>& wordTally, ifstream& infile) {
	string buffer;
	while (infile) {
		infile >> buffer;
		++wordTally[buffer];
	}
}

// pre:  outfile has not been printed to
// post: outfile contains a string of the sorted words from infile
void printSortedWords(map<string, int>& wordTally, ofstream& outfile) {
	map<string, int>::iterator it = wordTally.begin();
	while (it != wordTally.end()) {
		outfile << it->first;
		outfile << " ";
		++it;
	}
}