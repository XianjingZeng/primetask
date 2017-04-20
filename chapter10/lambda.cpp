#include <iostream>

using namespace std;

void lamb()
{
	auto sum = [](int a, int b) {return a + b; };

	cout << sum(1, 1) << endl;

}

void add(int a)
{
	auto sum = [a](int b) { return a + b; };

	cout << sum(1) << endl;
}



int main()
{
	//lamb();
	add(2);

	system("pause");
	return 0;
}