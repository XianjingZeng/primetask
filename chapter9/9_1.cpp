#include <vector>
#include <iostream>

using namespace std;

vector<int>::iterator search( vector<int> &v, int val)
{
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); ++it)
	{
		if (*it == val)
			break;
	}
	return it;
}


//int main()
//{
//	/*int a[] = { 1,2,3,4,5,6,7 };
//	vector<int> vec(a, a + 7);*/
//
//	vector<int> vec = { 1,2,3,4,5,6,7 };
//
//	vector<int>::iterator it = search(vec, 8);
//
//	if (it != vec.end()) {
//		cout << *it << endl;
//	}
//	else
//		cout << "not find" << endl;
//
//	system("pause");
//	return 0;
//}