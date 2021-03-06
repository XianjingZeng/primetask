#ifndef SALES_DATA_H
#define SALES_DATA_H
#endif // !SALES_DATA_H

#include <string>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

class Sales_data
{
public:
	Sales_data() {}
	Sales_data(const string &book) :bookNo(book) {}
	Sales_data(const string &book, const unsigned num,
		const double sellp, const double salep);
	Sales_data(istream &is) { is >> *this; }

	friend istream& operator>>(istream &, Sales_data &);
	friend ostream& operator<<(ostream &, Sales_data &);
	///bool operator<(const Sales_data &);
	
	Sales_data& operator+=(const Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);

	string isbn() const { return bookNo; }
	istream& read(istream&, Sales_data&);
	ostream& print(ostream&, const Sales_data&);

private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};

Sales_data::Sales_data(const string &book, const unsigned num,
	const double sellp, const double salep):bookNo(book),units_sold(num),
	sellingprice(sellp),saleprice(salep)
{
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
}

istream& operator>>(istream &is, Sales_data &s)
{
	is >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (is && s.sellingprice != 0)
		s.discount = s.saleprice / s.sellingprice;
	else
		s = Sales_data();

	return is;
}

ostream& operator<<(ostream &os, Sales_data &s)
{
	os << endl << "****************" << endl
		<< "bookNo: " << s.isbn() << endl
		<< "units_sold: " << s.units_sold << endl
		<< "sellingprice: " << s.sellingprice << endl
		<< "saleprice: " << s.saleprice << endl
		<< "discount: " << s.discount << endl
		<< "***************" << endl;
	return os;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn()
		&& lhs.units_sold == rhs.units_sold
		&& lhs.sellingprice == rhs.sellingprice
		&& lhs.saleprice == rhs.saleprice;
}

Sales_data& Sales_data::operator+=(const Sales_data&s)
{
	units_sold += s.units_sold;
	saleprice = (s.saleprice * s.units_sold + saleprice * units_sold) / (s.units_sold + units_sold);
	if (sellingprice != 0)
		discount = saleprice / sellingprice;

	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

istream & Sales_data::read(istream &is, Sales_data &s)
{
	is >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (is && s.sellingprice != 0)
		s.discount = s.saleprice / s.sellingprice;
	else
		s = Sales_data();

	return is;
}


ostream& Sales_data::print(ostream &os, const Sales_data &s)
{
	os << endl << "****************" << endl
		<< "bookNo: " << s.isbn() << endl
		<< "units_sold: " << s.units_sold << endl
		<< "sellingprice: " << s.sellingprice << endl
		<< "saleprice: " << s.saleprice << endl
		<< "discount: " << s.discount << endl
		<< "***************" << endl;
	return os;
}