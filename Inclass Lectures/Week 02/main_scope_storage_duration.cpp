#include <iostream>
#include <thread>

int x = 20;
static int y = 30;

namespace seneca {
	int s_x = 20;
	int s_y = 100;
}

class MyClass {
	int x;
public:

	void foo() const;
};

void MyClass::foo() const {
	//..
}

// Storage duration
// automatic
// static
// dynamic
// thread

// 2011 C++ standard - multithreading

// Task
thread_local int age;
void printHello(std::string name, int p_age) {
	age = p_age;
	std::cout << "Hello " << name << "!" <<  "You are " << age << " year old." << std::endl;
	std::cout << &age << std::endl;
}

int main() {

	std::thread t1(printHello, "John", 22);
	std::thread t2(printHello, "Sally", 24);

	t1.join();
	t2.join();

	int x;

	{
		double y;
	}

	int* iptr = new int(25); // dynamic storage duration

	for (int i = 0, j = 0; i < 5; i++, j--) {
		int m;
	}

	if (int i = 0; true) {
		double b;
	}
	/*
	char choice = 'y';
	switch (int j = 5; choice) {
	case 'y':

	case 'n':

	}
	*/

	delete iptr;


}