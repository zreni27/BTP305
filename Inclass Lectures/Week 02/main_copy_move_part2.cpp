#include <iostream>
#include <chrono>

// rule-of-three - cc, ca, des
// rule-of-5 - cc, ca, des, move constructor, move assignment operator
// Class variables, Class functions

class MyArray {
	int* elements;
	int size;
public:
	MyArray() { elements = nullptr; size = 0; }
	MyArray(const int* data, int psize) {
		if (data && size > 0) {
			size = psize;
			elements = new int[size];
			for (int i = 0; i < size; i++)
				elements[i] = data[i];
		}
		else {
			elements = nullptr;
			size = 0;
		}
	}

	//Copy Constructor
	MyArray(const MyArray& ma) {
		// current object is created
		elements = nullptr;
		size = 0;
		*this = ma;
	}

	// Copy assignment operator
	MyArray& operator=(const MyArray& ma) {
		if (this != &ma) { // guards against self-assignment
			delete[] elements;
			elements = nullptr;
			size = 0;
			if (ma.elements && ma.size > 0) {
				size = ma.size;
				elements = new int[size];
				for (int i = 0; i < size; i++)
					elements[i] = ma.elements[i];
			}
		}
		return *this;
	}

	// Move Constructor
		MyArray(MyArray&& ma) {
		**this = std::move(ma);
	}

	// Move assignment operator
	MyArray& operator=(MyArray&& ma) { // && for rvalue reference
		if (this != &ma) {
			delete[] elements;
			size = ma.size;
			elements = ma.elements; // moving the resource

			ma.elements = nullptr; // setting to default state
			ma.size = 0;
			}
		return *this;
	}

	void display(std::string str) const {
		std::cout << str << "[ ";
		if (elements && size > 0) {
			for (int i = 0; i < size; i++)
				std::cout << elements[i] << " ";
		}
		std::cout << "]" << (elements?elements: (int*)0xFFFFF) << "\n";
	}

	~MyArray() {
		delete[] elements;
	}
};
int main() {
	int numbers[]{ 2,4,5,6,9,12,23 };
	MyArray ma1(numbers, 7), ma2(&numbers[3], 4);

	ma1.display("ma1")
	ma2.display("ma2");

	// Copy operations/copy semantics
	MyArray ma3 = ma;
	ma3.display("ma3");

	// to.recordStartTime();
	ma2 = ma3; // time required
	// to.recordEndTime();

	ma2.display("ma2")

		// Move operations
		ma2m.display("ma2m");

	MyArray ma4 = std::move(ma1); // time required
	ma1.display("ma1");
	ma4.display("ma4");
	ma2.display("ma2");
	ma3.display("ma3");
	return 0;
}