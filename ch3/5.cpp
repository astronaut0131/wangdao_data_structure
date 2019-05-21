#include "LinkedList.hpp"

using NodeType = LNode<int>;
void reverse_list_A(NodeType* head) {
	auto p = head->next;
	head->next = nullptr;
	while (p != nullptr) {
		auto next_p = p->next;
		p->next = head->next;
		head->next = p;
		p = next_p;
	}
}

void reverse_list_B(NodeType* head) {
	auto p = head->next;
	NodeType* prev = nullptr;
	while (p != nullptr) {
		auto next_p = p->next;
		p->next = prev;
		prev = p;
		p = next_p;
	}
	head->next = prev;
}
int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	LinkedList<LNode,int> linked_list;
	linked_list.init(v);
	//reverse_list_A(linked_list.get_head());
	reverse_list_B(linked_list.get_head());
	cout << linked_list << endl;
	return 0;
}