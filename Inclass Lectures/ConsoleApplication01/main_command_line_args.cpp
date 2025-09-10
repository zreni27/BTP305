#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// command line arguments
// ~jeevan.pant/submit 200/w1/lab_NAA -due

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		std::cout << i + 1 << "# " << argv[i] << std::endl;
	}
	char arg2[250];
	strcpy(arg2, argv[1]);
	std::cout << arg2 << std::endl;

	char arg3[250];
	strcpy(arg3, argv[1]);
	std::cout << arg3 << std::endl;

	char arg4 = atoi(argv[3]);
	std::cout << arg4 << std::endl;

}