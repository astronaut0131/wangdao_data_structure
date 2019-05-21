#include "LinkedList.hpp"
using NodeType = LNode<int>;

void connect_list(LinkedList<LNode,int>& A, LinkedList<LNode,int>& B) {
	auto p1 = A.get_head();
	auto p2 = B.get_head();
	auto A_tail = p1;
	while (A_tail->next != p1) {
		A_tail = A_tail->next;
	}
	auto B_tail = p2;
	while (B_tail->next != p2) {
		B_tail = B_tail->next;
	}
	A_tail->next = p2->next;
	B_tail->next = p1;
	B.set_head(nullptr);
}

int main() {
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {6,7,8,9};
	LinkedList<LNode,int> A(true,true);
	A.init(v1);
	LinkedList<LNode,int> B(true,true);
	B.init(v2);
	connect_list(A,B);
	cout << A << endl;
	return 0;
}