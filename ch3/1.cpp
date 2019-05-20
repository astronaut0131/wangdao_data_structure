#include "LinkedList.hpp"

using NodeType = LNode<int>;
NodeType* remove_x(NodeType* head,int x) {
	if (!head) return nullptr;
	if (head->data == x) {
		delete head;
		return remove_x(head->next,x);
	} else {
		head->next = remove_x(head->next,x);
		return head;
	}
}

int main() {
	vector<int> v = {1,1,2,3,4,5,1};
	//vector<int> v = {1,1,1};
	SingleLinkedList<int> linked_list(false);
	linked_list.init(v);
	linked_list.set_head(remove_x(linked_list.get_head(),1));
	cout << linked_list << endl;
	return 0;
}