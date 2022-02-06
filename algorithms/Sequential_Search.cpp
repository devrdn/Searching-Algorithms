/**
* Функция последовательный поиска.
*/
#include "../include/Header.h"
int SequentialSearch(Employee* emp, int count_emp, int key) {
	// emp - массив объектов.
	// count_emp - количество сотрудников.
	// key - искомый номер сотрудника.
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
	return -1;
}