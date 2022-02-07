#include "../include/Employee.h"

Employee::Employee()
{
	this->id = 0;
	this->name = "John Doe";
	this->department = "No Department";
	this->salary = 0.0;
}

Employee::Employee(int id, string name, Date bdate, string department, float salary)
{
	this->id = id;
	this->name = name;
	this->bdate = bdate;
	this->department = department;
	this->salary = salary;
}

string Employee::toString()
{
	return  "Employee{ " + to_string(this->id) +
		", " + this->name +
		", " + this->bdate.toString() +
		", " + this->department +
		", " + to_string(this->salary) + " }";
}
