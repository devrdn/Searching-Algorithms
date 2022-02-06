#pragma once
#include "Employee.h"
struct EmployeeTree {
	Employee emp;
	EmployeeTree* left;
	EmployeeTree* right;
	EmployeeTree* addNode(EmployeeTree* tree, Employee emp);
};