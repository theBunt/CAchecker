#include "FileCheck.h"
#include <sstream>
#include <iomanip>
using namespace std;


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
	readFile();
	
}

void FileCheck::assessWord(string wordToCheck)
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
		//cout << "\n******************\nExtracting from file: " << name << endl;
		string word ,line;
		bool wordAssesment = true;
		
		while (!inStream.eof()) {
			while (getline(inStream, line)) {
				istringstream iss(line);
				wordAssesment = true;
				while (iss >> word) {
					/* do stuff with word */

					if ((word[0] == '/') && (word[1] == '/')) {
						//cout << "\n   SPOTTED A COMMENT  " << endl;
						wordAssesment = false;
						commentCount++;
					}
					//cout << word << " ";
					wordCount++;
					if (wordAssesment)
						assessWord(word);
				}

				//cout << "\n   NEXT LINE  " << endl;

			}
		}
		//cout << "line count " << end;
		
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

	/*
	cout << "Selection count : " << selectionCount << endl;
	cout << "Iterative count : " << itterativeCount << endl;
	cout << "Variable count : " << variableCount << endl;
	cout << "Comment count : " << commentCount << endl;
	cout << "File size : " << fileSize << " bytes." << endl;*/
}
