#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int value, result = 0;
	do {
		std::cout << "Введите целое число или число '0', чтобы закончить:" << std::endl;
		std::cin >> value;
		result += value;
	} while (value != 0);

	std::cout << "Сумма: " << result << std::endl;
	return 0;
}