#include "include/Header.h"

using namespace std;

int count_file_lines(ifstream& out);
void outFileArray(ifstream& out, string path, Employee* emp, int count_emp);
void printArray(Employee* emp, int count_emp);


int main()
{

	/* Ключи поиска: числовой и строковый */
	const int number_key = 200; 
	const string string_key = "Melloni Tea"; 

	/* Пути к файлам со списком */
	const string inord_path = "data/unordered.txt"; // путь к файлу с неотсортированными данным.
	const string ord_path = "data/ordered.txt"; // уть к файлу с отсортированными данным.

	/* Инициализация переменных */
	int id = -1; // возвращаемый номер позиции.
	int it_count = 0; // количество иттераций для поиска в бинарном.
	char flag; // флаг, для выбора меню.
	ifstream out(inord_path); // объект класса ifstream  (входной файловый поток).
	int count_emp = count_file_lines(out) - 1; // количество записй в файле.

	/* Инициализируем массив который будет содержать отсортированные данные. */
	Employee* emp_ord = new Employee[count_emp];
	outFileArray(out, ord_path, emp_ord, count_emp);

	/* Инициализируем массив который будет содержать неотсортированные данные. */
	Employee* emp_inord = new Employee[count_emp];
	outFileArray(out, inord_path, emp_inord, count_emp);

	/* Инициализируем бинарное дерево, содержанее данные */
	Tree tree = nullptr;
	createTree(out, inord_path, tree, count_emp);


	/* Меню выбора алгоритма */
	do {
		system("cls");
		cout << "Select Method: " << endl << endl;
		cout << " 1. Sequential Search." << endl;
		cout << " 2. Binary Search." << endl;
		cout << " 3. Interpolation Search." << endl;
		cout << " 4. Fibonacci Search." << endl;
		cout << " 5. Binary Tree Search." << endl;
		cout << " 6. Exit." << endl;
		cout << "> ";
		flag = _getche();
		system("cls");

		// Вывод записей в упорядоченном виде.
		if (flag == '1') {
			cout << " > InOrdered List of Employee: " << endl;
			printArray(emp_inord, count_emp);
		}
		else if (flag == '2' || flag == '3' || flag == '4') {
			cout << " > Ordered List of Employee: " << endl;
			printArray(emp_ord, count_emp);
		}
		else if (flag == '5') {
			cout << endl << endl << " > List of Emoloyee (Tree): " << endl;
			printTree(tree);
		}

		switch (flag) {
			case '1':
			{
				/* Последовательный поиск в неупорядоченной таблице */
				id = SequentialSearch(emp_inord, count_emp, number_key);
				cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp_inord[id].toString());
				break;
			}
			case '2':
			{
				/* Бинарный поиск в упорядоченной таблице */
				id = BinarySearch(emp_ord, count_emp, number_key);
				cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp_ord[id].toString());
				break;
			}
			case '3':
			{
				/* Поиск методом интерполяции */
				id = InterpolationSearch(emp_ord, count_emp, number_key);
				cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp_ord[id].toString());
				break;
			}
			case '4':
			{
				id = FibonaccianSearch(emp_ord, number_key, count_emp);
				cout << "Searched Employee: " << ((id == -1) ? "Unknown Employee." : emp_ord[id].toString());
				break;
			}
			case '5':
			{
				/* Поиск в бинарном дереве */
				Tree result = nullptr; // Результат поиска.

				cout << endl << endl << " > Binary Tree Search: ";
				result = BinTreeSearch(tree, string_key, it_count);
				if (result == nullptr) // Проверка, если результат существует.
					cout << "Unknown Employee.";
				else
					cout << endl << "Searched Employee: " << result->emp.toString() << endl << "Count of iterrations: " << it_count << endl;
				break;
			}
			case '6':
			{
				break;
			}
			default:
			{
				cout << "Select correct option: 1-5";
				break;
			}
		}
		system("pause > nul");
	} while (flag != '6');

	/* Освобождение памяти */
	delete[] emp_ord;
	delete[] emp_inord;
	deleteTree(tree);

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

class ArinaLucshayaDevushka {
	int ArinaLove;
public:
	ArinaLucshayaDevushka() {
		ArinaLove = 1;
	}
	ArinaLucshayaDevushka(int ArinaLove) {
		this->ArinaLove = ArinaLove;
	}
};




