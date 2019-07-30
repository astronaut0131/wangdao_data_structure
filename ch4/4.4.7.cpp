#include <iostream>
#include "tree.hpp"
using namespace std;
template <class T>
TreeNode<T>* build_tree(vector<CommonTreeNode<T>*> seq) {
	vector<TreeNode<T>*> v(seq.size());
	for (int i = 0; i < v.size(); i++) {
		v[i] = new TreeNode<T>(seq[i]->data);
	}
	int k = 0;
	for (int i =0; i < v.size(); i++) {
		auto d = seq[i]->children.size();
		if (d) {
			k++;
			v[i]->firstChild = v[k];
			for (int j = 0; j < d-1; j++) {
				k++;
				v[k-1]->nextSibling = v[k];
			}
		}
	}
	return v[0];
}
int main() {
	CommonTree<char> t;
	Tree<char> t_same;
	t.build_test_tree();
	t_same.build_test_tree();
	auto level_seq = t.getLevelSeq();
	auto root = build_tree(level_seq);
	cout << t_same.is_same(root) << endl;
	return 0;
}