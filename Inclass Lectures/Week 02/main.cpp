#include <iostream>

void print(int& data);

void print(int&& data);
// lvalue and rvalue reference
int main() {
	int x = 5;
	int& xr = x;
	// temporary - persistant
	// rvalue expression 

	++x = 56; // ++x is lvalue expression
	//x++ = 65; // prvalue expression (x++), a type of rvalue expression

	int&& xrr = x++; // rvalue reference to refer to rvalue expression
	xrr = 78;

	int& xrr2 = x + 5;
	
	print(xr);
	print(xrr);
	print(+x);
	print(x++);
	print(std::move(x));

	return 0;
}

void print(int& data) { // function 1
	std::cout << "data: " << data << std::endl;
}

void print(int&& data) { // function 2
	// data is rvalue reference to a rvalue expression
	print(data); // which function does this call
	std::cout << "{" << data << "}" << endl;
}