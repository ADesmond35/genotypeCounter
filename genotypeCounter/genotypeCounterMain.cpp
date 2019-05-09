//genotypeCounterMain.cpp
//Authors: Alex Desmond, Nick Kushch

#include <iostream>
#include <fstream>
#include <string>
#define NUM_ROWS 5
#define NUM_PATIENTS 5
using namespace std;

int main() {
	ofstream outFile;
	outFile.open("genotypeCounts.txt", ios::out | ios::trunc);
	outFile << "RSID\tChromosome\tPosn\tAA\tAG\tAT\tCC\tGG\n"; //Header line of output file

	string fileName[NUM_PATIENTS] = { "samp1.txt","samp2.txt","samp3.txt","samp4.txt","samp5.txt"};
	ifstream inFile[NUM_PATIENTS];
	for (int i = 0; i < NUM_PATIENTS; i++) {
		inFile[i].open(fileName[i]);
	}

	for (int row = 1; row <= NUM_ROWS; row++) {
		string rsid, genotype;
		int chromosome, position;
		int counter[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Initialize all counters to 0: AA, AG, AT, CC, GG ...

		for (int fileNumber = 0; fileNumber < NUM_PATIENTS; fileNumber++) {

			inFile[fileNumber] >> rsid;
			inFile[fileNumber] >> chromosome;
			inFile[fileNumber] >> position;
			inFile[fileNumber] >> genotype;

			if (genotype == "AA") {
				counter[0]++;
			}
			else if (genotype == "AG") {
				counter[1]++;
			}
			else if (genotype == "AT") {
				counter[2]++;
			}
			else if (genotype == "CC") {
				counter[3]++;
			}
			else if (genotype == "GG") {
				counter[4]++;
			}
			/*
			else if (genotype == "") {
				counter[5]++;
			}
			else if (genotype == "") {
				counter[6]++;
			}
			else if (genotype == "") {
				counter[7]++;
			}
			else if (genotype == "") {
				counter[8]++;
			}
			else if (genotype == "") {
				counter[9]++;
			}
			else if (genotype == "") {
				counter[10]++;
			}
			else if (genotype == "") {
				counter[11]++;
			}
			else if (genotype == "") {
				counter[12]++;
			}
			else if (genotype == "") {
				counter[13]++;
			}
			*/
		}

		outFile << rsid << "\t" << chromosome << "\t" << position << "\t";;
		for (int i = 0; i < 14; i++) {
			outFile << counter[i] << "\t";
		}
		outFile << "\n";
	}
	for (int i = 0; i < NUM_PATIENTS; i++) {
		inFile[i].close();
	}
	outFile.close();
}