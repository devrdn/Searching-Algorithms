#include "../include/Header.h"

/*
* ���������������� �����.
* emp - ������ �������� ������ Employee.
* count_emp - ���������� ��������� � �������.
* key - ���� ������.
* @return -1
*/
int SequentialSearch(Employee* emp, int count_emp, int key) {
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
	// ���� ��������� �� ��� ������, �� ���������� -1.
	return -1;
}