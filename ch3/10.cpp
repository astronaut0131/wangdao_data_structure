#include "LinkedList.hpp"
using NodeType = LNode<int>;

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
			pb->next = p;
			pb = pb->next;
			pb->next = nullptr;
		}
		p = next_p;
	}
	L->next = nullptr;
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	LinkedList<int> linked_list(v);
	LinkedList<int> A;
	LinkedList<int> B;
	split_list(linked_list.get_head(),A.get_head(),B.get_head());
	cout << A;
	cout << B;
	return 0;
}