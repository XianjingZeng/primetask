#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v;
	v.reserve(1024);
	cout << "init capa: " << v.capacity() << endl;

	int size = 1537;
	for (int i = 0; i < size; ++i)
		v.push_back(i);
	cout << "after push " << size << " integers, capa : " << v.capacity() << endl;
	
	v.resize(v.size() + v.size() / 2);
	cout << "after resize, capa: " << v.capacity() << endl;

	system("pause");
	return 0;
}