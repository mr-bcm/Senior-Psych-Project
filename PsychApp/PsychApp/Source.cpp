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
	vector<float> alldata;


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
		cout << line << endl;
	}

	data.close();	// close the .csv file. We always want to do this when we are done writing or reading from the file in our program.





















	//// was: while(data.getline(line)) { error
	//while (getline(data, line)) {
	//	vector<string> row = split(line);
	//	alldata.push_back(atof(row[1].c_str()));
	//}

	//for (int i = 0; i < alldata.size(); i++) {
	//	count++;
	//	sum += alldata[i];
	//}

	//cout << "average: " << sum / count << "\n";
}

