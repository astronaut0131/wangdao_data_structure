#include "LinkedList.hpp"

using NodeType = LNode<int>;
void remove_min(NodeType* head) {
	auto p = head->next;
	auto prev = head;
	NodeType* min_node = nullptr;
	NodeType* min_prev = nullptr;
	while (p != nullptr) {
		if (min_node == nullptr || p->data < min_node->data) {
			min_node = p;
			min_prev = prev;
		}
		prev = p;
		p = p->next;
	}
	min_prev->next = min_node->next;
	delete min_node;
}

int main() {
	vector<int> v = {1,1,2,3,0,4,5,1};
	LinkedList<int> linked_list(v);
	remove_min(linked_list.get_head());
	cout << linked_list << endl;
	return 0;
}