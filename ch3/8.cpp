#include "LinkedList.hpp"

using NodeType = LNode<int>;
NodeType* find_common(NodeType* L1,NodeType* L2) {
	auto p1 = L1;
	auto p2 = L2;
	while (p1 != p2) {
		if (p1->next == nullptr) {
			p1->next = p2;
		}
		if (p2->next == nullptr) {
			p2->next = p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
int main() {
	vector<int> v = {1,2,3};
	LinkedList<LNode,int> common(false);
	common.init(v);
	// no head
	LinkedList<LNode,int> L1(false);
	v = {3,2,1};
	L1.init(v);
	LinkedList<LNode,int> L2(false);
	v = {4,5,6};
	L2.init(v);
	auto L1_tail = L1.get_head();
	auto L2_tail = L2.get_head();
	while (L1_tail->next != nullptr) {
		L1_tail = L1_tail->next;
	}
	while (L2_tail->next != nullptr) {
		L2_tail = L2_tail->next;
	}
	L1_tail->next = common.get_head();
	L2_tail->next = common.get_head();
	auto result = find_common(L1.get_head(),L2.get_head());
	print_linked_list<int>(result);
	L1_tail->next = nullptr;
	L2_tail->next = nullptr;
	return 0;
}