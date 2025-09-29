#include <iostream>
#include <chrono>

// specialization

struct MyType {
	std::string fname;
	std::string lname;
	//char fname[25];
	//char lname[25];
	MyType() = default;
	
	MyType(const char* fn, const char* ln) {
		if (fn && ln) {
			fname = fn;
			lname = ln;
		}
	}
	
};

// Class variables, Class functions
using namespace std;
// type parameter, nontype parameter
template<typename T, int N=100>
class MyArray {
	T* elements;
	int size;
	int capacity;
	static T dummy; // class member 
public:
	static int numOfObjects; // belongs to class/instance
	static T getDummy() { // class member function 
		return dummy;
	}
	static int getNumOObjects() { // class member function 
		return numOfObjects;
	}
	MyArray() { 
		//elements = nullptr; 
		//size = 0; 
		size = 0;
		capacity = N;
		elements = new T[capacity];
		numOfObjects++; }
	MyArray(const T* data, int psize) {
		size = 0;
		capacity = N;
		elements = new T[capacity]; // requires default constructor
		if (data && psize > 0 && psize < capacity) {
			size = psize;
			//elements = new T[size];
			for (int i = 0; i < size; i++)
				elements[i] = data[i];
		}
		else {
			elements = nullptr;
			size = 0;
		}
		numOfObjects++;
	}

	/*
	// Copy constructor
	MyArray(const MyArray& ma) {
		// current object is created
		elements = nullptr;
		//capacity = N;
		size = 0;
		*this = ma;
		numOfObjects++;
	}
	// Copy assignment operator
	MyArray& operator=(const MyArray& ma) {
		if (this != &ma) { // guards agains self-assignment
			delete[] elements;
			elements = nullptr;
			size = 0;
			if (ma.elements && ma.size > 0) {
				size = ma.size;
				elements = new T[size];
				for (int i = 0; i < size; i++)
					elements[i] = ma.elements[i];
			}
		}
		return *this;
	}

	// Move constructor
	MyArray(MyArray&& ma) {
		*this = move(ma);
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
	*/
	void display(std::string str) const {
		std::cout << str << "[ ";
		if (elements && size > 0) {
			for (int i = 0; i < size; i++)
				std::cout << elements[i] << " ";
		}
		//std::cout << "]" << (elements ? elements : (int*)0xFFFFF) << "\n";
	}

	T& operator[](int i) {
		return i<0 || i>size-1 ?dummy:elements[i];
	}
	const T& operator[](int i) const {
		return i<0 || i>size - 1 ? dummy : elements[i];
	}

	int getSize() const {
		return size;
	}


	~MyArray() {
		delete[] elements;
		numOfObjects--;
	}
};

template<typename T, int N>
int MyArray<T,N>::numOfObjects{}; // initializing class variable

template<typename T, int N>
T MyArray<T, N>::dummy{};

// specialize this initialization differently for MyType and 3 
template<>
MyType MyArray<MyType, 3>::dummy("Xxxx", "Yyyy");


// Specialization of class member definition -- due next class 

// Protein sequences

int main() {
	int iarr[]{ 2, 5, 6, 23, 43, 4,5, 56, 78 }; // 9
	double darr[]{ 3.2,4.5,6.7,67.6,3.33,2.22,7.6,8.8,4.4 };//9

	// instantiation of template class: process of creating 
	//    version of templated class for a particular type
	//    -- outcome -- a class 

	// instantiation of the class: outcome is object.
	MyArray<int,9> obj1(iarr,9); // template instantiation, object creation
	MyArray<int,7> obj2(&iarr[1], 7);
	MyArray<int, 9> objt(iarr, 9); // 
	for (int i = 0; i < obj1.getSize(); i++)
		std::cout << obj1[i] << ' ';
	std::cout << std::endl;
	for (int i = 0; i < obj2.getSize(); i++)
		std::cout << obj2[i] << ' ';
	std::cout << std::endl;


	MyArray<double,12> obj3(darr, 9); // instantiation+object creation
	MyArray<double,8> obj4(&darr[1], 7); // only object creation
	MyArray<double> obj5(&darr[2], 5); // only object creation
	for (int i = 0; i < obj3.getSize(); i++)
		std::cout << obj3[i] << ' ';
	std::cout << std::endl;
	for (int i = 0; i < obj4.getSize(); i++)
		std::cout << obj4[i] << ' ';
	std::cout << std::endl;

	std::string sarr[]{ "Tornoto", "Ottawa", "Montreal" };
	MyArray<std::string, 3> obj6(sarr,3);

	// defalt value for MyType {"Xxxx","Yyyy"}
	MyType mtarr[]{ {"John","kerry"},{"Sara","Sparrow"},{"abc","xyz"} };
	MyArray<MyType, 3> obj7(mtarr, 3);
	std::cout << obj7[3].fname << "," << obj7[3].lname << std::endl;


	return  0;
}