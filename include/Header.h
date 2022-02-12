#pragma once
#include "Date.h"
#include "Employee.h"
#include "binTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

typedef Node* Tree;

/*
* Бинарный поиск.
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
*/
int BinarySearch(Employee* arr, int count, int key);

/*
* Последовательный поиск.
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
*/
int SequentialSearch(Employee* arr, int count, int key);

/*
* Поиск в бинарном дереве.
* tree - указатель на вершину дерева.
* key - искомый сотрудник (имя).
* it_count - количество иттераций.
*/
Node* BinTreeSearch(Node* tree, string key, int& it_count);

/*
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
* int номер индекса элемента.
*/
int InterpolationSearch(Employee* arr, int count, int key);

/*
* Поиск Фиббоначи.
* arr - массив объектов класса Employee.
* count - количество элементов в массиве.
* key - ключ поиска.
*/
int FibonaccianSearch(Employee* arr, int count, int key);