#include "LinkedList.hpp"

using NodeType = LNode<int>;
// same with problem 6
void sort_list_problem_6(NodeType* head) {
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

// introduced by solution
void min_delete(NodeType* head) {
	while(head->next != nullptr) {
		int min_data = 0x3f3f3f3f;
		NodeType* min_node = nullptr;
		NodeType* min_prev = nullptr;
		auto prev = head;
		auto p = head->next;
		while (p != nullptr) {
			if (p->data < min_data) {
				min_node = p;
				min_data = p->data;
				min_prev = prev;
			}
			prev = p;
			p = p->next;
		}
		min_prev->next = min_node->next;
		cout << min_node->data <<" ";
		delete min_node;
	}
	cout << endl;
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
//	vector<int> v = {0};
	LinkedList<LNode,int> linked_list;
	linked_list.init(v);
	min_delete(linked_list.get_head());
	cout << linked_list << endl;
	return 0;
}