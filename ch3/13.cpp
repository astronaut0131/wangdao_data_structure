#include "LinkedList.hpp"
using NodeType = LNode<int>;

NodeType* merge_list(LinkedList<int>& A, LinkedList<int>& B) {
	auto dummy = generate_dummy_head<int>();
	auto p1 = A.get_head();
	auto p2 = B.get_head();
	while (p1 && p2) {
		if (p1->data < p2->data) {
			auto next_p1 = p1->next;
			p1->next = dummy->next;
			dummy->next = p1;
			p1 = next_p1;
		} else {
			auto next_p2 = p2->next;
			p2->next = dummy->next;
			dummy->next = p2;
			p2 = next_p2;
		}
	}
	while (p1) {
		auto next_p1 = p1->next;
		p1->next = dummy->next;
		dummy->next = p1;
		p1 = next_p1;
	}
	while (p2) {
		auto next_p2 = p2->next;
		p2->next = dummy->next;
		dummy->next = p2;
		p2 = next_p2;
	}
	// avoid double free
	A.set_head(nullptr);
	B.set_head(nullptr);
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
	auto result = merge_list(A,B);
	print_linked_list<int>(result);
	free_linked_list<int>(result);
	return 0;
}