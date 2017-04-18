#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#endif

#include <iostream>
#include <string>
//#include "Screen.h"

using namespace std;

class Window_mgr
{
public:
	void clear();
};

class Screen
{
	friend void Window_mgr::clear();
public:
	Screen() {}
	Screen(unsigned h, unsigned w) :height(h), width(w),contents(h * w, ' ') {}
	Screen(unsigned h, unsigned w, char c) :height(h), width(w), contents(h * w, c) {}


private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
};


void Window_mgr::clear()
{
	Screen myScreen(10, 20, 'X');
	cout << "清理之前myScreen的内容是：" << endl;
	cout << myScreen.contents << endl;
	myScreen.contents = "";
	myScreen.cursor = 0;
	cout << "清理之后myScreen的内容是：" << endl;
	cout << myScreen.contents << endl;
}