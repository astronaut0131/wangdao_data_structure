#include "LinkedList.hpp"
using NodeType = LNode<int>;

bool is_subsequence(LinkedList<LNode,int>& A, LinkedList<LNode,int>& B) {
	auto p1 = A.get_head()->next;
	auto p2 = B.get_head()->next;
	while (p1 && p2) {
		auto pos = p2;
		while (p1 && p2 && p1->data == p2->data) {
			p1 = p1->next;
			p2 = p2->next;
		}
		if (!p1) {
			return true;
		}
		if (!p2) {
			return false;
		}
		p1 = A.get_head()->next;
		p2 = pos->next;
	}
	return false;
}

int main() {
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {0,2,4,5,6,1,2,3,4,5,1,2,3,4,8,9,11,12};
	LinkedList<LNode,int> A;
	A.init(v1);
	LinkedList<LNode,int> B;
	B.init(v2);
	cout << is_subsequence(A,B) << endl;
	v1 = {1,2,3,4};
	v2 = {1,2,3,1,2,3,5,1,1,2,3,5,4};
	LinkedList<LNode,int> C;
	C.init(v1);
	LinkedList<LNode,int> D;
	D.init(v2);
	cout << is_subsequence(C,D) << endl;
	return 0;
}