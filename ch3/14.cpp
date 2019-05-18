#include "LinkedList.hpp"
using NodeType = LNode<int>;

NodeType* generate_common_list(LinkedList<int>& A, LinkedList<int>& B) {
	auto dummy = generate_dummy_head<int>();
	auto p1 = A.get_head()->next;
	auto p2 = B.get_head()->next;
	auto p = dummy;
	while (p1 && p2) {
		if (p1->data < p2->data) {
			p1 = p1->next;
		} else if (p1->data > p2->data) {
			p2 = p2->next;
		} else {
			auto node = new LNode<int>(p1->data);
			p->next = node;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	auto result = dummy->next;
	delete dummy;
	return result;
}

int main() {
	vector<int> v1 = {1,3,5,6,6,7,9,10};
	vector<int> v2 = {0,2,4,5,6,8,9,11,12};
	LinkedList<int> linked_list(false);
	LinkedList<int> A(v1,false);
	LinkedList<int> B(v2,false);
	auto result = generate_common_list(A,B);
	print_linked_list<int>(result);
	free_linked_list<int>(result);
	return 0;
}