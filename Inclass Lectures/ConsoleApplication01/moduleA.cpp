#include <iostream>

int x = 10; // declaration which is also definition

// interal linkage
static int expenses = 4000.44; // dollar and cents

void printX() {
	std::cout << "x(modA): " << x << std::endl;
	std::cout << "&x: " << &x << std::endl;
	std::cout << "exp: " << expenses << std::endl;
	std::cout << "&exp: " << &expenses << std::endl;
}