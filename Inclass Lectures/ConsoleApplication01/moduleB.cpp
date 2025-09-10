#include <iostream>
#include "moduleB.h"

//extern int x; // declaration, not definition

static int expenses = 10000;

void useX() {
	std::cout << "square of x is: " << x * x << std::endl;
	std::cout << "&x: " << &x << std::endl;
	std::cout << "expenses: " << expenses << std::endl;
	std::cout << "&expenses: " << &expenses << std::endl;
}