#include <string>
#include <iostream>
//#include "Window_mgr.h"

using namespace std;
class Window_mgr;

class Screen
{
	friend void Window_mgr::clear();
public:
	Screen() {}
	Screen(unsigned h, unsigned w) :height(h), width(w),contents(h * w, ' ') {}
	Screen(unsigned h, unsigned w, char c) :height(h), width(w), contents(h * w, c) {}

	//Screen & move(unsigned x, unsigned y)
	Screen  move(unsigned x, unsigned y)
	{
		cursor = x * width + y;
		return *this;
	}

	//Screen &  set(char c)
	Screen  set(char c)
	{
		contents[cursor] = c;
		return *this;
	}

	ostream & display(ostream &os) const
	{
		for (int i = 0; i < contents.size(); ++i)
		{
			if (i % width == 0)
				os << endl;
			os << contents[i];
		}
		os << endl;
		return os;
	}

	

private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
};