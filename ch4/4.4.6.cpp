#include <iostream>
#include "tree.hpp"
using namespace std;
template <class T>
int getHeight(TreeNode<T>* root) {
	if (!root) return 0;
	return max(getHeight(root->firstChild)+1,getHeight(root->nextSibling));
}

int main() {
	Tree<char> t;
	t.build_test_tree();
	cout << getHeight(t.getRoot());
	return 0;
}