#include "../include/Header.h"

/*
* Последовательный поиск.
* emp - массив объектов класса Employee.
* count_emp - количество элементов в массиве.
* key - ключ поиска.
*/
int SequentialSearch(Employee* emp, int count_emp, int key) {
	cout << endl << endl << " > Sequential Search: " << endl;
	int it_count = 0;
	for (int i = 0; i < count_emp; i++) {
		it_count++;
		if (emp[i].id == key) { // Если номер сотрудника, совпал с искомым, то возвращаем позицию.
			cout << "Count of iterrations: " << it_count << endl;
			return i;
		}
	}
	cout << "Count of iterrations: " << it_count << endl;
	// Если сотрудник не был найден, то возвращаем -1.
	return -1;
}