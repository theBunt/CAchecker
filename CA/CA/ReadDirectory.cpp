#include "ReadDirectory.h"
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
using namespace std;
#include <cstring>

#include <string>

ReadDirectory::ReadDirectory()
{
	name = "";
}

ReadDirectory::ReadDirectory(string id)
{
	name = id;
}

void ReadDirectory::readDirFilenames()
{
	// code taken from http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/
	//  *************************************************************************

	DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
	struct dirent *pent = NULL;
	name = "G:/algoData/checker";//hardcode for convenience, change to what suits!!
	/*string word = "";
	cout << "Enter the full path and directory name:\t";
	cin >> word;
	name = name + word;*/

	pdir = opendir(name.c_str()); // "." will refer to the current directory

	if (pdir == NULL) // if pdir wasn't initialised correctly
	{ // print an error message and exit the 
		cout << "\nERROR! pdir could not be initialised correctly";
		system("pause");
		exit(1); // exit the program, using 1 as the status (most common for a failed execution)
	} // end if

	string fName = "";
	while (pent = readdir(pdir)) // while there is still something in the directory to list
	{
		if (pent == NULL) // if pent has not been initialised correctly

		{ // print an error message, and exit the program
			cout << "ERROR! pent could not be initialised correctly";
			exit(3);
		}

		// otherwise, it was initialised correctly. let's print it on the console:

		else if (pent->d_name[0] != '.')
		{
			string temp = name;
			fName = pent->d_name;
			temp = name + "/" + fName;
			checkedForPlagurism.push_back(temp);
		}
	}

	closedir(pdir);

	// *****************************************************************************

}

string ReadDirectory::getName()
{
	return name;
}

void ReadDirectory::displayInfo()
{
	for (unsigned int i = 0; i < checkedForPlagurism.size(); i++) {
		checkedForPlagurism[i].displayInfo();
	}
}






