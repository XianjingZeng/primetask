#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int line_and_words()
{
	fstream in("chapter8/data.txt");
	if (!in)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	vector<string> lines;
	string line;
	while (getline(in,line))
	{
		lines.push_back(line);

	}
	in.close();

	for (vector<string>::iterator it = lines.begin(); it != lines.end();
		++it)
	{
		istringstream is(*it);
		string word;
		while (is >> word)
		{
			cout << word << " ";
		}
		cout << endl;
	}
	return 0;
}


//int main()
//{
//	line_and_words();
//
//	system("pause");
//	return 0;
//}