#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

string &trans(string &s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= ('A' - 'a');
		else if (s[i] == ',' || s[i] == '.' || s[i] == ';')
			s.erase(i, 1);
	}
	return s;
}


void lineCnt(string filename)
{
	ifstream in(filename);
	if (!in)
		cout << "cannot open " << filename << endl;

	string line, word;
	int lineNum(0);

	map<string, list<int> > words;

	while (getline(in, line))
	{
		++lineNum;
		istringstream is;
		is.str(line);
		while (is >> word)
		{
			trans(word);
			words[word].push_back(lineNum);
		}
	}


	for (auto w : words)
	{
		cout << w.first << " shows in line ";
		for (auto linenum : w.second)
			cout << linenum << ",";
		cout << endl;
	}
			
}


//int main()
//{
//
//	lineCnt("chapter11/data.txt");
//
//	system("pause");
//	return 0;
//}