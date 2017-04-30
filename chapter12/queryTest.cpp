#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "my_TextQuery.h"

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;

	}
}

int main()
{
	string filename = "chapter11/data.txt";
	ifstream infile;

	if (!(infile.open(filename), infile))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}

	runQueries(infile);
	return 0;

}