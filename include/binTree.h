#pragma once
#include "Employee.h"

struct Node {
	Employee emp;
	Node* left;
	Node* right;
};

/*
* Добавление узла в дерево.
* tree - указать на вершину дерева.
* emp - данные, которые будет содержать узел.
*/
Node* addNode(Node* tree, Employee& emp); 


/*
* Формирование бинарного дерева (записи достаютс¤ из файлов).
* out - входной файловый поток.
* tree - ссылка на указатель вершины дерева.
* count_emp - количество записей.
*/
void createTree(ifstream& out, string path, Node*& tree, int count_emp);

/*
* Вывод бинарного дерева.
* tree - указатель вершины дерева.
*/
void printTree(Node* tree);

/*
* Удалание бинарного дерева.
* tree - указатель вершины дерева.
*/
void deleteTree(Node* tree);