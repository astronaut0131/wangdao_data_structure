#include "LinkedList.hpp"

using NodeType = LNode<int>;
void reverse_list(NodeType* head) {
	auto p = head->next;
	head->next = nullptr;
	while (p != nullptr) {
		auto next_p = p->next;
		p->next = head->next;
		head->next = p;
		p = next_p;
	}
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	LinkedList<int> linked_list(v);
	reverse_list(linked_list.get_head());
	cout << linked_list << endl;
	return 0;
}