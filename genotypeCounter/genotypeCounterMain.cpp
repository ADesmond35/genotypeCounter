//genotypeCounterMain.cpp
//Authors: Alex Desmond, Nick Kushch
//This program as is reads in patient data WITHOUT a header line; The first and every row of each input file should be actual data

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#define NUM_ROWS 5
#define NUM_PATIENTS 5 // If changing NUM_PATIENTS, update list of file names at the start of main

int main() {
	ofstream outFile;
	outFile.open("genotypeCounts.txt", ios::out | ios::trunc);
	outFile << "RSID\tChromosome\tPosn\tAA\tAG\tAT\tCC\tGG\n"; // Header line of output file

	ifstream inFile[NUM_PATIENTS];
	string fileName[NUM_PATIENTS] = {"samp1.txt","samp2.txt","samp3.txt","samp4.txt","samp5.txt"}; // All filenames go in this array. If adding or removing files, update NUM_PATIENTS
	for (int i = 0; i < NUM_PATIENTS; i++) {
		inFile[i].open(fileName[i]);
	}

	for (int row = 1; row <= NUM_ROWS; row++) { // Loop through all rows (number of rows defined in preprocessor)
		string rsid, genotype;
		int chromosome, position;
		int counter[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Initialize all counters to 0: AA, AG, AT, CC, GG ...

		for (int fileNumber = 0; fileNumber < NUM_PATIENTS; fileNumber++) { // Loop through all open input files

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
		} //End of inner loop

		outFile << rsid << "\t" << chromosome << "\t" << position;
		for (int i = 0; i < 14; i++) {
			outFile << "\t" << counter[i]; //Print all counters to output file
		}
		outFile << "\n";

	} // End of outer loop

	for (int i = 0; i < NUM_PATIENTS; i++) {
		inFile[i].close();
	}
	outFile.close();
}