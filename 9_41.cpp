#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * inital a string with vector<char>
 */
void stringVvec()
{
	vector<char> v = { 'H', 'e', 'l', 'l', 'o' };

	string s(v.data(), v.size());

	cout << s << endl;
}

/**
 *insert or erase the oldval with newval
 */
void mod(string &s, const string &oldval, const string &newval)
{
	auto sit = s.begin();

	while (sit < s.end() - 1)
	{
		auto iter1 = sit;
		auto oit = oldval.begin();

		while (oit != oldval.end() && *iter1 == *oit)
		{
			++oit;
			++iter1;
		}
		if (oit == oldval.end())
		{
			sit = s.erase(sit, iter1);
			if (newval.size())
			{
				oit = newval.end();
				do {
					--oit;
					sit = s.insert(sit, *oit);
				} while (oit > newval.begin());
			}
			sit += newval.size();
		}
		else
			++sit;
	}
	//string::iterator nit = newval.begin();

}

/**
 *replace the oldval with newval
 */
void replace(string &s, const string &oldval, const string &newval)
{
	int p = 0;
	while ((p = s.find(oldval, p)) != string::npos)
	{
		s.replace(p, oldval.size(), newval);
		p += newval.size();
	}
}


/**
 *insert prefix and suffix
 */
void prefixAndsuffix(string &s, const string &prefix, const string &suffix)
{
	s.insert(s.begin(), 1, ' ');
	s.insert(s.begin(), prefix.begin(), prefix.end());
	s.append(" ");
	s.append(suffix);
}

int main()
{
	//stringVvec();

	/*string s = "tho thru tho!";
	cout << s << endl;

	mod(s, "thru", "through");
	cout << s << endl;

	mod(s, "tho", "though");
	cout << s << endl;

	replace(s, "thru", "through");
	cout << s << endl;

	replace(s, "tho", "though");
	cout << s << endl;*/

	string s1 = "jim";
	prefixAndsuffix(s1, "Mr.", "I");
	cout << s1 << endl;

	string s2 = "lily";
	prefixAndsuffix(s2, "Mrs.", "II");
	cout << s2 << endl;

	system("pause");
	return 0;
}