#include <iostream>
#include <map>
#include <string>

using namespace std;

void addChild(multimap<string, string> &family, const string &familyName, const string &child)
{
	family.insert({ familyName, child });
}

//int main()
//{
//	multimap<string, string> family;
//	addChild(family, "zhang", "qiang");
//	addChild(family, "zhang", "ming");
//	addChild(family, "zeng", "jing");
//	addChild(family, "zhang", "xian");
//
//	for (auto f : family)
//	{
//		cout << f.first << " " << f.second << endl;
//	}
//
//	system("pause");
//	return 0;
//}