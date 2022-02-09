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
* �������� �����.
* emp - ������ �������� ������ Employee.
* count_emp - ���������� ��������� � �������.
* key - ���� ������.
*/
int BinarySearch(Employee* emp, int count_emp, int key);

/*
* ���������������� �����.
* emp - ������ �������� ������ Employee.
* count_emp - ���������� ��������� � �������.
* key - ���� ������.
*/
int SequentialSearch(Employee* emp, int count_emp, int key);

/*
* ����� � �������� ������.
* tree - ��������� �� ������� ������.
* key - ������� ��������� (���).
* it_count - ���������� ���������.
*/
Node* BinTreeSearch(Node* tree, string key, int& it_count);