#include <dirent.h>// directory header
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
using namespace std;
#include <string>
#include "ReadDirectory.h"



int main() // entry point of the program
{
	ReadDirectory readDir("Example");
	cout << readDir.getName() << endl;
	readDir.readDirFilenames();
	readDir.displayInfo();
	system("pause");

	return 0; // everything went OK

}