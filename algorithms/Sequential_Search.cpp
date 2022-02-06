/**
* ������� ���������������� ������.
*/
#include "../include/Header.h"
int SequentialSearch(Employee* emp, int count_emp, int key) {
	// emp - ������ ��������.
	// count_emp - ���������� �����������.
	// key - ������� ����� ����������.
	cout << endl << endl << " > Sequential Search: " << endl;
	int it_count = 0;
	for (int i = 0; i < count_emp; i++) {
		it_count++;
		if (emp[i].id == key) { // ���� ����� ����������, ������ � �������, �� ���������� �������.
			cout << "Count of iterrations: " << it_count << endl;
			return i;
		}
	}
	cout << "Count of iterrations: " << it_count << endl;
	return -1;
}