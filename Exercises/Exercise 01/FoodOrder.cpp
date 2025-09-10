#include "FoodOrder.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

double g_taxrate = 0;
double g_dailydiscount = 0;


namespace seneca {

	FoodOrder::FoodOrder() : f_foodDesc{ nullptr }, f_foodPrice{ 0 }, f_isSpecial{ false } {
		f_customerName[0] = '\0';
	}

	void FoodOrder::read(istream& is) {
		if (!is) return;

		string customerName, foodDesc;
		double foodPrice;
		char isSpecial;
		char comma;

		getline(is, customerName, ',');
		getline(is, foodDesc, ',');
		is >> foodPrice >> comma;
		is >> ws;
		is.get(isSpecial);

		strncpy(f_customerName, customerName.c_str(), sizeof(f_customerName) - 1);
		f_customerName[sizeof(f_customerName) - 1] = '\0';

		delete[] f_foodDesc;
		f_foodDesc = new char[foodDesc.length() + 1];
		strcpy(f_foodDesc, foodDesc.c_str());

		f_foodPrice = foodPrice;

		f_isSpecial = (isSpecial == 'Y');
	}

	void FoodOrder::display() {
		static int cnt = 0;
		cnt++;

		if (f_customerName[0] == '\0') {
			cout << left << setw(2) << cnt << ". No Order" << endl;
			return;
		}
		
		double priceWithTax = f_foodPrice * (1 + g_taxrate);
		double specialPrice = priceWithTax;

		if (f_isSpecial) {
			specialPrice = priceWithTax / g_dailydiscount;
		}

		cout << left << setw(2) << cnt << ". "
			<< left << setw(10) << f_customerName << "|"
			<< left << setw(25) << f_foodDesc << "|"
			<< left << setw(12) << fixed << setprecision(2) << priceWithTax << "|";

		if (f_isSpecial) {
			cout << right << setw(13) << fixed << setprecision(2) << specialPrice;
		}

		cout << endl;
	}
}
