#include "binary_tree.hpp"
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

vector<BinTreeNode<int>*> ancestors;

template <class T>
void findAncestor(BinTreeNode<T> *root,T x, vector<BinTreeNode<T>*>& path) {
	if (!root) return;
	if (root->data == x) {
		ancestors = path;
		return;
	}
	path.push_back(root);
	if (root->leftChild) {
		findAncestor(root->leftChild,x,path);
	}
	if (root->rightChild) {
		findAncestor(root->rightChild,x,path);
	}
	path.pop_back();
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	vector<BinTreeNode<int>*> path;
	findAncestor<int>(bt.getRoot(),7,path);
	for(auto p:ancestors) {
		cout << p->data << endl;
	}
	return 0;
}