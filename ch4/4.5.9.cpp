#include <iostream>
#include "binary_tree.hpp"
#include <queue>
using namespace std;

template <class T>
pair<T,T> getMinMax(BinTreeNode<T>* root) {
	T min,max;
	auto p = root;
	while (p->leftChild) {
		p = p->leftChild;
	}
	min = p->data;
	p = root;
	while (p->rightChild) {
		p = p->rightChild;
	}
	max = p->data;
	return make_pair(min,max);
}
int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	auto pair = getMinMax(bt.getRoot());
	cout << pair.first << " " << pair.second << endl;
	return 0;
}