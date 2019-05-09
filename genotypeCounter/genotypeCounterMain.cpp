//genotypeCounterMain.cpp
//Alex Desmond in collaboration with Nick Kushch

#include <iostream>
#include <fstream>
#include <string>
#define NUM_ROWS 5
using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;

	inFile.open("samp1.txt");
	outFile.open("genotypeCounts.txt", ios::out | ios::trunc);

	while (!inFile.eof()) {
		string rsid, genotype;
		int chromosome, position;
		int counter[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		inFile >> rsid;
		inFile >> chromosome;
		inFile >> position;
		inFile >> genotype;



	
		outFile << rsid << "\t" << chromosome << "\t" << position << "\t" << genotype << "\n";
		
	}

	inFile.close();
	outFile.close();
}