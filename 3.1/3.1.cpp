
#include <iostream>
#include <cstdlib>
#include <ctime>

int** createTable(unsigned int rows, unsigned int cols) {
	int** table = new int* [rows];
	std::srand(std::time(0));

	for (int i = 0; i < rows; i++) {
		table[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			table[i][j] = std::rand() % 5 + 1;
		}
	}
	return table;
}

void printTable(int** table, unsigned int rows, unsigned int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void mySolve(int** table, unsigned int cols, unsigned int rows) {
	bool found = false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
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

	std::cout << (found ? "В таблице есть три числа в ряд" : "В таблице нет трех чисел в ряд") << std::endl;
}

void deleteTable(int** table, unsigned int rows, unsigned int cols) {
	for (int i = 0; i < rows; ++i) {
		delete[] table[i];
	}
	delete[] table;
}

int main() {
	setlocale(LC_ALL, "Russian");

	unsigned int COLS, ROWS;

	std::cout << "Введите количество строк таблицы:" << std::endl;
	std::cin >> ROWS;

	std::cout << "Введите количество столбцов таблицы:" << std::endl;
	std::cin >> COLS;

	int** table = createTable(ROWS, COLS);

	std::cout << "Исходная таблица" << std::endl;
	printTable(table, ROWS, COLS);

	mySolve(table, ROWS, COLS);

	deleteTable(table, ROWS, COLS);

	return 0;
};