#include "../include/Header.h"

/*
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
*/
int InterpolationSearch(Employee* arr, int count, int key) {
	cout << endl << endl << " > Interpolation Search: " << endl;
	int left = 0;  int right = count - 1; // »ндексы конца и начала массива.
	int it_count = 0; // —четчик итераций.

	// Левая сторона отрезка, должна быть меньше, чем лева¤.
	//  Ключ должен находитс¤ в пределах определенных отерзком.
	while (left <= right && key >= arr[left].id && key <= arr[right].id) {
		it_count++;
		if (left == right) {
			cout << "Count of iterrations: " << it_count << endl;
			if (arr[left].id == key)
				return left;
			return -1;
		}

		// Считаем позицию по формуле интерпол¤ции.
		int position = left + (((double)(right - left) / (arr[right].id - arr[left].id)) * (key - arr[left].id));

		//  Ключ был найден в массиве.
		if (arr[position].id == key) {
			cout << "Count of iterrations: " << it_count << endl;
			return position;
		}
		
		//  Ключ находитс¤ после текущей позиции.
		if (arr[position].id < key)
			left = position + 1;

		//  Ключ находитс¤ перед текущей позицией.
		else
			right = position - 1;
	}

	// Если сотрудник не был найден.
	return -1;
}