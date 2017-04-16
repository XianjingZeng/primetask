#include <string>

using namespace std;

class Screen
{

public:
	Screen() {}
	Screen(unsigned h, unsigned w) :height(h), width(w),contents(h * w, ' ') {}
	Screen(unsigned h, unsigned w, char c) :height(h), width(w), contents(h * w, c) {}
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
};