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
	// common should be destructed after L1,L2
	// note the LIFO rule of stack
	LinkedList<int> common(v,false);
	// no head
	LinkedList<int> L1(v,false);
	v = {3,2,1};
	LinkedList<int> L2(v,false);
	// common part
	v = {4,5,6};
	L1.concatenate(common);
	L2.concatenate(common);
	auto result = find_common(L1.get_head(),L2.get_head());
	print_linked_list<int>(result);
	return 0;
}