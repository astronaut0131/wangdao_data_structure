#include <iostream>
#include "binary_tree.hpp"
#include <queue>
using namespace std;
template <class T>
int getLevel(BinTreeNode<T>* root,T x) {
	auto p = root;
	int level = 0;
	while (p) {
		level++;
		if (x == p->data) {
			return level; 
		} else if (x < p->data) {
			p = p->leftChild;
		} else {
			p = p->rightChild;
		}
	}
	return -1;
}
int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	cout << getLevel(bt.getRoot(),4) << endl;
	cout << getLevel(bt.getRoot(),3) << endl;
	return 0;
}