#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;
template <class T>
int get_height(BinTreeNode<T>* root) {
	queue<BinTreeNode<T>*> q;
	int height = 0;
	q.push(root);
	int size = q.size();
	while (!q.empty()) {
		for (int i = 0; i < size;i++) {
				auto front = q.front();
				q.pop();
				if (front->leftChild) {
					q.push(front->leftChild);
				}
				if (front->rightChild) {
					q.push(front->rightChild);
				}
		}
		height++;
		size = q.size();
	}
	return height;
}
int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	cout << get_height<int>(bt.getRoot()) << endl;
	return 0;
}