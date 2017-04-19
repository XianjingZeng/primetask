#include <forward_list>
#include <iostream>
#include <string>

using namespace std;


/**
 * delete element from forward_list
 */
void deleteforward_list()
{
	forward_list<int> fl = { 1,2,3,4,5,6,7 };

	auto pre = fl.before_begin();
	auto cur = fl.begin();

	while (cur != fl.end())
	{
		if (*cur & 1)
		{
			cur = fl.erase_after(pre);
		}
		else
		{
			pre = cur;
			++cur;
		}
	}

	for (auto i : fl)
		cout << i << " ";
	cout << endl;
}


/**
 * insert element into specific position
 */
void insertPos(forward_list<string> &fl, string str1, string str2)
{
	forward_list<string>::iterator pre = fl.before_begin();
	forward_list<string>::iterator cur = fl.begin();

	while (cur != fl.end())
		if (*cur == str1) break;
		else
		{
			pre = cur;
			++cur;
		}
	if (cur == fl.end())
		fl.insert_after(pre, str2);
	else
		fl.insert_after(cur, str2);
}

//int main()
//{
//	//deleteforward_list();
//
//	forward_list<string> fl = { "hello", "world", "test", "abc", "end" };
//
//	insertPos(fl, "hello", "new");
//	for (auto s : fl)
//		cout << s << " ";
//	cout << endl;
//
//	insertPos(fl, "ho", "new");
//	for (auto s : fl)
//		cout << s << " ";
//	cout << endl;
//
//
//	system("pause");
//	return 0;
//}