#pragma once
#include "Employee.h"

struct Node {
	Employee emp;
	Node* left;
	Node* right;
};

/*
* ���������� ���� � ������.
* tree - ������� �� ������� ������.
* emp - ������, ������� ����� ��������� ����.
*/
Node* addNode(Node* tree, Employee& emp); 


/*
* ������������ ��������� ������ (������ ��������� �� ������).
* out - ������� �������� �����.
* tree - ������ �� ��������� ������� ������.
* count_emp - ���������� �������.
*/
void createTree(ifstream& out, string path, Node*& tree, int count_emp);

/*
* ����� ��������� ������.
* tree - ��������� ������� ������.
*/
void printTree(Node* tree);

/*
* �������� ��������� ������.
* tree - ��������� ������� ������.
*/
void deleteTree(Node* tree);