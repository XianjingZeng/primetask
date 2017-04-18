#include <iostream>
#include <stdexcept>

using namespace std;

istream & f(istream &is)
{
	int v;
	while (is >> v, !is.eof())
	{
		if (is.bad())
		{
			throw runtime_error("IO flow error");
		}
		if (is.fail())
		{
			cerr << "data error, try again:" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}

	is.clear();
	return is;
}

//
//int main()
//{
//	cout << "type in some integers, end with 'ctrl + z'." << endl;
//	f(cin);
//
//	system("pause");
//	return 0;
//}