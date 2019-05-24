#include <iostream>
using namespace std;
bool is_valid_seq(const string& s) {
	int cnt = 0;
	for(char ch : s) {
		if (ch == 'I') cnt++;
		else if (ch == 'O') cnt--;
		else return false;
		if (cnt < 0) return false;
	}
	return cnt == 0;
}
int main() {
	cout << is_valid_seq("IOIIOIOO") << endl;
	cout << is_valid_seq("IOOIOIIO") << endl;
	cout << is_valid_seq("IIIOIOIO") << endl;
	cout << is_valid_seq("IIIOOIOO") << endl;
 	return 0;
}