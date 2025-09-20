#include<iostream>

template<typename T>
T sum(T x, T y) {
	std::cout << "template function" << std::endl;
	return x + y;
}


// specialization (for char type)
template<>
char sum(char x, char y) {
	std::cout << "specialized function" << std::endl;
	char result = x + y;
	if (result > 'z' || result < 'a')
		result = 'z';
	return result;
}



// overloading 
char sum(char x, char y, char z) 
{
	std::cout << "overloaded function" << std::endl;
	char result = x + y;
	//std::cout << (int)x << "," << (int)y << "," << (int)result << std::endl;
	if (result > 'z' || result < 'a')
		result = 'a';
	return result;
}
 


int main() {

	int x = 5, y = 6;
	double xd = 4.5, yd = 6.5;
	std::string s1 = "Hello", s2 = " ", s3 = "World!";
	char c1 = 'a', c2 = 'b';// larger than 'z', set it to 'z'

	std::cout << sum(x, y) << std::endl;
	std::cout << sum(xd, yd) << std::endl;
	std::cout << sum(sum(s1, s2), s3) << std::endl;
	std::cout << sum(c1, c2) << std::endl;


	return 0;
}