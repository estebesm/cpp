#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::srand(std::time(0));


	//Создание и заполнение массива

	int table[8][6];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			int randomNumber = std::rand() % 5 + 1;
			table[i][j] = randomNumber;
			std::cout << table[i][j] << "  ";

		}
		std::cout << std::endl;
	}

	// Решение

	bool found = false;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (table[i][j] == table[i][j + 1] && table[i][j] == table[i][j + 2]) {
				found = true;
				break;
			}
			if (table[i][j] == table[i + 1][j] && table[i][j] == table[i + 2][j]) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}

	std::cout << (found ? "В таблице есть три числа в ряд" : "В таблице нет трех чисел в ряд");


	return 0;
}
