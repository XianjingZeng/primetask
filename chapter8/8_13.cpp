#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInf
{
	string name;
	vector<string> phone;
};

int readInf()
{
	fstream in("chapter8/phone.txt");
	if (!in)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	vector<PersonInf> people;
	string line, word;
	istringstream record;

	while (getline(in, line))
	{
		PersonInf p;
		record.clear();
		record.str(line);
		record >> p.name;
		while (record >> word)
		{
			p.phone.push_back(word);
		}
		people.push_back(p);
	}
	in.close();

	ostringstream os;
	for (auto p : people)
	{
		os << p.name << " ";
		for (auto num : p.phone)
		{
			os << num << " ";
		}
		os << endl;
	}

	cout << os.str() << endl;

	return 0;
}


int main()
{
	readInf();

	system("pause");
	return 0;
}