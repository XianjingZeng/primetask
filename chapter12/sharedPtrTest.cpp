#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int> > new_vector()
{
	return make_shared<vector<int> >();
}

void read_ints(shared_ptr<vector<int> > spv)
{
	int v;
	while (cin >> v)
		spv->push_back(v);
}

void print_ints(shared_ptr<vector<int> > spv)
{
	for (const auto &v : *spv)
		cout << v << " ";
	cout << endl;
}

//int main()
//{
//	shared_ptr<vector<int> > p = new_vector();
//	read_ints(p);
//	print_ints(p);
//
//	system("pause");
//	return 0;
//}