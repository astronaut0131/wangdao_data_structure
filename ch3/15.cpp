#include "LinkedList.hpp"
using NodeType = LNode<int>;

void find_intersection(LinkedList<LNode,int>& A, LinkedList<LNode,int>& B) {
	auto p1 = A.get_head()->next;
	auto p2 = B.get_head()->next;
	auto prev = A.get_head();
	while (p1 && p2) {
		if (p1->data == p2->data) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;	
		} else if (p1->data < p2->data) {
			auto next_p1 = p1->next;
			prev->next = p1->next;
			delete p1;
			p1 = next_p1;
		} else {
			p2 = p2->next;
		}
	}
	prev->next = nullptr;
}

int main() {
	vector<int> v1 = {1,3,5,6,7,9,10};
	vector<int> v2 = {0,2,4,5,6,8,9,11,12};
	LinkedList<LNode,int> A;
	A.init(v1);
	LinkedList<LNode,int> B;
	B.init(v2);
	find_intersection(A,B);
	cout << A << endl;
	return 0;
}