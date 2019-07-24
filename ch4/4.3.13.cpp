#include "binary_tree.hpp"
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

template <class T>
BinTreeNode<T> *findCommonAncestor(BinTreeNode<T> *root, BinTreeNode<T>* a, BinTreeNode<T>* b) {
	// record whether we find p first or not
	auto p = root;
	decltype(p) last = nullptr;
	stack<decltype(p)> s;
	vector<decltype(p)> known_ancestors;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->leftChild;
		} else {
			p = s.top();
			if (p->rightChild && p->rightChild != last) {
				p = p->rightChild;
			} else {
				s.pop();
				if (p == a || p == b) {
					if (known_ancestors.empty()) {
						known_ancestors.push_back(p);
						while (!s.empty()) {
							known_ancestors.push_back(s.top());
							s.pop();
						}
						for (int i = known_ancestors.size()-1; i > 0; i--) {
							s.push(known_ancestors[i]);
						}
					} else {
						while (!s.empty()) {
							auto it = std::find(known_ancestors.begin(),known_ancestors.end(),s.top());
							if (it != known_ancestors.end()) return *it;
							s.pop();
						}
						return nullptr;
					}
				}
				last = p;
				p = nullptr;
			}
		}
	}
	return nullptr;
}

/*
 *			1
 *		   / \
 *		  2   3
 *		 / \   \
 *		4   5   6
 *		   /
 *		  7
 */

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	// p = 4, q = 7
	auto p = bt.getRoot()->leftChild->leftChild;
	auto q = bt.getRoot()->leftChild->rightChild->leftChild;
	auto LCA = findCommonAncestor<int>(bt.getRoot(),p,q);
	cout << LCA->data << endl;
	// p = 6, q = 7
	p = bt.getRoot()->rightChild->rightChild;
	LCA = findCommonAncestor<int>(bt.getRoot(),p,q);
	cout << LCA->data << endl;
	return 0;
}