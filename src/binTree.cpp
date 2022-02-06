#include "../include/binTree.h"

EmployeeTree* EmployeeTree::addNode(EmployeeTree* tree, Employee data)
{
	if (tree == nullptr) {
		EmployeeTree* temp = new EmployeeTree();
		temp->emp = data;
		temp->left = nullptr;
		temp->right = nullptr;
		return temp;
	}
	 
	if (data.name < tree->emp.name) {
		tree->left = addNode(tree->left, data);
	}

	if (data.name > tree->emp.name) {
		tree->right = addNode(tree->right, data);
	}

	return tree;
}
