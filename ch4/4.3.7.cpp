#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;
/*
   use level order traversal
   and add null nodes to queue
   after a null node is poped 
   if there is a non-null node in the queue, the tree is not complete
*/

template <class T>
bool IsCompleteBinaryTree(BinTreeNode<T> *root) {
	queue<BinTreeNode<T>*> q;
	q.push(root);
	bool after_null = false;
	while(!q.empty()) {
		auto front = q.front();
		q.pop();
		if (!after_null && front == nullptr) {
			after_null = true;
		} else if (after_null && front != nullptr) {
			return false;
		}
		if (front) {
			q.push(front->leftChild);
			q.push(front->rightChild);
		}
	}
	return true;
}
int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << IsCompleteBinaryTree<int>(bt.getRoot()) << endl;
	bt.generate_test_tree_b();
	cout << IsCompleteBinaryTree<int>(bt.getRoot()) << endl;
	return 0;
}