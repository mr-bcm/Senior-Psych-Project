// Project by Emma Gebben
// Started July 15, 2014
// Edited by Brennan Metzelaar & Timothy Bradford

#include <iostream>
#include <string>// so I can have strings
#include <fstream>// for file inpu and output
#include <ctime>	// for random number generating
#include <cstdlib>	// for random number generating
#include <vector>	// allows us to use a vector
using namespace std;

// function prototype. This is needed when a function comes after main(){}. It just lets main know that something may come up that requires it to look outside itself.
vector<string> split(string);

int main(){

	string line; // line is a string that is used to get parts of the .csv file for us so that we can then store it in the vector
	vector<float> alldata; // vector alldata will be used to store all data from the .csv file
	int count = 0;	// NEEDS COMMENT
	float sum = 0;	// NEEDS COMMENT

	// Open the file 2301data.csv (for writing only)
	ifstream inputer("2301data.csv",ios::in);
	
	// checking to see if the program has been opened or not
	if(!inputer){
		cout<<"failed badly\n";
		return 0;
	}
	else if(inputer){cout << "it opened!!!\n";}

	//// this copys 2301data.csv into my doc string
	//while(getline(inputer,doc))
	//{	

	//	cout << doc <<endl;
	//}


	// Going to read the document into a vector
	while(getline(inputer,line)) // inputer is the ifstream that is dealing with the .csv file
	{	
		// this was made by Pete Tucker
		vector<string> row = split(line);
		alldata.push_back(atof(row[1].c_str()));	// Debug: this is where we crash. Specifically the issue is with "atof(row[1].c_str())"
		// atof is used to convert string to double.
		
		// cout << line <<endl; // was used to output the .csv file contents.
	}


   inputer.close();// closing the text doc

   // made by Pete Tucker
   for (int i = 0; i < alldata.size(); i++) {
	   count++;
	   sum += alldata[i];
   }

   // made by Pete Tucker
   cout << "average: " << sum / count << "\n";

	cout << line << "this is where line(doc) is \n"; // outputs my doc string
	
}

// function made by Pete Tucker
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