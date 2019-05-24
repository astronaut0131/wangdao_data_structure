#include "LinkedList.hpp"

using NodeType = LNode<int>;
void remove_x(NodeType* head,int x) {
	auto prev = head;
	auto p = head->next;
	head->next = nullptr;
	while (p != nullptr) {
		auto next_p = p->next;
		if (p->data != x) {
			prev->next = p;
			prev = prev->next;
			prev->next = nullptr;
		} else {
			delete p;
		}
		p = next_p;
	}
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	//vector<int> v = {1,1,1};
	LinkedList<LNode,int> linked_list;
	linked_list.init(v);
	remove_x(linked_list.get_head(),1);
	cout << linked_list << endl;
	return 0;
}