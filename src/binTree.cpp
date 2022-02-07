#include <fstream>
#include <sstream>
#include <string>
#include "../include/binTree.h"

Node* addNode(Node* tree, Employee& data)
{

	/*
	* Если указатель равен нулю, то добавляем узел.
	*/
	if (tree == nullptr) {
		Node* node = new Node();
		node->emp = data;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
	 
	/*
	* Если переданное значение меньше чем значение узла..
	* продолжаем рассматривать дерево влево.
	*/
	if (data.name < tree->emp.name) {
		tree->left = addNode(tree->left, data);
	}

	/*
	* Если переданное значение меньше чем значение узла..
	* продолжаем рассматривать дерево вправо.
	*/
	if (data.name > tree->emp.name) {
		tree->right = addNode(tree->right, data);
	}

	return tree;
}

void createTree(ifstream& out, string path, Node*& tree, int count_emp)
{
	out.open(path, ios::in); // Открываем файл для чтения.
	string line;
	Employee temp;
	if (out.is_open()) { // Проверяем, если файл открыт.
		for (int i = 0; i < count_emp && getline(out, line); i++)
		{
			stringstream str(line); // инициализируем строковый поток.
			string t_name, t_date, t_salary; // вводим временные перменные.
			getline(str, t_name, ','); temp.id = stoi(t_name); // считываем id.
			getline(str, temp.name, ','); // считываем имя.
			getline(str, t_date, ','); temp.bdate = Date(t_date); // считываем дату рождения.
			getline(str, temp.department, ','); // считываем департамент.
			getline(str, t_salary, ','); temp.salary = stod(t_salary);// считываем зарплату.
			tree = addNode(tree, temp); // добавляем в дерево узел с информацией.
		}
	}
	else {
		cout << "File is not Open!" << endl;
		exit(0);
	}
	out.close(); // Закрываем файл.
}

void printTree(Node* tree)
{
	if (tree == nullptr) {
		return;
	}
	printTree(tree->left);
	cout << tree->emp.toString() << endl;
	printTree(tree->right);
}

void deleteTree(Node* tree)
{
	if (tree->left) deleteTree(tree->left);
	if (tree->right) deleteTree(tree->right);
	delete tree;
	return;
}
