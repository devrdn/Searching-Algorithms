#include "../include/Header.h"

/*
* ����� � �������� ������.
* tree - ��������� �� ������� ������.
* key - ������� ��������� (���).
* it_count - ���������� ���������.
*/
Node* BinTreeSearch(Node* tree, string key, int& it_count) {

	/* ���������, ��� ���� ������ �� �������� ������ ����������, ���� ����� ��������� */
	if ((tree == nullptr) || (key == tree->emp.name)) {
		return tree;
	}

	/* ���� ���� �������� ������ ��� �������� ����, ���� ������ */
	if (key > tree->emp.name) {
		it_count = it_count + 1;
		tree = BinTreeSearch(tree->right, key, it_count);
	}

	/* ���� ���� �������� ������ ��� �������� ����, ���� ����� */
	else {
		it_count = it_count + 1;
		tree = BinTreeSearch(tree->left, key, it_count);
	}
	return tree;
}