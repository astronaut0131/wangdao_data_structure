#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
int findDoubleLinkedCount(BinTreeNode<T> *root) {
	queue<BinTreeNode<T>*> q;
	q.push(root);
	int cnt = 0;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		if (front->leftChild)
			q.push(front->leftChild);
		if (front->rightChild)
			q.push(front->rightChild);
		if (front->leftChild && front->rightChild) {
			cnt++;
		} 
	}
	return cnt;
}
int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << findDoubleLinkedCount<int>(bt.getRoot()) << endl;
	bt.generate_test_tree_b();
	cout << findDoubleLinkedCount<int>(bt.getRoot()) << endl;
	return 0;
}