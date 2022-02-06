#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
class Employee
{
public:
	int id; // ����� ����������.
	string name; // ��� ����������.
	Date bdate; // ���� �������� ����������.
	string department; // ����� ����������.
	double salary; // �������� ����������
	Employee();
	Employee(int id, string name, Date bdate, string department, float salary);
	string toString();
};
