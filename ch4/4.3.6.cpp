#include "binary_tree.hpp"
#include <iostream>
#include <vector>
using namespace std;
BinTreeNode<int>* build_tree(const vector<int>& pre,const vector<int>& in,
	int preL,int preR,int inL,int inR) {
	if (preL < 0 || preR >=pre.size() || inL < 0 || inR >= in.size()
		|| preL > preR || inL > inR) {
		return nullptr;
	}
	auto root = new BinTreeNode<int>(pre[preL]);
	int pos = -1;
	for (int i = inL; i <= inR; i++) {
		if (in[i] == root->data) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		cout << "parse error" << endl;
		//error
		exit(1);
	}
	root->leftChild = build_tree(pre,in,preL+1,preL+pos-inL,inL,pos-1);
	root->rightChild = build_tree(pre,in,preL+pos-inL+1,preR,pos+1,inR);
	return root;
}
void visit(BinTreeNode<int> *p) {
	cout << p->data << endl;
}

int main() {
	auto bt = BinaryTree<int>();
	/*
	 *			1
	 *		   / \
	 *		  2   3
	 *		 / \   \
	 *		4   5   6
	 *		   /
	 *		  7
	 *
	 */
	vector<int> pre{1,2,4,5,7,3,6};
	vector<int> in{4,2,7,5,1,3,6};
	bt.setRoot(build_tree(pre,in,0,pre.size()-1,0,in.size()-1));
	cout << int(bt.getRoot()==nullptr) << endl;
	bt.levelTraversal(visit);
	return 0;
}