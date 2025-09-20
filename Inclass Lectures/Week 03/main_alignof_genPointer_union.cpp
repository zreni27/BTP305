#include <iostream>

enum class Cities{Toronto, Ottawa, Hamilton}; // plain enumeration

struct Data {
	int x;
	double y;
	char z;
};

union DataU {
	int x;
	double y;
	char z;
};


int main()
{
	Cities cvar;
	cvar = Cities::Toronto;

	char name[] = { "Toronto" };

	Data dat;
	std::cout << sizeof(dat) << std::endl;
	std::cout << &dat << std::endl;
	std::cout << &dat.x << std::endl;
	std::cout << &dat.y << std::endl;
	std::cout << (int*)&dat.z << std::endl;
	std::cout << &name[0] << std::endl;

	DataU du;
	std::cout << sizeof(du) << std::endl;
	du.x = 25;
	std::cout << du.x << std::endl;
	std::cout << du.y << std::endl;
	du.y = 33.33;
	std::cout << du.y << std::endl;
	du.z = 'A';
	std::cout << du.z << std::endl;

	// generic pointer 
	int* iptr;
	void* gptr;

	int x = 55;
	gptr = &x;

	std::cout << *static_cast<int*>(gptr) << std::endl;

	double y = 22.22;
	gptr = &y;

	std::cout << *static_cast<double*>(gptr) << std::endl;
	std::cout << *static_cast<int*>(gptr) << std::endl;
	//[0x...0, 0x...1,0x...2,0x...3,0x...4,0x...5,0x...6]

	char ch='a';
	int ix;

	//std::cout << alignof(ch) << std::endl;
	std::cout << alignof(char) << std::endl;
	std::cout << alignof(int) << std::endl;
	std::cout << alignof(double) << std::endl;

	std::cout << alignof(Data) << std::endl;

	alignas(8) int ix2;

	return 0;
}

