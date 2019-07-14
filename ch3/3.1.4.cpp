#include "LinkedList.hpp"
#include <stack>
bool is_symmetry(const LinkedList<LNode,int>& L,int n) {
	std::stack<int> s;
	auto head = L.get_head();
	auto p = head->next;
	for (int i = 0; i < n/2; i++) {
		s.push(p->data);
		p = p->next;
	}
	if (n % 2 != 0) p = p->next;
	while(p != nullptr) {
		if (s.empty()) return false;
		int data = s.top();
		s.pop();
		if (data != p->data) return false;
		p = p->next;
	}
	return s.empty();
}
int main() {
	vector<int> v1 = {1,2,3,3,2,1};
	vector<int> v2 = {1,2,3,2,1};
	vector<int> v3 = {1,2,3,2,1,0};
	LinkedList<LNode,int> L1,L2,L3;
	L1.init(v1);
	L2.init(v2);
	L3.init(v3);
	cout << is_symmetry(L1,v1.size()) << endl;
	cout << is_symmetry(L2,v2.size()) << endl;
	cout << is_symmetry(L3,v3.size()) << endl;
	return 0;
}