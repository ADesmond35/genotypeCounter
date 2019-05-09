//genotypeCounterMain.cpp
//Authors: Alex Desmond, Nick Kushch
//This program as is reads in patient data WITHOUT a header line; The first and every row of each input file should be actual data

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#define NUM_ROWS 5
#define NUM_PATIENTS 5 // If changing NUM_PATIENTS, update list of file names at the start of main
#define NUM_GENOTYPES 14

int main() {

	ifstream inFile;
	string fileName[NUM_PATIENTS] = {"samp1.txt","samp2.txt","samp3.txt","samp4.txt","samp5.txt"}; // If adding or removing files, update NUM_PATIENTS
	int counter[NUM_ROWS][NUM_GENOTYPES];

	for (int row = 0; row < NUM_ROWS; row++){ // Loop through all rows (NUM_ROWS defined in preprocessor (before main))
		for (int counterIndex = 0; counterIndex < NUM_GENOTYPES; counterIndex++){
			counter[row][counterIndex] = 0; // Initialize all counters to 0
		}
	}

	for (int fileNumber = 0; fileNumber < NUM_PATIENTS; fileNumber++) { // Loop through input files

		string rsid, genotype; //declare string variables
		int chromosome, position; //declare integer variables
		
		inFile.open(fileName[fileNumber]);

		while (inFile.peek() == '#'){
			string garbage;
			getline(inFile,garbage);
		}

		for (int row = 0; row < NUM_ROWS; row++){ // Loop through all rows (NUM_ROWS defined in preprocessor (before main))

			inFile >> rsid;
			inFile >> chromosome;
			inFile >> position;
			inFile >> genotype;

			if (genotype == "AA") { // AA, AT, AC, AG, TT, CT GT, CC, CG, GG, DD, DI, II, --
				counter[row][0]++;
			}
			else if (genotype == "AT") {
				counter[row][1]++;
			}
			else if (genotype == "AC") {
				counter[row][2]++;
			}
			else if (genotype == "AG") {
				counter[row][3]++;
			}
			else if (genotype == "TT") {
				counter[row][4]++;
			}
			else if (genotype == "CT") {
				counter[row][5]++;
			}
			else if (genotype == "GT") {
				counter[row][6]++;
			}
			else if (genotype == "CC") {
				counter[row][7]++;
			}
			else if (genotype == "CG") {
				counter[row][8]++;
			}
			else if (genotype == "GG") {
				counter[row][9]++;
			}
			else if (genotype == "DD") {
				counter[row][10]++;
			}
			else if (genotype == "DI") {
				counter[row][11]++;
			}
			else if (genotype == "II") {
				counter[row][12]++;
			}
			else if (genotype == "--") {
				counter[row][13]++;
			}
			
		} //End of inner loop

		inFile.close();
	} // End of outer loop

	inFile.open(fileName[0]);
	ofstream outFile;
	outFile.open("genotypeCounts.txt", ios::out | ios::trunc);
	outFile << "RSID\tChromosome\tPosn\tAA\tAT\tAC\tAG\tTT\tCT\tGT\tCC\tCG\tGG\tDD\tDI\tII\t--\n"; // Header line of output file

	for (int row = 0; row < NUM_ROWS; row++){
		string rsid, genotype; //declare string variables
		int chromosome, position; //declare integer variables

		inFile >> rsid;
		inFile >> chromosome;
		inFile >> position;
		inFile >> genotype;
		outFile << rsid << "\t" << chromosome << "\t" << position;

		for (int counterIndex = 0; counterIndex < NUM_GENOTYPES; counterIndex++){
			outFile << "\t" << counter[row][counterIndex]; //Print all counters to output file
		}
		outFile << "\n";
	}

	inFile.close();
	outFile.close();
}