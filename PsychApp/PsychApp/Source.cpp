// Data Compiler: to take information from an EEG .csv file, store certain parts of the data
// in the program, catalogue those data points and find percentage of each in 1, 5, and 10 minute increments.

// Emma Gebben
// July 15, 2014
// Edited by Brennan Metzelaar

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>		// used for istringstream, which is used to convert strings into numbers.
#include <algorithm>	// used for the semicolon removal so that the string can be stored as an float without issues
#include <vector>


using namespace std;

int main() {

	string line;	// We will originally take data in as a string
	float nline;	// The string is now converted to a number, which will be stored here
	char rmChar = ':';	// Used to remove the semicolon ":" character

	// Two vectors, each is incontrol of storing a column of data from the .csv file
	vector<float> adata;	// Changed float to string, for now
	vector<float> bdata;


	ifstream data; // ifstream (input file stream) because we are reading from a file
	data.open("2301data.csv"); // Open the .csv file (p430 talks more about different file modes)

	// So we are checking to see if the file exists and can be opened (p425).
	if (data.fail()) {
		cout << "File does not exist." << endl;
		cout << "Exit program." << endl;
		exit(1);	// We exit the program
	}
	else if (!data.fail()) {				// If the file did not fail. This isn't necessary, I just do it to write a message that lets us know its happy.
		cout << "CSV file opened!\n";		// The message, its happy! :)
	}

	// Copy the file 2301data.csv into the 'line' string.
	// What we are doing here is very, simple. We get each line from each column, but only store the lines from the columns
	// that we want to keep. In this case we only care about column 2 and 8.
	while (getline(data, line)) {

		// need 1st and 7th columns
		getline(data, line, ',');	// 1st column, get/throwaway

		getline(data, line, ',');	// 2nd column, want
		line.erase(std::remove(line.begin(), line.end(), rmChar), line.end());	// The string "line" is combed for every semicolon ":" when it finds one it removes it
		istringstream(line) >> nline;	// Convert the string to a number
		adata.push_back(nline);			// Store 2nd column in vector adata

		getline(data, line, ',');		// 3rd column, get/throwaway
		getline(data, line, ',');		// 4th column, get/throwaway
		getline(data, line, ',');		// 5th column, get/throwaway
		getline(data, line, ',');		// 6th column, get/throwaway
		getline(data, line, ',');		// 7th column, get/throwaway
		
		getline(data, line, ',');		// 8th column, want
		istringstream(line) >> nline;	// Convert the string to a number
		bdata.push_back(nline);			// Store 8th column in vector bdata

		getline(data, line, ',');		// 9th column, get/throwaway
		getline(data, line, ',');		// 10th column, get/throwaway
	}

	data.close();	// Close the .csv file. We always want to do this when we are done writing or reading from the file in our program.


	// Lets print our vector of column data and see if it worked
	// Sample data for Elapsed Time
	cout << "Vector adata\n";
	cout << "Testing data from spot 0 to spot 3\n";
	cout << adata[0] << endl;			// NOTE! Each second is represented as 1000, so if you do math with these
	cout << adata[1] << endl;			// numbers you will probably want to divide it by 1000 so that you
	cout << adata[2] << endl;			// are getting the time in seconds.
	cout << adata[3] << endl;
	cout << endl;

	// Sample data for CogState
	cout << "Vector bdata\n";
	cout << "\n Testing data from spot 0 to spot 3\n";
	cout << bdata[0] << endl;
	cout << bdata[1] << endl;
	cout << bdata[2] << endl;
	cout << bdata[3] << endl;
	cout << endl;
}

