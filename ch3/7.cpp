#include "LinkedList.hpp"

using NodeType = LNode<int>;
void erase_range(NodeType* head,int lower, int upper) {
	auto p = head->next;
	auto prev = head;
	while (p != nullptr) {
		auto next_p = p->next;
		if (p->data >= lower && p->data <= upper) {
			prev->next = next_p;
			delete p;
		} else {
			prev = p;
		}
		p = next_p;
	}
}
int main() {
	vector<int> v = {1,1,2,3,4,5,1};
//	vector<int> v = {0};
	SingleLinkedList<int> linked_list;
	linked_list.init(v);
	erase_range(linked_list.get_head(),0,3);
	cout << linked_list << endl;
	return 0;
}