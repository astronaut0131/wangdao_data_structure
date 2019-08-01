#include <iostream>
#include "binary_tree.hpp"
#include <queue>
#include <stack>
using namespace std;

template <class T>
BinTreeNode<T>* kthLeastNode(BinTreeNode<T>* root,int k) {
	if (k <=0 || !root || k > root->subnode_cnt + 1) return nullptr;
	if (!root->leftChild) {
		if (k == 1) return root;
		return kthLeastNode(root->rightChild,k-1);
	} else {
		int left_node_cnt = root->leftChild->subnode_cnt + 1;
		if (left_node_cnt + 1 == k) return root;
		else if (left_node_cnt + 1 > k) return kthLeastNode(root->leftChild,k);
		else return kthLeastNode(root->rightChild,k - left_node_cnt - 1);
	}
}
     
 /*		6
 *	   / \
 *    2   8  
 *   / \ 
 *  1   4
 *     /
 *    3
 *
 */

int main() {
	BinaryTree<int> bt;
	bt.generate_test_BST();
	for (int i = 1; i <= 6; i++)
		cout << kthLeastNode(bt.getRoot(),i)->data << endl;
	return 0;
}