#include "binary_tree.hpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
void reverse_level_order_traverse(BinTreeNode<T>* root) {
	queue<BinTreeNode<T>*> q;
	stack<BinTreeNode<T>*> s;
	q.push(root);
	while (!q.empty()) {
		auto front = q.front();
		s.push(front);
		q.pop();
		if (front->leftChild) {
			q.push(front->leftChild);
		}
		if (front->rightChild) {
			q.push(front->rightChild);
		}
	}
	while (!s.empty()) {
		auto top = s.top();
		s.pop();
		cout << top->data << " "; // visit it
	}
}
int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	reverse_level_order_traverse<int>(bt.getRoot());
}