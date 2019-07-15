/*
 *				1,	n = 0
 * Pn(x) = 		2x, n = 1
 *				2xPn-1(x) - 2(n-1)Pn-2(x),  n > 1
 */
#include <iostream>
#include <stack>
using namespace std;
struct Node {
	int no;
	double val;
	Node(int n):no(n),val(0){}
};

double calculate(double x,int n) {
	if (n == 0) return 1;
	if (n == 1) return 2*x;
	stack<Node> s;
	for (int i = n; i >= 2;i--) {
		s.push(Node(i));
	}
	double a = 1;
	double b = 2 * x;
	while (!s.empty()) {
		auto top = s.top();
		s.pop();
		top.val = 2*x*b - 2*(top.no-1)*a;
		a = b;
		b = top.val;
	}
	return b;
}

double P(double x,int n) {
	if (n == 0) return 1;
	if (n == 1) return 2*x;
	return 2*x*P(x,n-1) - 2 * (n-1) * P(x,n-2);
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << (P(2,i) == calculate(2,i)) << endl;
	}
	return 0;
}