#include <iostream>
#include <stack>
using namespace std;
bool is_valid_expr(const char* expr) {
	stack<char> s;
	while(*expr != '\0') {
		if (*expr == '[' || *expr == '{' || *expr == '(') {
			s.push(*expr);
		} else if (*expr == ']' && s.top() == '[') {
			s.pop();
		} else if (*expr == '}' && s.top() == '{') {
			s.pop();
		} else if (*expr == ')' && s.top() == '(') {
			s.pop();
		} else {
			return false;
		}
		expr++;
	}
	return s.empty();
}

int main() {
	cout << is_valid_expr("({[]})") << endl;
	cout << is_valid_expr("{[(]}") << endl;
	cout << is_valid_expr("{") << endl;
	return 0;
}