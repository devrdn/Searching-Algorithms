#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
class Employee
{
public:
	int id; // Номер сотрудника.
	string name; // ФИО сотрудника.
	Date bdate; // День рождение сотрудника.
	string department; // Отдел сотрудника.
	double salary; // Зарплата сотрудника
	Employee();
	Employee(int id, string name, Date bdate, string department, float salary);
	string toString();
};
