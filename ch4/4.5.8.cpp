#include <iostream>
#include "binary_tree.hpp"
#include <queue>
#include <map>
using namespace std;
template <class T>
map<BinTreeNode<T>*,int> cache;

template <class T>
int getHeight(BinTreeNode<T>* root) {
	if (!root) return 0;
	auto it = cache<T>.find(root);
	if (it != cache<T>.end()) return it->second;
	int height = max(getHeight(root->leftChild)+1,getHeight(root->rightChild)+1);
	cache<T>.insert(make_pair(root,height));
	return height;
}

template <class T>
bool isAVLTree(BinTreeNode<T>* root) {
	if (!root) return true;
	return abs(getHeight<T>(root->leftChild) - getHeight<T>(root->rightChild)) <= 1 && isAVLTree(root->leftChild) && isAVLTree(root->rightChild);
}
int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	cout << isAVLTree(bt.getRoot()) << endl;
	cache<int>.clear();
	bt.generate_test_AVL();
	cout << isAVLTree(bt.getRoot()) << endl;
	return 0;
}