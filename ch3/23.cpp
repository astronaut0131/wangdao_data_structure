#include "LinkedList.hpp"
using NodeType = LNode<int>;
using std::fill;
//time complexity: O(n) n is A.len
//space complexity: O(n) n is the max abs in all A elements 
void remove_dup(LinkedList<LNode,int>& A, int n){
	int exist[n+1];
	fill(exist,exist+n+1,false);
	auto head = A.get_head();
	auto p = head->next;
	auto prev = head;
	while (p != nullptr) {
		auto next_p = p->next;
		if (exist[abs(p->data)]) {
			prev->next = p->next;
			delete p;
		} else {
			exist[abs(p->data)] = true;
			prev = p;
		}
		p = next_p;
	}
}

int main() {
	vector<int> v1 = {21,-15,-15,-7,15};
	LinkedList<LNode,int> A;
	A.init(v1);
	remove_dup(A,*max_element(v1.begin(),v1.end()));
	cout << A;
	return 0;
}