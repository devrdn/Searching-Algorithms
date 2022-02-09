#include "include/Header.h"

using namespace std;

int count_file_lines(ifstream& out);
void outFileArray(ifstream& out, string path, Employee* emp, int count_emp);
void printArray(Employee* emp, int count_emp);


int main()
{

	/* Инициализация переменных */
	const int number_key = 200; // численный ключ.
	const string string_key = "Melloni Tea"; // строковый ключ.
	int id = -1; // возвращаемый номер позиции.
	char flag; // флаг, для выбора меню.
	const string inord_path = "data/inordered.txt"; // путь к неотсортированным данным.
	const string ord_path = "data/ordered.txt"; // пусть к сортированным данным.
	ifstream out(inord_path); // объект класса ifstream  (входной файловый поток).
	int count_emp = count_file_lines(out) - 1; // количество записй в файле.
	Employee* emp = new Employee[count_emp]; // инициализируется динамический массив объектов класса Employee.

	/* Меню выбора алгоритма */
	do {
		system("cls");
		cout << "Methods: " << endl << endl;
		cout << " 1. Sequential Search." << endl;
		cout << " 2. Binary Search." << endl;
		cout << " 3. Binary Tree Search." << endl;
		cout << " 4. Exit." << endl;
		cout << "> ";
		flag = getchar();
		if (emp != nullptr) {
			delete[] emp;
			emp = new Employee[count_emp];
		}
		system("cls");
		switch (flag) {
			case '1':
			{
				/* Последовательный поиск */
				cout << " > InOrdered List of Employee: " << endl;
				outFileArray(out, inord_path, emp, count_emp);
				printArray(emp, count_emp);
				id = SequentialSearch(emp, count_emp, number_key);
				cout <<  "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp[id].toString());
				break;
			}
			case '2':
			{
				/* Бинарный поиск */
				cout << " > Ordered List of Employee: " << endl;
				outFileArray(out, ord_path, emp, count_emp);
				printArray(emp, count_emp);
				id = BinarySearch(emp, count_emp, number_key);
				cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp[id].toString());
				break;
			}
			case '3':
			{
				// Инициализируем бинарное дерево (ключем является имя человека).
				Node* tree = nullptr; // Дерево.
				Node* result = nullptr; // Результат поиска.
				int it_count = 0; // Количество иттераций.
				createTree(out, inord_path, tree, count_emp); 
				cout << endl << endl << " > List of Emoloyee (Tree): " << endl;
				printTree(tree);
				cout << endl << endl << " > Binary Tree Search: ";
				result = BinTreeSearch(tree, string_key, it_count);
				if (result == nullptr) // Проверка, если результат существует.
					cout << "Unknown Employee.";
				else
					cout << endl << "Searched Employee: " << result->emp.toString() << endl << "Count of iterrations: " << it_count << endl;
				deleteTree(tree);
				break;
			}
			case '4':
				exit(0);
				break;
		}
		system("pause > null");
	} while (true);

	system("pause > nul");
	
}

/*  Вывод массива объектов Employee. 
* emp - массив объектов класса Employee.
* count_emp - количество элементов в массиве.
*/
void printArray(Employee* emp, int count_emp) {
	for (int i = 0; i < count_emp; i++) {
		cout << emp[i].toString() << endl;
	}

}

/*
* Подсчёт количества строк в файле.
* out - входной файловый поток.
*/
int count_file_lines(ifstream& out) {
	
	string str;
	int j = 0;
	while (out) {
		getline(out, str);
		j++;
	}
	out.close();
	return j;
}

/*
* Вывод данных из файла в объект.
* out - входной файловый поток.
* path - путь к файлу.
* emp - массив объектов класса Employee.
* count_emp - количество строк (записей) в файле.
*/
void outFileArray(ifstream& out, string path, Employee* emp, int count_emp) {
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


