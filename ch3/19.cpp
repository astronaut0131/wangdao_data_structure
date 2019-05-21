#include "LinkedList.hpp"
using NodeType = LNode<int>;

void remove_min(LinkedList<LNode,int>& A){
	auto head = A.get_head();
	NodeType* min_prev = nullptr;
	int min_val = 0x3f3f3f3f;
	auto p = head->next;
	auto prev = head;
	while (p != head) {
		if (p->data < min_val) {
			min_val = p->data;
			min_prev = prev; 
		}
		prev = p;
		p = p->next;
	}
	auto min_node = min_prev->next;
	min_prev->next = min_node->next;
	cout << "delete " << min_node->data << endl;
	delete min_node;
}

int main() {
	vector<int> v1 = {1,2,3,4,5,5,4,3,2,1};
	LinkedList<LNode,int> A(true,true);
	A.init(v1);
	while(A.get_head()->next != A.get_head()) {
		remove_min(A);
	}
	delete A.get_head();
	A.set_head(nullptr);
	cout << A << endl;
	return 0;
}