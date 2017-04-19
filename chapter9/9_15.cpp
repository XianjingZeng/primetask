#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

/**
 *list<char *> assign to vector<string>
 */

void ptrListTostrVec()
{
	list<char *> clist = { "hello" , "abc", "!" };

	vector<string> vec;
	vec.assign(clist.begin(), clist.end());

	for (auto s : vec)
		cout << s << " ";
	cout << endl;
}


/**
 *vector compare
 */

void comparevector()
{
	vector<int> ivec = { 1,2,3,4,5,6,7 };
	vector<int> ivec1 = { 1,2,3,4,5,6,7 };
	vector<int> ivec2 = { 1,2,3,4,5, };
	vector<int> ivec3 = { 1,2,3,4,5,6,8 };
	vector<int> ivec4 = { 1,2,3,4,5,7,6 };

	cout << (ivec == ivec1) << endl;
	cout << (ivec == ivec2) << endl;
	cout << (ivec == ivec3) << endl;
	cout << (ivec == ivec4) << endl;

	ivec1.push_back(8);
	ivec1.pop_back();
	cout << ivec1.capacity() << " " << ivec1.size() << endl;
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl << (ivec == ivec1) << endl;

}

/**
 * deque operation
 */
void dequeop()
{
	deque<string> q;
	
	string word;
	
	while (cin >> word)
	{
		q.push_back(word);
	}

	for (auto it = q.cbegin(); it != q.cend(); ++it)
		cout << *it << " ";
	cout << endl;
}

//int main()
//{
//	//ptrListTostrVec();
//	//comparevector();
//	dequeop();
//
//	system("pause");
//	return 0;
//}