#include <iostream>

// rule-of-three - cc, ca, des
// rule-of-5 - cc, ca, des, move constructor, move assignment operator
// Class variables, Class functions
using namespace std;

class MyArray {
	int* elements;
	int size;
	static int dummy;// class member
public:
	static int numOfObjects; // belongs to class/instance
	 static int getDummy() { // class member function
		 return dummy;
	}
	 static int getNumObjects() { // class member function
		 return numOfObjects;
	 }
	MyArray() { elements = nullptr; size = 0; numOfObjects++; }
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
		numOfObjects++;
	}

	//Copy Constructor
	MyArray(const MyArray& ma) {
		// current object is created
		elements = nullptr;
		size = 0;
		*this = ma;
		numOfObjects++;
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
		numOfObjects++;
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

	int& operator[](int i) {
		return i < 0 || i > size-1 ?dummy:elements[i];
	}

	int getSize() const {
		return size;
	}

	~MyArray() {
		delete[] elements;
		numOfObjects--;
	}
};

int MyArray::numOfObjects = 0; // initializing class variable
int MyArray::dummy = 0;
int main() {
	int numbers[]{ 2,4,5,6,9,12,23 };
	MyArray ma1(numbers, 7), ma2(&numbers[3], 4), ma2m(&numbers[3], 4);

	cout << "total active objects: " << MyArray::numOfObjects << endl;
	cout << "total active objects: " << ma1.numOfObjects << endl;
	cout << "total active objects: " << ma2.numOfObjects << endl;
	cout << "total active objects: " << ma2m.numOfObjects << endl;

	{
		MyArray m1, m2;
		cout << "total active objects: " << MyArray::numOfObjects << endl;
	}
	cout << "total active objects: " << MyArray::numOfObjects << endl;
	// how many objects are created and not destroyed yet.
	// class variable
	// class member function

	for (int i = 0; i < ma1, getSize(); i++)
		cout << ma1[i] << ' ';
		cout << endl;
		ma1[0] = 25;
		for (int i = 0; i < ma1, getSize(); i++)
			cout << ma1[i] << ' ';
		cout << endl;
		//ma1[-1] = 23;

		//cout << ma1[-6] << endl;
		cout << "dummy value: " << MyArray::getDummy << endl;
	return 0;
}