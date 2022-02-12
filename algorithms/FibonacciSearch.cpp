#include "../include/Header.h"


/*
* ����� ���������.
* arr - ������ �������� ������ Employee.
* count - ���������� ��������� � �������.
* key - ���� ������.
*/
int FibonaccianSearch(Employee* arr, int key, int count) {

	cout << endl << endl << " > FibonaccianSearch: " << endl;

	// �������������� ������ ��������� 
	int fm2 = 0; // m-2 ������� ������ ���������.
	int fm1 = 1; // m-1 ������� ������ ���������.
	int fmM = fm2 + fm1; // m �������� ������ ���������.
	int it_count = 0; // ���������� ���������.

	// ���� ����������� ����� ��������� ����� count 
	while (fmM < count) {
		fm2 = fm1;
		fm1 = fmM;
		fmM = fm2 + fm1;
	}

	int offs = -1; // �����.

	while (fmM > 1) {
		
		it_count++;

		// ���������, ���� ����� ��������� �� ��������� �������.
		int i = min(offs + fm2, count - 1);

		// ���� �������� ����� ������ ��� ������� ��������, �������� ��������� �� offs �� i
		if (arr[i].id < key) {
			fmM = fm1;
			fm1 = fm2;
			fm2 = fmM - fm1;
			offs = i;
		}


		// ���� �������� ����� ������ ��� ������� ��������, �������� ��������� ����� i+1.
		else if (arr[i].id > key) {
			fmM = fm2;
			fm1 = fm1 - fm2;
			fm2 = fmM - fm1;
		}

		// ���� �������� �������, ����������.
		else {
			cout << "Count of iterrations: " << it_count << endl;
			return i;
		}

	}

	// ���������� ��������� ������� � ������.
	if (fm1 && arr[offs + 1].id == key) {
		cout << "Count of iterrations: " << it_count << endl;
		return offs + 1;
	}

	// ������� �� ��� ������.
	return -1;


}