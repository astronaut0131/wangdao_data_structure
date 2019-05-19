#include "LinkedList.hpp"
using NodeType = DoubleLNode<int>;

bool is_symmetry(DoubleLinkedList<int>& A) {
	auto p1 = A.get_head()->next;
	auto p2 = A.get_head()->prev;
	while (!(p1 == p2 || p1->prev == p2)) {
		if (p1->data != p2->data) return false;
		p1 = p1->next;
		p2 = p2->prev;
	}
	return true;
}

int main() {
	vector<int> v1 = {1,2,3,2,1};
	vector<int> v2 = {1,2,3,3,2,1};
	vector<int> v3 = {1,2,3,2};
	DoubleLinkedList<int> A(v1,true,true);
	DoubleLinkedList<int> B(v2,true,true);
	DoubleLinkedList<int> C(v3,true,true);
	cout << is_symmetry(A) << endl;
	cout << is_symmetry(B) << endl;
	cout << is_symmetry(C) << endl;
	return 0;
}