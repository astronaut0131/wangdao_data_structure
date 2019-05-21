#include "LinkedList.hpp"
using NodeType = DoubleLNode<int>;

bool is_symmetry(LinkedList<DoubleLNode,int>& A) {
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
	LinkedList<DoubleLNode,int> A(true,true);
	A.init(v1);
	LinkedList<DoubleLNode,int> B(true,true);
	B.init(v2);
	LinkedList<DoubleLNode,int> C(true,true);
	C.init(v3);
	cout << is_symmetry(A) << endl;
	cout << is_symmetry(B) << endl;
	cout << is_symmetry(C) << endl;
	return 0;
}