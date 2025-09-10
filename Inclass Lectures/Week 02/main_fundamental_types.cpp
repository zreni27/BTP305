#include <iostream>

int main() {
	int w = 24;
	int x = 024; // 20 - 16 + 4 - 4 (20 decimal)
	int y = 0x24; //hexadecimal 20 - 32 (36 decimal)
	int z = 0b100001000010011100101;

	std::cout << w << ", " << x << ", " << y << ", " << z << std::endl;

	auto a = 0133L;
	std::cout << typeid(a).name() << std::endl;
	//// to be continued....
	
	

	return 0;
}