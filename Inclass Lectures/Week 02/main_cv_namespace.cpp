// cv qualifiers
// namespace

// const volatile

#include <iostream>

// nested namespace, anonymous

namespace seneca {
	int x = 10;
	namespace bsd {
		double x = 5.6;
	}
}

namespace { // sets interal linkage
	int xd = 20;
	double yd = 2.2;
}

int main() {
	int w = 10; // none
	const int x = 20; // const
	volatile int y = 30; //volatile - this variable can be modified and it may also have side-effect
	const volatile int z = 40; // const volatile - will not be modified by the code, but it may have side effect

	std::cout << seneca::x << std::endl;
	std::cout << seneca::bsd::x << std::endl;

	seneca::x += 2;
	seneca::bsd::x += 3;

	std::cout << xd << std::endl;

	return 0;
}