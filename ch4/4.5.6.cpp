#include <iostream>
#include "binary_tree.hpp"
#include <queue>
using namespace std;
template <class T>
bool isBSTRecurs(BinTreeNode<T>* root) {
	if (!root) return true;
	bool res = true;
	if (root->leftChild)
		res &= root->leftChild->data < root->data;
	if (root->rightChild)
		res &= root->rightChild->data > root->data;
	return res && isBSTRecurs(root->leftChild) && isBSTRecurs(root->rightChild);
}

template <class T>
bool isBST(BinTreeNode<T>* root) {
	if (!root) return true;
	stack<decltype(root)> s;
	auto p = root;
	T last;
	bool has_last = false;
	while (p || !s.empty()) {
		if (p) {
			while (p) {
				s.push(p);
				p = p->leftChild;
			}
				
		} else {
			auto top = s.top();
			s.pop();
			if (!has_last) {
				has_last = true;
			}
			else if (last >= top->data) return false;
			last = top->data;
			p = top->rightChild;
		}
	}
	return true;
}
int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	cout << isBSTRecurs(bt.getRoot()) << endl;
	cout << isBST(bt.getRoot()) << endl;
	bt.generate_test_tree();
	cout << isBSTRecurs(bt.getRoot()) << endl;
	cout << isBST(bt.getRoot()) << endl;
	return 0;
}