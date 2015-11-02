#include"FileCheck.h"
#include<sstream>
#include<iomanip>
using namespace std;

const std::string FileCheck::variableTypes[8]= // initialized here (not in the constructor)
{ "double","char","int","float","bool","long","string","byte" };

const std::string FileCheck::selectionWords[4] = 
{ "if","else","switch","case"};

const std::string FileCheck::ierativeWords[2] =
{ "for","while"};

FileCheck::FileCheck()
{

}

FileCheck::FileCheck(string fname)
{
	//cout << "\n **********    creating filecheck object           ***************" << name << endl;
	name = fname;
	fileSize = 0;
	wordCount = 0;
	itterativeCount = 0;
	selectionCount = 0;
	lineCount = 0;
	variableCount = 0;
	commentCount = 0;
	includeCount = 0;
	readFile();
}

void FileCheck::assessWord(string & wordToCheck)
{
	if (wordToCheck == "if" || wordToCheck == "switch" || wordToCheck == "else")
		selectionCount++;
	if (wordToCheck == "for" || wordToCheck == "while")
		itterativeCount++;
	if (wordToCheck == "int" || wordToCheck == "long" || wordToCheck == "double" || wordToCheck == "short" || wordToCheck == "string" || wordToCheck == "char"
		|| wordToCheck == "float" || wordToCheck == "byte" || wordToCheck == "vector")
		variableCount++;
}

void FileCheck::readFile()
{
	//displayInfo();
	long begin = 0;
	long end = 0;
	inStream.open(name);
		if (inStream.fail())
		{
			cout << "\nInput file opening failed.\n";
			system("pause");
			exit(1);
		}
		cout << "\n******************\nExtracting from file: " << name << endl;
		string word ,line;
		bool commentline = false;
		bool multilineComment = false;
		string haystack = "";
		//while the instrem still has something to read
		while (!inStream.eof()) {
			int i = 1;
			// read the file line by line
			while (getline(inStream, line)) {
				cout << "\n"<<i << ". \t";
				istringstream iss(line);
				commentline = false;
				while (iss >> word) {
					/* do stuff word by word */
					if ((word[0] == '/') && (word[1] == '/')) {
						cout << "  SPOTTED A COMMENT  " << endl;
						commentline = true;
						commentCount++;
					}
					//if spotted a multiline comment do nothing with the word until end of multiline comment
					else if ((word[0] == '/') && (word[1] == '*')) {
						multilineComment = true;
						cout << "multiline code = ";
						char now;
						char next;
						while (multilineComment) {
							inStream.get(now);
							next = inStream.peek();
							cout << now;
							if (now == '*' && next == '/') {
								multilineComment = false;
								haystack = "";
							}
						}
					}
					else if (!commentline)
						haystack.append(word);
					}
				if (haystack != "{" || haystack != "}" || haystack != "" )
					searchHaystack(haystack);
				haystack = "";
				i++;
			}
		}
		inStream.close();
}

void FileCheck::displayInfo()
{
	cout << "" << endl;
	cout << "File Name : " << name << endl;
	cout << "" << endl;
	cout << setfill('-') << setw(110) << "-" << endl;
	cout  <<  "Word Count" << setw(20) << setfill(' ') <<  "Selection Count" << setw(20) << "Iterative Count" << setw(20) << "Variable Count" << setw(20) << "Comment Count" << setw(15) << "File Size" << endl;
	cout << setfill('-') << setw(110) << "-" << endl;
	cout << setw(2) << setfill(' ') << wordCount << setw(20) << selectionCount << setw(20) << itterativeCount << setw(20) << variableCount << setw(20) << commentCount << setw(20) << fileSize << endl;
	cout << setfill('-') << setw(110) << "-" << endl;
	cout << "" << endl;
	cout << "includes = " << includeCount;

	/*
	cout << "Selection count : " << selectionCount << endl;
	cout << "Iterative count : " << itterativeCount << endl;
	cout << "Variable count : " << variableCount << endl;
	cout << "Comment count : " << commentCount << endl;
	cout << "File size : " << fileSize << " bytes." << endl;*/
}
// coded by peter
void FileCheck::searchHaystack(string & haystack)
{
	cout << "Searching haystack = " << haystack << ": " << endl;
	string needle = "#include";
	std::size_t found = 0;
	while ((found = haystack.find(needle, found))
		!= std::string::npos) {
		includeCount++;
		found += needle.size();
		cout << "include found";
	}
	//search for iterative words
	for (int i = 0; i < 2; ++i) {
		found = 0;// found is reset to 0 each time to return to the start of the sentence
		needle = ierativeWords[i];
		while ((found = haystack.find(needle, found))
			!= std::string::npos) {
			itterativeCount++;
			found += needle.size();
			cout << needle << " found!!";
		}
	}
	//search for variable defs
	for (int i = 0; i < 9; ++i) {
		found = 0;
		needle = variableTypes[i];
		while ((found = haystack.find(needle, found))
			!= std::string::npos) {
			//cout << "NEEDLE = " << needle;
			variableCount++;
			found += needle.size();
			cout << needle << " found!!";
		}
	}
	//search for selectionWords
	for (int i = 0; i < 4; ++i) {
		found = 0;
		needle = selectionWords[i];
		while ((found = haystack.find(needle, found))
			!= std::string::npos) {
			selectionCount++;
			found += needle.size();
			cout << needle << " found!!";
		}
	}
}
