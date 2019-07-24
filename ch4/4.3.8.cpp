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

template <class T>
int findDoubleLinkedCountRecurs(BinTreeNode<T>* root) {
	if (!root) return 0;
	if (root->leftChild && root->rightChild)
		return findDoubleLinkedCountRecurs(root->leftChild) + findDoubleLinkedCountRecurs(root->rightChild)+1;
	else
		return findDoubleLinkedCountRecurs(root->leftChild) + findDoubleLinkedCountRecurs(root->rightChild);
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << findDoubleLinkedCount<int>(bt.getRoot()) << endl;
	cout << findDoubleLinkedCountRecurs<int>(bt.getRoot()) << endl;

	bt.generate_test_tree_b();
	cout << findDoubleLinkedCount<int>(bt.getRoot()) << endl;
	cout << findDoubleLinkedCountRecurs<int>(bt.getRoot()) << endl;
	
	return 0;
}