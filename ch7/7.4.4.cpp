#include <iostream>
using namespace std;
template <class T>
struct Node{
	T data;
	Node* next;
	Node(T d):data(d),next(nullptr){};
};
template <class T>
void selection_sort(Node<T>* head) {
	auto p = head;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	p = head;
	for (int i = 0; i < len; i++) {
		auto min_it = p;
		auto it = p->next;
		while (it) {
			if (it->data < min_it->data) min_it = it;
			it = it->next;
		}
		swap(min_it->data,p->data);
		p = p->next;
	}
}

template <class T>
void print_list(Node<T>* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	auto root = new Node<int>(2);
	root->next = new Node<int>(1);
	root->next->next = new Node<int>(3);
	root->next->next->next = new Node<int>(4);
	root->next->next->next->next = new Node<int>(0);
	selection_sort(root);
	print_list(root);
	while (root) {
		auto next_root = root->next;
		delete root;
		root = next_root;
	}
	return 0;
}