#include "LinkedList.hpp"
using NodeType = LNode<int>;

void remove_dup(NodeType* L) {
	NodeType* prev = nullptr;
	while (L != nullptr) {
		auto next_L = L->next;
		if (prev == nullptr || L->data != prev->data) {
			prev = L;
		} else {
			prev->next = L->next;
			delete L;
		}
		L = next_L;
	}
}

int main() {
	vector<int> v = {7,10,10,21,30,42,42,42,51,70};
	// without head
	LinkedList<int> linked_list(v,false);
	remove_dup(linked_list.get_head());
	cout << linked_list;
	return 0;
}