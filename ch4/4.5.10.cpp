#include <iostream>
#include "binary_tree.hpp"
#include <queue>
#include <stack>
using namespace std;

template <class T>
vector<T> greaterThan(BinTreeNode<T>* root,T k) {
	if (!root) return vector<T>{};
	auto p = root;
	stack<decltype(p)> s;
	vector<T> result;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->rightChild;
		} else {
			auto top = s.top();
			s.pop();
			if (top->data >= k)
				result.push_back(top->data);
			else
				return result;
			p = top->leftChild;
		}
	}
	return result;
}
     
int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	auto ret = greaterThan(bt.getRoot(),2);
	for (auto item:ret) {
		cout << item << " ";
	}
	return 0;
}