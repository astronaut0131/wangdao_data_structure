#include <iostream>
#include <stack>
using namespace std;
typedef int ElementType;
#define MAXSIZE 3
stack<ElementType> s1;
stack<ElementType> s2;

void Push(stack<ElementType> &s,ElementType x) {
	s.push(x);
}

void Pop(stack<ElementType> &s, ElementType& ret) {
	ret = s.top();
	s.pop();
}

bool StackEmpty(const stack<ElementType>& s) {
	return s.empty();
}

bool StackOverFlow(const stack<ElementType>& s) {
	return s.size() == MAXSIZE;
}

bool Enqueue(ElementType x) {
	if (StackOverFlow(s1)) {
		if (StackEmpty(s2) && !StackEmpty(s1)) {
			ElementType ret;
			while (!StackEmpty(s1)) {
				Pop(s1,ret);
				Push(s2,ret);
			}
		}
		else{
			cout << "Queue full!" << endl;
			return false;
		}
	};
	Push(s1,x);
	return true;
}

bool Dequeue(ElementType& ret) {
	if (StackEmpty(s2)) {
		if (StackEmpty(s2) && !StackEmpty(s1)) {
			ElementType ret;
			while (!StackEmpty(s1)) {
				Pop(s1,ret);
				Push(s2,ret);
			}
		}
		else {
			cout << "Queue empty!" << endl;
			return false;
		}
	}
	Pop(s2,ret);
	return true;
}

bool QueueEmpty() {
	return StackEmpty(s1) && StackEmpty(s2);
}

int main() {
	cout << QueueEmpty() << endl;
	ElementType ret;
	Dequeue(ret);
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Enqueue(6);
	Enqueue(7);
	while (!QueueEmpty()) {
		Dequeue(ret);
		cout << ret << " ";
	}
	cout << endl;
	Dequeue(ret);
	return 0;
}