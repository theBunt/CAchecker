#include "FileCheck.h"
#include <sstream>

FileCheck::FileCheck()
{

}

FileCheck::FileCheck(string fname)
{
	cout << "\n **********    creating filecheck object           ***************" << name << endl;
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

void FileCheck::assessWord(string &wordToCheck)
{
	if (wordToCheck == "if" || wordToCheck == "switch" || wordToCheck == "else")
		selectionCount++;
	else if (wordToCheck == "for" || wordToCheck == "while")
		itterativeCount++;
	else if (wordToCheck == "int" || wordToCheck == "long" || wordToCheck == "double" || wordToCheck == "short" || wordToCheck == "string" || wordToCheck == "char"
		|| wordToCheck == "float" || wordToCheck == "byte" || wordToCheck == "vector")
		variableCount++;
	else {
		// let n be the size of the text and m the size of the
		// pattern
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m && i + j < n; j++)
		//		if (text[i + j] != pattern[j]) break;
		//	// mismatch found, break the inner loop
		//	if (j == m) // match found
		//}
		
	}
}

void FileCheck::readFile()
{
	displayInfo();
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
		bool wordAssesment = true;
		vector<string> lineArray;
		//char lineArray[100];
		string lineWithNoSpace = "";
		begin = inStream.tellg();
		while (!inStream.eof()) {
			while (getline(inStream, line)) {
				istringstream iss(line);
				wordAssesment = true;
				while (iss >> word) {
					/* do stuff with word */
					lineArray.push_back(word);
					if (word == "<include>")
						includeCount++;
					if ((word[0] == '/') && (word[1] == '/')) {
						//cout << "\n   SPOTTED A COMMENT  " << endl;
						wordAssesment = false;
						commentCount++;
					}
					//cout << word;
					if (wordAssesment) {
						assessWord(word);
						wordCount++;
					}
					}
				end++;
				for (int i = 0; i < lineArray.size(); i++)
					cout << lineArray[i] << endl;
				cout << "\t\t NEXT LINE  " << endl;
				lineArray.clear();
			}
		}
		cout << "line count = " << end;
		inStream.seekg(0, ios::end);
		end = inStream.tellg();
		fileSize = (end - begin);
		inStream.close();
}

void FileCheck::displayInfo()
{
	cout << "\nFile name : " << name << endl;
	cout << "Word count : " << wordCount << endl;
	cout << "Selection count : " << selectionCount << endl;
	cout << "Iterative count : " << itterativeCount << endl;
	cout << "Variable count : " << variableCount << endl;
	cout << "Comment count : " << commentCount << endl;
	cout << "File size : " << fileSize << " bytes." << endl;
}

void FileCheck::searchHaystack(string & haystack)
{
	/* 
	str - string = haystack
	obj - substring we're looking for = needle
	int Count(const std::string & str,
		const std::string & obj) {
		int n = 0;
		std::string::size_type pos = 0;
		while ((pos = needle.find(haystack, pos)) != std::string::npos) {
			n++;
			pos += haystack.size();
		}
		return n;
	}*/
	bool match = false;
	string needle = "";
	string *itPointer;
	string iteratives[2] = { "for","while"};
	itPointer = iteratives;
	string selection[2] = { "if","switch"};
	string variables[10] = { "int","long", "double", "float", "short", "string", "byte", "vector", "char", "bool" };
	int j = 0;
	for (int i = 0; i < 2; i++) {
		needle = iteratives[i];
		if (haystack[i] = needle[i]) {
			match = true;
			while (match) {

			}
		}
	}
	
}


