#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef int ElementType;
void reverse_queue(queue<ElementType> &q) {
	stack<ElementType> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}
int main() {
	queue<ElementType> q; 
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	reverse_queue(q);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}