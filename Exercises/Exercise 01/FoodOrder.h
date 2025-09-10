#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;


namespace seneca {
	class FoodOrder {
		char f_customerName[10];
		char* f_foodDesc;
		double f_foodPrice;
		bool f_isSpecial;

	public:
		FoodOrder();
		void read(std::istream&);
		void display();
	};
}

#endif