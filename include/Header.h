#pragma once
#include "Date.h"
#include "Employee.h"
#include "binTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
* Бинарный поиск.
* emp - массив объектов класса Employee.
* count_emp - количество элементов в массиве.
* key - ключ поиска.
*/
int BinarySearch(Employee* emp, int count_emp, int key);

/*
* Последовательный поиск.
* emp - массив объектов класса Employee.
* count_emp - количество элементов в массиве.
* key - ключ поиска.
*/
int SequentialSearch(Employee* emp, int count_emp, int key);

/*
* Поиск в бинарном дереве.
* tree - указатель на вершину дерева.
* key - искомый сотрудник (имя).
* it_count - количество иттераций.
*/
Node* BinTreeSearch(Node* tree, string key, int& it_count);