#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/Header.h"

using namespace std;

int count_file_lines(ifstream& out);
void outFileArray(ifstream& out, string path, Employee* emp, int count_emp);
void printArray(Employee* emp, int count_emp);


int main()
{

	int number_key = 200;
	int id = 0;

	// Инициализируем путь и массив объектов.
	string path = "data/in_inordered.txt";
	ifstream out(path);
	int count_emp = count_file_lines(out) - 1;
	Employee* emp = new Employee[count_emp];

	// Записываем в массив объектов, неупорядоченные записи с файла.
	outFileArray(out, path, emp, count_emp);
	cout << " > Emoloyee (inordered): " << endl;
	printArray(emp, count_emp);

	// Последовательный поиск.
	id = SequentialSearch(emp, count_emp, number_key);
	cout << "Searched Employee: " << ((id == -1) ?  "Unknown Employee." : emp[id].toString());


	// Записываем в массив объектов, упорядоченные записи с файла.
	path = "data/in_ordered.txt";
	outFileArray(out, path, emp, count_emp);
	cout << endl << endl << endl << " > Emoloyee (ordered): " << endl;
	printArray(emp, count_emp);

	// Бинарный поиск.
	id = BinarySearch(emp, count_emp, number_key);
	cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp[id].toString());

	// Удаляем созданный массив.
	delete[] emp;



	system("pause > nul");
	
}



int count_file_lines(ifstream& out) {
	// Подсчёт количества строк в файле.
	// out - входной файловый поток.
	string str;
	int j = 0;
	while (out) {
		getline(out, str);
		j++;
	}
	out.close();
	return j;
}

void printArray(Employee* emp, int count_emp) {
	// Вывод массива объектов Employee.
	for (int i = 0; i < count_emp; i++) {
		cout << emp[i].toString() << endl;
	}

}

void outFileArray(ifstream& out, string path, Employee* emp, int count_emp) {
	// Вывод данных из файла в объект.
	// out - входной файловый поток.
	// path - путь к файлу.
	// emp - массив объектов Employee.
	// count_emp - количество строк (записей) в файле.
	string line;
	out.open(path, ios::in); // Открываем файл для чтения.
	if (out.is_open()) { // Проверяем, если файл открыт.
		for (int i = 0; i < count_emp && getline(out, line); i++)
		{
			stringstream str(line); // инициализируем строковый поток.
			string t_name, t_date, t_salary; // вводим временные перменные.
			getline(str, t_name, ','); emp[i].id = stoi(t_name); // считываем id.
			getline(str, emp[i].name, ','); // считываем имя.
			getline(str, t_date, ',');  emp[i].bdate = Date(t_date); // считываем дату рождения.
			getline(str, emp[i].department, ','); // считываем департамент.
			getline(str, t_salary, ','); emp[i].salary = stod(t_salary);// считываем зарплату.
		}
	}
	out.close();
}

