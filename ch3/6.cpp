#include "LinkedList.hpp"

using NodeType = LNode<int>;
void sort_list(NodeType* head) {
	auto p = head->next;
	head->next = nullptr;
	while (p != nullptr) {
		auto next_p = p->next;
		auto q = head->next;
		auto prev = head;
		while (q && q->data < p->data) {
			prev = q;
			q = q->next;
		}
		p->next = q;
		prev->next = p;
		p = next_p;
	}
}
int main() {
	vector<int> v = {1,1,2,3,4,5,1};
//	vector<int> v = {0};
	SingleLinkedList<int> linked_list;
	linked_list.init(v);
	sort_list(linked_list.get_head());
	cout << linked_list << endl;
	return 0;
}