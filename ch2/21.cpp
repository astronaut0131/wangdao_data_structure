#include "LinkedList.hpp"
using NodeType = LNode<int>;
//full score solution: one pass by two pointers
int find_countdown_k(const LinkedList<LNode,int>& A, int k){
	if (k <= 0) return 0;
	auto head = A.get_head();
	auto p1 = head->next;
	auto p2 = head->next;
	// p2 is ahead of p1(head) by k node
	for (int i = 0; i < k; i++) {
		if (p2 == nullptr) return 0;
		p2 = p2->next;
	}
	// p2 reaches nullptr means p1 is pointing the countdown k node
	while(p2 != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << "countdown "  << k << " element is " << p1->data << endl;
	return 1;
}

int main() {
	vector<int> v1 = {1,2,3,4,5};
	LinkedList<LNode,int> A;
	A.init(v1);
	cout << find_countdown_k(A,1) << endl;
	cout << find_countdown_k(A,5) << endl;
	cout << find_countdown_k(A,20) << endl;
	return 0;
}