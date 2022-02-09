#include "../include/Header.h"

/*
* Поиск в бинарном дереве.
* tree - указатель на вершину дерева.
* key - искомый сотрудник (имя).
* it_count - количество иттераций.
*/
Node* BinTreeSearch(Node* tree, string key, int& it_count) {

	/* Проверяем, что узел дерева не является пустым указателем, либо нашим значением */
	if ((tree == nullptr) || (key == tree->emp.name)) {
		return tree;
	}

	/* Если наше значение больше чем значение узла, идем вправо */
	if (key > tree->emp.name) {
		it_count = it_count + 1;
		tree = BinTreeSearch(tree->right, key, it_count);
	}

	/* Если наше значение меньше чем значение узла, идем влево */
	else {
		it_count = it_count + 1;
		tree = BinTreeSearch(tree->left, key, it_count);
	}
	return tree;
}