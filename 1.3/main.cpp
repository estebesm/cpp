#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");

	int initialValue;

	std::cout << "¬ведите целое число:" << std::endl;
	std::cin >> initialValue;

	for (int i = 1; i <= 10; ++i) {
		std::cout << initialValue << " x " << i << " = " << initialValue * i << std::endl;
	}


	return 0;
}