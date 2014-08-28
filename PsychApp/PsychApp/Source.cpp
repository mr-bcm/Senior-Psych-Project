// Data Compiler: to take information from an EEG .csv file, store certain parts of the data
// in the program, catalogue those data points and find percentage of each in 1, 5, and 10 minute increments.

// Emma Gebben
// July 15, 2014 [1st attempt at build, with outline from Pete Tucker: CS Professor at Whitworth University]

#include <iostream>
#include <string>	//bcm
#include <fstream>
#include <vector>


using namespace std;

vector<string> split(string s) {
	vector<string> ret;
	size_t start = 0;
	size_t end = s.find('\t', start);
	while (end != string::npos) {
		ret.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find('\t', start);
	}

	return ret;
}


int main() {


	string line;
	int count = 0;
	float sum = 0;
	vector<string> adata;	// changed float to string, for now
	vector<string> bdata;


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

	// copy the file 2301data.csv into the 'line' string.
	while (getline(data, line)) {

		// need 1st and 7th columns
		getline(data, line, ',');	// 1st column, get/throwaway

		getline(data, line, ',');	// 2nd column, want
		adata.push_back(line);	// Store 2nd column in vector adata

		getline(data, line, ',');	// 3rd column, get/throwaway
		getline(data, line, ',');	// 4th column, get/throwaway
		getline(data, line, ',');	// 5th column, get/throwaway
		getline(data, line, ',');	// 6th column, get/throwaway
		getline(data, line, ',');	// 7th column, get/throwaway
		
		getline(data, line, ',');	// 8th column, want
		bdata.push_back(line);	// Store 8th column in vector bdata

		getline(data, line, ',');	// 9th column, get/throwaway
		getline(data, line, ',');	// 10th column, get/throwaway
	}

	data.close();	// close the .csv file. We always want to do this when we are done writing or reading from the file in our program.


	// lets print our vector of column data and see if it worked
	// cout << line << endl;
	for (int a = 0; a < adata.size(); a++){
		cout << adata[a] << endl;
	}

	cout << endl;
	cout << "Vector adata\n";
	cout << "Testing data from spot 0 to spot 3\n";
	cout << adata[0] << endl;
	cout << adata[1] << endl;
	cout << adata[2] << endl;
	cout << adata[3] << endl;
	cout << endl;


	//for (int b = 0; b < bdata.size(); b++){
	//	cout << bdata[b] << endl;
	//}

	cout << "Vector bdata\n";
	cout << "\n Testing data from spot 0 to spot 3\n";
	cout << bdata[0] << endl;
	cout << bdata[1] << endl;
	cout << bdata[2] << endl;
	cout << bdata[3] << endl;
	cout << endl;
}

