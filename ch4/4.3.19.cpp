#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
int getWPL(BinTreeNode<T> *root) {
	if (!root) return 0;
	queue<decltype(root)> q;
	q.push(root);
	int size = q.size();
	int level = 0;
	int WSL = 0;
	while (!q.empty()) {
		for (int i = 0; i < size; i++) {
			auto front = q.front();
			q.pop();
			if (front->leftChild) {
				q.push(front->leftChild);
			}
			if (front->rightChild){
				q.push(front->rightChild);
			}
			if (!front->leftChild && !front->rightChild) {
				WSL += level * front->weight;
			}
		}
		size = q.size();
		level++;
	}
	return WSL;
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	/*
	 *			1
	 *		   / \
	 *		  2   3
	 *		 / \   \
	 *		4   5   6
	 *		   /
	 *		  7
	 * 4*2 + 7*3 + 6*2 = 41
	 */
	cout << getWPL(bt.getRoot()) << endl;
	bt.generate_test_tree_b();

	/*
	 *			 1
	 *		   /   \
	 *		  2     3
	 *		 / \   /
	 *		4   5 6  
	 * 4*2 + 5*2 + 6*2 = 30
	 */
	cout << getWPL(bt.getRoot()) << endl;
	bt.generate_test_tree_c();

	/*
	 *			 1
	 *		   /   \
	 *		  2     3
	 *		 / \   / 
	 *		4   5 6  
	 *		 	 / \
	 *			2   1
	 *		   /     \
	 *        3       2
	 *	4*2+5*2+4*3+4*2 = 38
	 */
	cout << getWPL(bt.getRoot()) << endl;
	return 0;
}