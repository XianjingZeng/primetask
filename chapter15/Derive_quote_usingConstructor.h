#ifndef DERIVE_QUOTE_USINGCONSTRUCTOR
#define DERIVE_QUOTE_USINGCONSTRUCTOR


#include "Quote.h"

class Derive_quote_usingConstructor :public Quote
{
public:
	using Quote::Quote;
};


#endif // !DERIVE_QUOTE_USINGCONSTRUCTOR