#include "LinkedList.hpp"
using NodeType = LNode<int>;
template<class ElemType>
struct FreqNode:public DoubleLNode<ElemType> {
	FreqNode* next;
	int freq;
	FreqNode(ElemType data):DoubleLNode<ElemType>(data),freq(0) {}
};

FreqNode<int>* Locate(LinkedList<FreqNode,int> &L, int x) {
	auto head = L.get_head();
	auto p = head->next;
	auto prev = head;
	while (p != head) {
		if (p->data == x) break;
		prev = p;
		p = p->next;
	}
	prev->next = p->next;
	p->freq++;
	auto q = head->next;
	prev = head;
	while(p->freq < q->freq) {
		prev = q;
		q = q->next;
	}
	p->next = prev->next;
	prev->next = p;
	return p;
}
int main() {
	vector<int> v1 = {1,2,3,4,5};
	LinkedList<FreqNode,int> A;
	A.init(v1);
	cout << A;
	Locate(A,5);
	Locate(A,4);
	cout << A;
	Locate(A,5);
	cout << A;
	Locate(A,3);
	cout << A;
	return 0;
}