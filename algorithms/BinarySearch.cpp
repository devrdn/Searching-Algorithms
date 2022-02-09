#include "../include/Header.h"

/*
* Бинарный поиск.
* emp - массив объектов класса Employee.
* count_emp - количество элементов в массиве.
* key - ключ поиска.
*/
int BinarySearch(Employee* emp, int count_emp, int key) {
	cout << endl << endl << " > Binary Search: " << endl;
	int a = 0, b = count_emp - 1, c = 0;
	int it_count = 0;
	/* Выполняем условия, до тех пор пока не вышли за пределы массива */
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