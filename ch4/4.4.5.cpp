#include "tree.hpp"
#include <iostream>
using namespace std;
template <class T>
int getLeavesCount(TreeNode<T>* root) {
	if (!root) return 0;
	if (!root->firstChild) return getLeavesCount(root->nextSibling) + 1;
	return getLeavesCount(root->nextSibling) + getLeavesCount(root->firstChild);

}
int main() {
	Forest<char> f;
	f.build_test_forest();
	cout << getLeavesCount(f.getRoot()) << endl;
	return 0;
}