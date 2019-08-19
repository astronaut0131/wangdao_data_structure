#include <iostream>
#include <vector>
using namespace std;
template <class T>
int search(vector<T>& v, const T target) {
	int i = 0;
	while (i < v.size() && v[i] != target) i++;
	if (i == v.size()) return -1;
	if (i != 0) {
		swap(v[i],v[i-1]);
		return i-1;
	}
	return i;
}

template <class T>
struct Node{
	T data;
	Node* next;
	Node(T d):data(d),next(nullptr) {}
};

template <class T>
Node<T>* search(const Node<T>* head, const T target) {
	auto p = head->next;
	decltype(p) prev = nullptr;
	while (p != nullptr && p->data != target) {
		prev = p;
		p = p->next;
	}
	if (p != nullptr && prev != nullptr) {
		swap(prev->data,p->data);
		return prev;
	}
	return p;
}

template <class T>
void print_linked_list(const Node<T>* head) {
	auto p = head->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
void delete_linked_list(Node<T>* head) {
	while (head != nullptr) {
		auto next = head->next;
		delete head;
		head = head->next;
	}
}

int main() {
	vector<int> v = {3,1,4,2};
	search(v,2);
	for (auto i:v) {
		cout << i << " ";
	}
	cout << endl;
	search(v,3);
	for (auto i:v) {
		cout << i << " ";
	}
	cout << endl;
	auto root = new Node<int>(-1);
	root->next = new Node<int>(3);
	root->next->next = new Node<int>(1);	
	root->next->next->next = new Node<int>(4);
	root->next->next->next->next = new Node<int>(2);
	search(root,2);
	print_linked_list(root);
	search(root,3);
	print_linked_list(root);
	delete_linked_list(root);
	return 0;
}