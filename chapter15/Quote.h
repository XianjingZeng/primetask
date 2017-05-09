#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &bookNo, double sales_price) :
		bookNo(bookNo), price(sales_price) 
	{
		//std::cout << "Quote constructor is running" << std::endl;
	}

	std::string isbn() const{ return bookNo; }

	virtual double net_price(std::size_t n) const 
	{ 
		cout << "Quote::net_price(size_t) is running" << endl; 
		return n*price; 
	}
	virtual void debug()
	{
		std::cout << "bookNo:" << bookNo << " price:" << price << std::endl;
	}
	virtual ~Quote()
	{
		//std::cout << "Quote destructor is running" << std::endl;
	}

	friend std::ostream & operator<<(std::ostream&, Quote&);
	//friend double print_total(std::ostream &, const Quote &, size_t );

private:
	std::string bookNo;
protected:
	double price = 0;
};

static double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double t = item.net_price(n);

	os << "booNo:" << item.isbn() << " sold " << n << " total due:" << t << std::endl;
	return t;
}



#endif // !QUOTE_H