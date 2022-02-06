/**
* Алгоритм бинарного поиска.
*/   
#include "../include/Header.h"
int BinarySearch(Employee* emp, int count_emp, int key) {
	// Бинарный поиск.
	// emp - массив объектов.
	// count_emp - количество сотрудников.
	// key - искомый номер сотрудника.
	cout << endl << endl << " > Binary Search: " << endl;
	int a = 0, b = count_emp - 1, c = 0;
	int it_count = 0;
	while (a < b) {
		it_count++;
		c = (a + b) / 2;
		if (key < emp[c].id) b = c - 1;
		else if (key > emp[c].id) a = c + 1;
		else {
			cout << "Count of iterrations: " << it_count << endl;
			return c;
		}
	}
	cout << "Count of iterrations: " << it_count << endl;
	return -1;
}
