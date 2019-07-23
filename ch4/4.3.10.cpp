#include "binary_tree.hpp"
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

template <class T>
T kthNodeData(BinTreeNode<T> *root,int k) {
	stack<BinTreeNode<T>*> s;
	s.push(root);
	int cnt = 0;
	while (!s.empty()) {
		cnt++;
		auto front = s.top();
		s.pop();
		if (cnt == k) return front->data;
		if (front->rightChild)
			s.push(front->rightChild);
		if (front->leftChild)
			s.push(front->leftChild);
	}
	// k is invalid
	cout << "invalid k" << endl;
	return T{};
}

int main() {
	auto bt = BinaryTree<int>();
	// pre order 1 2 4 5 7 3 6
	bt.generate_test_tree();
	auto vec = bt.getPreSequence();
	assert(kthNodeData(bt.getRoot(),3) == vec[3-1]);
	cout << kthNodeData(bt.getRoot(),3) << endl;
	// pre order 1 2 4 5 3 6
	bt.generate_test_tree_b();
	vec = bt.getPreSequence();
	assert(kthNodeData(bt.getRoot(),4) == vec[4-1]);
	cout << kthNodeData(bt.getRoot(),4) << endl;
	return 0;
}