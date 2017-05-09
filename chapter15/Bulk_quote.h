#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	/*Bulk_quote(const std::string &bookNo, double sales_price, size_t cnt,
		double disc) :Disc_quote(bookNo, sales_price, cnt, disc) {}*/

	double net_price(size_t cnt) const
	{
		cout << "Bulk_quote::net_price(size_t) is running" << endl;
		if (cnt > quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	
	/*double net_price(size_t cnt) const override
	{
		if (cnt > min_qty)
			return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
		else
			return cnt * (1 - discount) * price;
	}

	virtual void debug()
	{
		Quote::debug;
		std::cout << " min_qty:" << min_qty << " discount:" << discount << std::endl;
	}*/

};


#endif // !BULK_QUOTE_H