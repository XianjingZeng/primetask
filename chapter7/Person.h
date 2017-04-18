#ifndef PERSON_H
#define PERSON_H
#endif // !PERSON_H

#include <string>


using namespace std;


class Person
{

private:
	string strName;
	string strAddress;


public:
	Person() {}
	Person(const string &name, const string &add) :strName(name), strAddress(add) {	}
	Person(istream &is) { is >> *this; }


	string getName() const{ return strName; }
	string getAdd() const { return strAddress; }

	istream& read(istream&, Person&);
	ostream& print(ostream&, const Person&);

	friend istream & operator>>(istream &, Person &);
};

istream & operator >> (istream &is, Person &p)
{
	is >> p.strName >> p.strAddress;
	return is;
}

istream& Person::read(istream &is, Person &p)
{
	is >> p.strName >> p.strAddress;
	return is;
}

ostream& Person::print(ostream &os, const Person &p)
{
	os << endl << "****************" << endl
		<< "name: " << p.getName() << endl
		<< "address: " << p.getAdd() << endl
		<< "***************" << endl;
	return os;
}