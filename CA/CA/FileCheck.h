#pragma once
#include <dirent.h>// directory header
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
#include <vector>
using namespace std;
#include <string>

#include <fstream>
using std::ifstream;
using std::ofstream;

class FileCheck
{
private:
	int fileSize;
	int wordCount;
	int variableCount;
	int itterativeCount;
	int selectionCount;
	int lineCount;
	int commentCount;
	int includeCount;
	string name;
	ifstream inStream;
	ofstream outStream;
	static const string selectionWords[];
	static const string ierativeWords[];
	static const string variableTypes[];
public:
	FileCheck();
	FileCheck(string);
	void assessWord(string & wordToCheck);
	void readFile();
	void displayInfo();
	void searchHaystack(string &haystack);
};
