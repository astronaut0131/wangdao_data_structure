#include "binary_tree.hpp"
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

template <class T>
T kthNodeData(BinTreeNode<T> *root,int k) {
	stack<BinTreeNode<T>*> s;
	auto p = root;
	int i = 0;
	while (p || !s.empty()) {
		if (p) {
			// visit
			i++;
			if (k==i) return p->data;
			if (p->rightChild)
				s.push(p->rightChild);
			if (p->leftChild)
				s.push(p->leftChild);
			p = nullptr;
		} else {
			p = s.top();
			s.pop();
		}
	}
	// k is invalid
	cout << "invalid k" << endl;
	return T{};
}

int result;
template <class T>
void kthNodeDataRecurs(BinTreeNode<T> *root, int k, int& cnt) {
	if (!root) return;
	cnt++;
	if (cnt == k)
		result = root->data;
	kthNodeDataRecurs(root->leftChild,k,cnt);
	kthNodeDataRecurs(root->rightChild,k,cnt);
}

int main() {
	auto bt = BinaryTree<int>();
	// pre order 1 2 4 5 7 3 6
	bt.generate_test_tree();
	auto vec = bt.getPreSequence();
	assert(kthNodeData(bt.getRoot(),3) == vec[3-1]);
	cout << kthNodeData(bt.getRoot(),3) << endl;
	int cnt = 0;
	kthNodeDataRecurs(bt.getRoot(),3,cnt);
	cout << result << endl;
	// pre order 1 2 4 5 3 6
	bt.generate_test_tree_b();
	vec = bt.getPreSequence();
	assert(kthNodeData(bt.getRoot(),4) == vec[4-1]);
	cout << kthNodeData(bt.getRoot(),4) << endl;
	cnt = 0;
	kthNodeDataRecurs(bt.getRoot(),4,cnt);
	cout << result << endl;
	return 0;
}