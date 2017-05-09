#include "Basket.h"
#include "Bulk_quote.h"
#include <vector>

//int main()
//{
//	Basket b;
//	vector<shared_ptr<Quote> > items_v;
//	for (int i = 0; i < 10; ++i)
//	{
//		Bulk_quote q1("c++ prime", 6, 5, 0.5);
//		shared_ptr<Quote> sq1 = make_shared<Quote>(q1);
//		items_v.push_back(sq1);
//		//b.add_item(const_cast(sq1));
//	}
//
//	for (vector<shared_ptr<Quote> >::const_iterator iter = items_v.begin();
//		iter != items_v.end(); ++iter)
//	{
//		b.add_item(*iter);
//	}
//	b.total_receipt(cout);
//
//	system("pause");
//	return 0;
//}