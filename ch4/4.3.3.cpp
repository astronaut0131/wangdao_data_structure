#include "binary_tree.hpp"
#include <iostream>
#include <stack>
using namespace std;
template <class T>
struct stkNode {
	BinTreeNode<T> *ptr;
	enum tag_type{L,R};
	tag_type tag;
	stkNode(BinTreeNode<T>* N = nullptr):ptr(N),tag(L) {} 
};

template <class T>
void post_order_traversal(BinTreeNode<T>* root) {
	stack<stkNode<T>> s;
	stkNode<T> w;
	BinTreeNode<T> *p = root;
	do {
		while (p != nullptr) {
			w.ptr = p;
			w.tag = stkNode<T>::L;
			s.push(w);
			p = p->leftChild;
		}
		while (!s.empty()) {
			w = s.top();
			p = w.ptr;
			s.pop();
			if (w.tag == stkNode<T>::L) {
				w.tag = stkNode<T>::R;
				s.push(w);
				p = p->rightChild;
				break;
			} else {
				cout << w.ptr->data << " "; // visit it
			}
		}
	} while(!s.empty());
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	post_order_traversal<int>(bt.getRoot());
	return 0;
}