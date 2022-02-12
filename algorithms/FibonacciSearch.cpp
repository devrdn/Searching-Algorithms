#include "../include/Header.h"


/*
* Поиск Фиббоначи.
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
*/
int FibonaccianSearch(Employee* arr, int key, int count) {

	cout << endl << endl << " > FibonaccianSearch: " << endl;

	// Инициализируем список Фибоначчи 
	int fm2 = 0; // m-2 элемент списка Фибоначчи.
	int fm1 = 1; // m-1 элемент списка Фибоначчи.
	int fmM = fm2 + fm1; // m элемента списка фибоначчи.
	int it_count = 0; // Количество иттераций.

	// Ищем минимальное число Фиббоначи после count 
	while (fmM < count) {
		fm2 = fm1;
		fm1 = fmM;
		fmM = fm2 + fm1;
	}

	int offs = -1; // Сдвиг.

	while (fmM > 1) {
		
		it_count++;

		// Проверяем, если число Фиббоначи на правильно позиции.
		int i = min(offs + fm2, count - 1);

		// Если значение ключи больше чем текущее значение, отрезаем подмассив от offs до i
		if (arr[i].id < key) {
			fmM = fm1;
			fm1 = fm2;
			fm2 = fmM - fm1;
			offs = i;
		}


		// Если значения ключа меньше чем текущее значение, отрезаем подмассив после i+1.
		else if (arr[i].id > key) {
			fmM = fm2;
			fm1 = fm1 - fm2;
			fm2 = fmM - fm1;
		}

		// Если значение найдено, возвращаем.
		else {
			cout << "Count of iterrations: " << it_count << endl;
			return i;
		}

	}

	// Сравниваем последний элемент с ключём.
	if (fm1 && arr[offs + 1].id == key) {
		cout << "Count of iterrations: " << it_count << endl;
		return offs + 1;
	}

	// Элемент не был найден.
	return -1;


}