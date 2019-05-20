#include "LinkedList.hpp"
using NodeType = LNode<int>;

// this problem is similar to prob 10
// but this time we use head insert to B to get it reversed
void split_list(NodeType* L, NodeType* A, NodeType* B) {
	int cnt = 0;
	auto p = L->next;
	auto pa = A;
	auto pb = B;
	while (p != nullptr) {
		cnt++;
		auto next_p = p->next;
		if (cnt % 2 != 0) {
			pa->next = p;
			pa = pa->next;
			pa->next = nullptr;
		} else {
			p->next = pb->next;
			pb->next = p;
		}
		p = next_p;
	}
	L->next = nullptr;
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	SingleLinkedList<int> linked_list;
	linked_list.init(v);
	SingleLinkedList<int> A;
	SingleLinkedList<int> B;
	split_list(linked_list.get_head(),A.get_head(),B.get_head());
	cout << A;
	cout << B;
	return 0;
}