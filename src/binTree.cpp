#include "../include/binTree.h"
#include <fstream>
#include <sstream>
#include <string>

BinTree* addNode(BinTree* tree, Employee data)
{
	if (tree == nullptr) {
		BinTree* node = new BinTree();
		node->emp = data;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
	 
	if (data.name < tree->emp.name) {
		tree->left = addNode(tree->left, data);
	}

	if (data.name > tree->emp.name) {
		tree->right = addNode(tree->right, data);
	}

	return tree;
}

void createTree(ifstream& out, string path, BinTree* tree, int count_emp)
{
	out.open(path, ios::in);
	string line;
	Employee temp;
	if (out.is_open()) { // ѕровер€ем, если файл открыт.
		for (int i = 0; i < count_emp && getline(out, line); i++)
		{
			stringstream str(line); // инициализируем строковый поток.
			string t_name, t_date, t_salary; // вводим временные перменные.
			getline(str, t_name, ','); temp.id = stoi(t_name); // считываем id.
			getline(str, temp.name, ','); // считываем им€.
			getline(str, t_date, ',');  temp.bdate = Date(t_date); // считываем дату рождени€.
			getline(str, temp.department, ','); // считываем департамент.
			getline(str, t_salary, ','); temp.salary = stod(t_salary);// считываем зарплату.
			addNode(tree, temp); // добавл€ем в дерево узел с информацией.
		}
	}
	out.close(); // «акрываем файл.
}

void printTree(BinTree* tree)
{
	if (tree == nullptr) {
		cout << "Tree is Empty";
	}
	printTree(tree->left);
	cout << tree->emp.toString();
	printTree(tree->right);
}
