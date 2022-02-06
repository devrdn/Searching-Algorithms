#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/Header.h"

using namespace std;

int count_file_lines(ifstream& out);
void outFileArray(ifstream& out, string path, Employee* emp, int count_emp);
void printArray(Employee* emp, int count_emp);
int BinarySearch(Employee* emp, int count_emp, int key);
int SequentialSearch(Employee* emp, int count_emp, int key);
Node* TreeSearch(Node* tree, string key, int&);

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

	// Бинарное дерево. 
	Node* tree = nullptr;
	Node* result = nullptr;
	int it_count = 0;
	path = "data/in_inordered.txt";

	// Создание бинарного дерева.
	createTree(out, path, tree, count_emp);
	
	// Вывод бинарного дерева.
	cout << endl << endl << " > Emoloyee (Tree): " << endl;
	printTree(tree);

	// Поиск в бинарном дереве.
	cout << endl << endl << " > Binary Tree Search";
	result = TreeSearch(tree, "Melloni Tea", it_count);
	cout << endl << "Searched Employee: ";
	if (result == nullptr)
		cout << "Unknown Employee.";
	else
		cout << result->emp.toString() << endl << "Count of iterrations: " << it_count << endl;
	deleteTree(tree);
	


	system("pause > nul");
	
}

Node* TreeSearch(Node* tree, string key, int& it_count) {
	// Поиск в бинарном дереве.
	// tree - указатель на вершину дерева.
	// key - искомый сотрудник (имя).
	// it_count - количество иттераций.
	if ((tree == nullptr) || (key == tree->emp.name)) {
		return tree;
	}
	if (key > tree->emp.name) {
		it_count = it_count + 1;
		tree = TreeSearch(tree->right, key, it_count);
	}
	else {
		it_count = it_count + 1;
		tree = TreeSearch(tree->left,  key, it_count);
	}
	return tree;
}

int BinarySearch(Employee* emp, int count_emp, int key) {
	// Бинарный поиск.
	// emp - массив объектов.
	// count_emp - количество сотрудников.
	// key - искомый номер сотрудника.
	cout << endl << endl << " > Binary Search: " << endl;
	int a = 0, b = count_emp - 1, c = 0;
	int it_count = 0;
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


