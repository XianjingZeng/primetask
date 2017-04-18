#include <iostream>
#include <fstream>
#include "../chapter7/Sales_data.h"

using namespace std;
/*
int getdata(char *filename)
{
	

	ifstream in(filename);
	if (!in)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	Sales_data total(in);
	if (total.isbn() != "")
	{
		while (!in.eof())
		{
			Sales_data tran(in);
			if (tran.isbn() == total.isbn())
				total += tran;
			else
			{
				//cout << total;
				print(cout, total);
				total = tran;
			}
		}
		print(cout, total);
	}
	else
		cout << "no data" << endl;
	return 0;
}
*/
//int main(int argc, char *argv[])
//{
//	if (argc < 2)
//	{
//		cerr << "type in filename" << endl;
//		return -1;
//	}
//	getdata(argv[1]);
//
//	system("pause");
//
//	return 0;
//}