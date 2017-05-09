#ifndef DRIVE_QUOTE_H
#define DRIVE_QUOTE_H


#include "Quote.h"

class Drive_quote : public Quote
{
public:
	Drive_quote(const std::string &bookNo, double sales_price, size_t qty,
		double disc) :Quote(bookNo, sales_price),min_qty(qty),discount(disc)
	{
		std::cout << "Drive_quote constructor is running " << std::endl;
	}


	double net_price(size_t cnt) const override
	{
	if (cnt > min_qty)
		return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
	else
		return cnt * (1 - discount) * price;
	}

	virtual void debug()
	{
		Quote::debug();
		std::cout << " min_qty:" << min_qty << " discount:" << discount << std::endl;
	}

	~Drive_quote()
	{
		cout << "Drive_quote destructor is running" << endl;
	}
	
private:
	size_t min_qty;
	double discount;

};

std::ostream& operator<<(std::ostream &os, Drive_quote &d)
{
	os << "using operator<<(std::ostream&, Drive_quote&);" << std::endl;
	return os;
}


#endif // !DRIVE_QUOTE_H