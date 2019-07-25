#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
void getPostSequence(const vector<T> &pre_sequence,int preL,int preR,
	vector<T> &post_sequence,int postL,int postR) {
	if (preL > preR || postL > postR) return;
	post_sequence[postR] = pre_sequence[preL];
	int half = (preR-preL) >> 1;
	getPostSequence(pre_sequence,preL+1,preL+half,post_sequence,postL,postL+half-1);
	getPostSequence(pre_sequence,preL+half+1,preR,post_sequence,postL+half,postR-1);
}

int main() {
	vector<int> pre_sequence = {1,2,4,5,3,6,7};
	auto res = pre_sequence;
	getPostSequence(pre_sequence,0,pre_sequence.size()-1,res,0,res.size()-1);
	for(auto i:res)
		cout << i << " ";
	cout << endl;
	vector<char> pre_sequence2 = {'A','B','C','D','E','F','G'};
	auto res2 = pre_sequence2;
	getPostSequence(pre_sequence2,0,pre_sequence2.size()-1,res2,0,res2.size()-1);
	for(auto i:res2)
		cout << i << " ";
	return 0;
}