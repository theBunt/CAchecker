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
		begin = inStream.tellg();
		while (!inStream.eof()) {
			while (getline(inStream, line)) {
				istringstream iss(line);
				wordAssesment = true;
				while (iss >> word) {
					/* do stuff with word */

					if ((word[0] == '/') && (word[1] == '/')) {
						cout << "\n   SPOTTED A COMMENT  " << endl;
						wordAssesment = false;
						commentCount++;
					}
					cout << word << " ";
					wordCount++;
					if (wordAssesment)
						assessWord(word);
					}
				//end++;
				cout << "\n   NEXT LINE  " << endl;
			}
		}
		cout << "line count " << end;
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
