#include <iostream>
#include "process.h"
#include "CString.h"
 
using namespace std;
 
int main(int argc, char** argv)
{
	cout << "Command Line :";
	for (int i = 0; i < argc; i++)
	{
		cout << " " << argv[i];
	}
	cout << endl;
 
	if (argc == 1)
	{
		cout << "Insufficient number of arguments (min 1)" << endl;
	}
	else
	{
		cout << "Maximum number of characters stored : " << w1::MAX << endl;
		for (int i = 1; i < argc; i++)
		{			
			w1::process(argv[i]);
		}
	}
 
	return 0;
}