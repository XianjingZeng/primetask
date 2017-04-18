#include <iostream>
#include <fstream>
#include "../chapter7/Sales_data.h"

using namespace std;

int recdata(char *recname, char *outname)
{


	ifstream in(recname);
	if (!in)
	{
		cerr << "open file failed" << endl;
		return -1;
	}
	//ofstream out(outname);
	ofstream out(outname,ofstream::app);
	if (!out)
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
				print(out, total);
				total = tran;
			}
		}
		print(out, total);
	}
	else
		cout << "no data" << endl;
	in.close();
	out.close();
	return 0;
}

//int main(int argc, char *argv[])
//{
//	if (argc < 3)
//	{
//		cerr << "type in filename" << endl;
//		return -1;
//	}
//	recdata(argv[1],argv[2]);
//
//	system("pause");
//
//	return 0;
//}