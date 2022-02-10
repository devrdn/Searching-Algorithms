#include "../include/Header.h"

/*
* arr - ������ �������� ������ Employee.
* count - ���������� ��������� � �������.
* key - ���� ������.
*/
int InterpolationSearch(Employee* arr, int count, int key) {
	cout << endl << endl << " > Interpolation Search: " << endl;
	int left = 0;  int right = count - 1; // ������� ����� � ������ �������.
	int it_count = 0; // ������� ��������.

	// ����� ������� �������, ������ ���� ������, ��� �����.
	// ���� ������ ��������� � �������� ������������ ��������.
	while (left <= right && key >= arr[left].id && key <= arr[right].id) {
		it_count++;
		if (left == right) {
			cout << "Count of iterrations: " << it_count << endl;
			if (arr[left].id == key)
				return left;
			return -1;
		}

		// ������� ������� �� ������� ������������.
		int position = left + (((double)(right - left) / (arr[right].id - arr[left].id)) * (key - arr[left].id));

		// ���� ��� ������ � �������.
		if (arr[position].id == key) {
			cout << "Count of iterrations: " << it_count << endl;
			return position;
		}
		
		// ���� ��������� ����� ������� �������.
		if (arr[position].id < key)
			left = position + 1;

		// ���� ��������� ����� ������� ��������.
		else
			right = position - 1;
	}

	// ���� ��������� �� ��� ������.
	return -1;
}