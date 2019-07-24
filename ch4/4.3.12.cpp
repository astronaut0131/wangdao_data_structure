#include "binary_tree.hpp"
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

vector<BinTreeNode<int>*> ancestors;

template <class T>
void findAncestorRecurs(BinTreeNode<T> *root,T x, vector<BinTreeNode<T>*>& path) {
	if (!root) return;
	if (root->data == x) {
		ancestors = path;
		return;
	}
	path.push_back(root);
	if (root->leftChild) {
		findAncestorRecurs(root->leftChild,x,path);
	}
	if (root->rightChild) {
		findAncestorRecurs(root->rightChild,x,path);
	}
	path.pop_back();
}

template <class T>
vector<BinTreeNode<T>*> findAncestor(BinTreeNode<T>* root, T x) {
	auto p = root;
	decltype(p) last = nullptr;
	stack<decltype(p)> s;
	vector<decltype(p)> v;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->leftChild;
		}
		else {
			p = s.top();
			if (p->rightChild && p->rightChild != last) {
				// visit p's right subtree
				p = p->rightChild;
			} else {
				s.pop();
				// visit p
				if (p->data == x) {
					while (!s.empty()) {
						v.push_back(s.top());
						s.pop();
					}
					return v;
				}
				last = p;
				p = nullptr;
			}
		}
	}
	return v;
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	vector<BinTreeNode<int>*> path;
	findAncestorRecurs<int>(bt.getRoot(),7,path);
	for(auto p:ancestors) {
		cout << p->data << " ";
	}
	cout << endl;
	auto vec = findAncestor<int>(bt.getRoot(),7);
	for (auto p:vec) {
		cout << p->data << " ";
	}
	return 0;
}