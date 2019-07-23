#include "binary_tree.hpp"
#include <iostream>
using namespace std;

template <class T>
void revertTree(BinTreeNode<T> *root) {
	if (!root) return;
	swap(root->leftChild,root->rightChild);
	revertTree(root->leftChild);
	revertTree(root->rightChild);
}
void visit(BinTreeNode<int> *p) {
	cout << p->data << " ";
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	revertTree(bt.getRoot());
	bt.levelTraversal(visit);
	cout << endl;
	bt.generate_test_tree_b();
	revertTree(bt.getRoot());
	bt.levelTraversal(visit);
	return 0;
}