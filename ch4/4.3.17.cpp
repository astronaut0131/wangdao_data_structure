#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
bool isSimilarTree(BinTreeNode<T> *root1,BinTreeNode<T> *root2) {
	return (root1 == nullptr && root2 == nullptr) || 
	(root1 && root2 && isSimilarTree(root1->leftChild,root2->leftChild) && isSimilarTree(root1->rightChild,root2->rightChild));
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << isSimilarTree(bt.getRoot(),bt.getRoot()) << endl;;
	auto bt2 = BinaryTree<int>();
	bt2.generate_test_tree_b();
	cout << isSimilarTree(bt.getRoot(),bt2.getRoot()) << endl;
	return 0;
}