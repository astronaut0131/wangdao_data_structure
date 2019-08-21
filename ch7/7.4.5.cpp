#include <iostream>
#include <vector>
using namespace std;
bool IsMinHeap(const vector<int> &seq,int i) {
	if (2 * i + 2 < seq.size()) {
		return seq[i] < seq[2 * i + 1] && seq[i] < seq[2 * i + 2] && IsMinHeap(seq,2 * i + 1) && IsMinHeap(seq,2 *i + 2);
	} else if (2 * i + 1< seq.size()) {
		return seq[i] < seq[2 * i + 1] && IsMinHeap(seq,2 * i + 1);
	} else {
		return true;
	}
}

int main() {
	vector<int> a = {19,34,26,97,56,75};
	cout << IsMinHeap(a,0) << endl;
	vector<int> b = {19,56,26,97,34,75};
	cout << IsMinHeap(b,0) << endl;	
	return 0;
}