#include <iostream>
#include <stack>
using namespace std;
void dispatch(const char* sequence) {
	stack<char> s;
	while (*sequence != '\0') {
		if (*sequence == 'H') {
			s.push('H');
		} else if (*sequence == 'S') {
			cout << 'S';
		}
		sequence++;
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
int main() {
	dispatch("HSHSSSHSSHHHS");
	return 0;
}