#pragma once
#include "Employee.h"

struct BinTree {
	Employee emp;
	BinTree* left;
	BinTree* right;
};

BinTree* addNode(BinTree* tree, Employee emp); 
void createTree(ifstream& out, string path, BinTree* tree, int count_emp);
void printTree(BinTree* tree);