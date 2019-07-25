#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct LinkedListNode{
	LinkedListNode(T d):data(d),next(nullptr){}
	T data;
	LinkedListNode<T>* next;
};

template <class T>
class LinkedList{
public:
	LinkedList():head(nullptr){}
	LinkedList(LinkedListNode<T>* h):head(h){}
	~LinkedList() {
		auto p = head;
		while (p) {
			auto next_p = p->next;
			delete p;
			p = next_p;
		}
	}
	void setHead(LinkedListNode<T>* h) { head = h; }
	friend ostream& operator << (ostream& out, LinkedList<T>& linked_list);
	LinkedListNode<T>* head;
};

template <class T>
ostream& operator << (ostream& out, LinkedList<T>* linked_list) {
	auto p = linked_list->head;
	while (p) {
		// magic...
		out << p->data->data << " ";
		p = p->next;
	}
	return out;
}

template <class T>
LinkedList<BinTreeNode<T>*>* linkLeaves(BinTreeNode<T>* root){
	if (!root) return nullptr;
	queue<decltype(root)> q;
	q.push(root);
	auto L = new LinkedList<BinTreeNode<T>*>;
	LinkedListNode<BinTreeNode<T>*>* p = nullptr;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		if (front->leftChild)
			q.push(front->leftChild);
		if (front->rightChild)
			q.push(front->rightChild);
		if (!front->leftChild && !front->rightChild) {
			if (L->head == nullptr) {
				p = new LinkedListNode<BinTreeNode<T>*>(front);
				L->head = p;
			} else {
				auto x = new LinkedListNode<BinTreeNode<T>*>(front);
				p->next = x;
				p = p->next;
			}
		}
	}
	return L;
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree();
	auto L = linkLeaves(bt.getRoot());
	cout << L << endl;
	delete L;
	bt.generate_test_tree_b();
	L = linkLeaves(bt.getRoot());
	cout << L << endl;
	delete L;
	bt.generate_test_tree_c();
	L = linkLeaves(bt.getRoot());
	cout << L << endl;
	delete L;
	return 0;
}