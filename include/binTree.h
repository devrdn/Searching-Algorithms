#pragma once
#include "Employee.h"

struct Node {
	Employee emp;
	Node* left;
	Node* right;
};

/*
* ƒобавление узла в дерево.
* tree - указать на вершину дерева.
* emp - данные, которые будет содержать узел.
*/
Node* addNode(Node* tree, Employee& emp); 


/*
* ‘ормирование бинарного дерева (записи достаютс€ из файлов).
* out - входной файловый поток.
* tree - ссылка на указатель вершины дерева.
* count_emp - количество записей.
*/
void createTree(ifstream& out, string path, Node*& tree, int count_emp);

/*
* ¬ывод бинарного дерева.
* tree - указатель вершины дерева.
*/
void printTree(Node* tree);

/*
* ”далание бинарного дерева.
* tree - указатель вершины дерева.
*/
void deleteTree(Node* tree);