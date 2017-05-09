#ifndef LIMITED_QUOTE
#define LIMITED_QUOTE


#include "Disc_quote.h"

class Limited_quote : public Disc_quote
{
public:
	Limited_quote(const std::string &bookNo, double price, size_t qty,
		double discount) :Disc_quote(bookNo, price, qty, discount) {}

	double net_price(size_t cnt) const
	{
		if (cnt <= quantity)
			return (1 - discount) * price * cnt;
		else
			return (1 - discount) * price * quantity + price * (cnt - quantity);
	}
};

#endif // !LIMITED_QUOTE