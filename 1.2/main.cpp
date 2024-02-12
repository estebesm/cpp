#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");

	int initialValue, result = 0;

	std::cout << "Введите целое число:" << std::endl;
	std::cin >> initialValue;

	while (initialValue > 0) {
		result += initialValue % 10;
		initialValue /= 10;
	}

	std::cout << "Сумма цифр: " << result;

	return 0;
}