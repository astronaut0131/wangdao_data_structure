#include "LinkedList.hpp"
using NodeType = LNode<char>;
//time complexity O(A.len + B.len)
NodeType *find_common_suffix(const LinkedList<LNode,char> &A,const LinkedList<LNode,char> &B) {
	auto p1 = A.get_head()->next;
	auto p2 = B.get_head()->next;
	// say A.len = m, B.len = n, and m > n, p1 = A head and p2 = B head
	// when p2 reaches the end of B, p1 is m-n node from the end of A
	// then redirect p2 to A head
	// when p1 reaches the end of A, p2 is m-n node from the head of A
	// redirect p1 to B head
	// p1 has n nodes to go while p2 has m-(m-n) = n nodes to go, they will reach the common node at the same time.
	while(p1 != p2) {
		p1 = p1->next ? p1->next:B.get_head()->next;
		p2 = p2->next ? p2->next:A.get_head()->next;
	}
	return p1;
}

int main() {
	vector<char> v1 = {'l','o','a','d'};
	vector<char> v2 = {'b','e'};
	LinkedList<LNode,char> A,B;
	A.init(v1);
	B.init(v2);
	vector<char> common_vec = {'i','n','g'};
	LinkedList<LNode,char> common(false);
	common.init(common_vec);
	auto a = A.get_head();
	auto b = B.get_head();
	while (a->next != nullptr) {
		a = a->next;
	}
	while (b->next != nullptr) {
		b = b->next;
	}
	a->next = common.get_head();
	b->next = common.get_head();
	auto p = find_common_suffix(A,B);
	print_linked_list<char>(p);
	a->next = nullptr;
	b->next = nullptr;
	return 0;
}