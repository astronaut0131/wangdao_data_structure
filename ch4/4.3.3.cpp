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
void post_order_traversal_b(BinTreeNode<T>* root) {
	stack<BinTreeNode<T>*> s;
	auto p = root;
	/* use last to denote whether we are returning from a left subtree or not */
	/* according to left right node sequence of post order traversal */
	/* when we return from a left subtree, we must visit the node's right subtree */
	/* when we return from a right subtree, we must visit this node and backtrace the stack to get its parent */
	BinTreeNode<T>* last = nullptr;
	while (p || !s.empty()) {
		/* p == nullptr means we are backtracing */
		if (p) {
			/* go to the leftmost child and record path in stack */
			s.push(p);
			p = p->leftChild;
		} else {
			p = s.top();
			/* don't pop top here */
			/* if we have done with top's right subtree, we pop top and visit it */
			/* top should be kept in stack otherwise, it should be visited after its right subtree */
			if (p->rightChild && p->rightChild != last) {
				/* node has right subtree and haven't visit it yet */
				/* turn to right subtree */
				p = p->rightChild;
			} else {
				/* node don't have right subtree or have already visited it */
				/* pop it and visit */
				s.pop();
				cout << p->data << " ";
				/* record the last node visited */
				last = p;
				/* turn p to nullptr, next node is the parent of top and must be fetched from the stack */
				p = nullptr;
			}
		}
	}
}
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

template <class T>
void pre_order_traversal(BinTreeNode<T>* root) {
	stack<BinTreeNode<T>*> s;
	auto p = root;
	while (p || !s.empty()) {
		if (p) {
			// visit it
			cout << p->data << " ";
			/* node left right */
			/* right must be push to stack before left */
			/* so that left comes out first */
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
}

template <class T>
void in_order_traversal(BinTreeNode<T>* root) {
	stack<BinTreeNode<T>*> s;
	auto p = root;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->leftChild;
		} else {
			p = s.top();
			s.pop();
			// visit it
			cout << p->data << " ";
			p = p->rightChild;
		}
	}
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	post_order_traversal<int>(bt.getRoot());
	cout << endl;
	post_order_traversal_b<int>(bt.getRoot());
	cout << endl;
	pre_order_traversal<int>(bt.getRoot());
	cout << endl;
	in_order_traversal<int>(bt.getRoot());
	return 0;
}