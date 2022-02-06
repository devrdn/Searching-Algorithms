#include "../include/binTree.h"
#include <fstream>
#include <sstream>
#include <string>

Node* addNode(Node* tree, Employee& data)
{

	/*
	* ���� ��������� ����� ����, �� ��������� ����.
	*/
	if (tree == nullptr) {
		Node* node = new Node();
		node->emp = data;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
	 
	/*
	* ���� ���������� �������� ������ ��� �������� ����..
	* ���������� ������������� ������ �����.
	*/
	if (data.name < tree->emp.name) {
		tree->left = addNode(tree->left, data);
	}

	/*
	* ���� ���������� �������� ������ ��� �������� ����..
	* ���������� ������������� ������ ������.
	*/
	if (data.name > tree->emp.name) {
		tree->right = addNode(tree->right, data);
	}

	return tree;
}

void createTree(ifstream& out, string path, Node*& tree, int count_emp)
{
	out.open(path, ios::in); // ��������� ���� ��� ������.
	string line;
	Employee temp;
	if (out.is_open()) { // ���������, ���� ���� ������.
		for (int i = 0; i < count_emp && getline(out, line); i++)
		{
			stringstream str(line); // �������������� ��������� �����.
			string t_name, t_date, t_salary; // ������ ��������� ���������.
			getline(str, t_name, ','); temp.id = stoi(t_name); // ��������� id.
			getline(str, temp.name, ','); // ��������� ���.
			getline(str, t_date, ','); temp.bdate = Date(t_date); // ��������� ���� ��������.
			getline(str, temp.department, ','); // ��������� �����������.
			getline(str, t_salary, ','); temp.salary = stod(t_salary);// ��������� ��������.
			tree = addNode(tree, temp); // ��������� � ������ ���� � �����������.
		}
	}
	else {
		cout << "File is not Open!" << endl;
		exit(0);
	}
	out.close(); // ��������� ����.
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
