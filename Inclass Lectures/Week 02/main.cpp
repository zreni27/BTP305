#include <iostream>

// rule-of-three - cc, ca, des
// rule-of-5 - cc, ca, des, move constructor, move assignment operator

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
		*this = ma;
	}

	// Copy assignment operator
	MyArray& operator=(const MyArray& ma) {
		if (this != &ma) {
			delete[] elements;
			elements = nullptr;
			size = 0;
			if (ma.elements && ma.size > 0) {
				size = ma.size;
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
			elements = ma.elements; // moving the resource
			size = ma.size;

			ma.elements = nullptr; // setting to default state
			ma.size = 0;
			}
		return *this;
	}

	~MyArray() {
		delete[] elements;
	}
};
int main() {
	int numbers[]{ 2,4,5,6,9,12,23 };
	MyArray ma(numbers, 7);


	return 0;
}