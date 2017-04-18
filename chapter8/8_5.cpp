#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int read_word()
{
	fstream in("chapter8/data.txt");
	if (!in)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (in >> line)
	{
		words.push_back(line);
	}

	in.close();

	for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}


//int main()
//{
//	read_word();
//
//	system("pause");
//	return 0;
//}