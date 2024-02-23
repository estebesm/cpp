
#include <iostream>
#include <cstdlib>
#include <ctime>

class Cell {
public: 
	int x, y;
	char c;
};

Cell** createTable(unsigned int rows, unsigned int cols) {
	Cell** table = new Cell*[rows];
	std::srand(std::time(0));

	char letters[] = "ABCDE";

	for (int i = 0; i < rows; i++) {
		table[i] = new Cell[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			char c = letters[rand() % 5];
			table[i][j].x = i;
			table[i][j].y = j;
			table[i][j].c = c;
		}
	}
	return table;
}

void printTable(Cell** table, unsigned int rows, unsigned int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			std::cout << table[i][j].c << " ";
		}
		std::cout << std::endl;
	}
}

void mySolve(Cell** table, unsigned int cols, unsigned int rows) {
	bool found = false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			if (j < cols - 2 && table[i][j].c == table[i][j + 1].c && table[i][j].c == table[i][j + 2].c) {
				found = true;
				break;
			}
			if (i < rows - 2 && table[i][j].c == table[i + 1][j].c && table[i][j].c == table[i + 2][j].c) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}

	std::cout << (found ? "В таблице есть три символа в ряд" : "В таблице нет трех символов в ряд") << std::endl;
}

void deleteTable(Cell** table, unsigned int rows, unsigned int cols) {
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

	Cell** table = createTable(ROWS, COLS);

	std::cout << "Исходная таблица" << std::endl;
	printTable(table, ROWS, COLS);

	mySolve(table, ROWS, COLS);

	deleteTable(table, ROWS, COLS);

	return 0;
};