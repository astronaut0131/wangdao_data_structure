#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
int getTreeWidth(BinTreeNode<T> *root) {
	if (!root) return 0;
	queue<decltype(root)> q;
	q.push(root);
	int size = q.size();
	int max_width = 1;
	while (!q.empty()) {
		for (int i = 0; i < size; i++) {
			auto front = q.front();
			q.pop();
			if (front->leftChild)
				q.push(front->leftChild);
			if (front->rightChild)
				q.push(front->rightChild);
		}
		size = q.size();
		max_width = size > max_width ? size : max_width;
	}
	return max_width;
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << getTreeWidth(bt.getRoot()) << endl;
	bt.generate_test_tree_b();
	cout << getTreeWidth(bt.getRoot()) << endl;
	bt.generate_test_tree_c();
	cout << getTreeWidth(bt.getRoot()) << endl;
	return 0;
}