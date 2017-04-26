#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
//#include <algorithm>

using namespace std;

string &tran(string &s)
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


void wordcount(string filename)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "cannot open file " << filename << endl;
	}

	map<string, int> wordCnt;
	string word;

	while (in >> word)
	{
		tran(word);
		++wordCnt[word];
	}

	for (auto w : wordCnt)
	{
		cout << w.first << " " << w.second << endl;
	}
}

void addChild(map<string, vector<string> > &families)
{
	cout << "type in another family, start with a line of family name,\n" <<
		"and all the children in a second line:" << endl;
	string familyName, child;
	cin >> familyName;

	while (cin >> child)
	{
		families[familyName].push_back(child);
	}
}

void families(string filename, map<string, vector<string> > &families)
{
	ifstream in(filename);
	if (!in)
		cout << "cannot open file " << filename << endl;

	
	string line;

	string familyName, child, children;
	//vector<string> children;
	while (getline(in, line))
	{
		istringstream s;
		s.str(line);
		s >> familyName;
		
		while (s >> child)
			families[familyName].push_back(child);
	}

	
	addChild(families);


}

//int main(int argc, char *argv[])
//{
//	//wordcount(argv[1]);
//	map<string, vector<string> > family;
//	families("chapter11/families.txt", family);
//	for (auto f : family)
//	{
//		cout << f.first << ":" << endl;
//		for (auto c : f.second)
//			cout << c << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}