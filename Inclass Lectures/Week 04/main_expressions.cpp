#include <iostream>

// Expression 
// value categories -- categories with respect to which expressions can be 
//  categorized. 

// lvalue - rvalue 
// glvalue, xvalue, prvalue 

/*
			value cateory

	      glvalue        rvalue 


	lvalue       xvalue        prvalue



*/

void foo() noexcept {

}

void foo(const char* name) {
	if (name && name[0] != '\0') { // valid and it is not empty
		std::cout << name << std::endl;
	}
}



int main() {
	//noexcept(foo);


	int x = 5; 

	const int size = 5;

	//size = 45; // value cateo
	// modifiable lvalue, non-modifiable lvalue 
	char charr[] = "Seneca"; // string literal
	std::cout << (int*)charr << std::endl;
	std::cout << &"Seneca" << std::endl;

	const char* colName = "Seneca";

	charr[0] = 'M';

	// []

	//x + 5 = 20; // lvalue - locator value 
	 // x+5 - value category is 'prvalue'
	//x++ = 20;
	//-x = 35;

	++x = 20;
	//(x++)++;
	// 

	&x; // lvalue expression 

	//!x = 20;
	//! 
	
	foo("Seneca");
	foo(nullptr);

	int a, b;

	x > 5 ? a : b = 67;


	return 0;
}