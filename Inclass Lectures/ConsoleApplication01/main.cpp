#include <iostream>

int x = 5;

int main() {

	std::cout << "x: " << x << std::endl;

	int& xr = x;
	double  x = 15;
	std::cout << "x: " << x << std::endl;
	std::cout << "::x: " << ::x << std::endl;
	std::cout << "xr: " << xr << std::endl;
	{
		char x = 'a';

		std::cout << "x: " << x << std::endl;
	}

	// C++17
	if (int y = 55; x > 10) { // int variable 'y' initialized to 55. 

	}
	else {

	}

	return 0;
}