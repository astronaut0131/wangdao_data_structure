#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;
template <class T>
void destroy(BinTreeNode<T>* root) {
	if (!root) return;
	if (root->leftChild) destroy(root->leftChild);
	if (root->rightChild) destroy(root->rightChild);
	delete root;
}

template <class T>
void deleteSubtreeX(BinaryTree<T> &bt,T x) {
	if (!root) return;
	queue<BinTreeNode<T>*> q;
	if (bt.getRoot()->data == x) {
		destroy<T>(bt.getRoot());
		bt.setRoot(nullptr);
		return;
	}
	q.push(bt.getRoot());
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		if (front->leftChild) {
			if (front->leftChild->data == x){
				destroy(front->leftChild);
				front->leftChild = nullptr;
			} else { 
				q.push(front->leftChild);
			}
		}
		if (front->rightChild) {
			if (front->rightChild->data == x){
				destroy(front->rightChild);
				front->rightChild = nullptr;
			} else { 
				q.push(front->rightChild);
			}	
		}
	}
}

/* before
 *			 1
 *		   /   \
 *		  2     3
 *		 / \   / 
 *		4   5 6  
 *		 	 / \
 *			2   1
 *		   /     \
 *        3       2
*/

/* after delete 2
 *			 1
 *		       \
 *		        3
 *		       / 
 *		      6  
 *		 	   \
 *			    1
 *		         
 *               
*/
void visit(BinTreeNode<int> *p) {
	cout << p->data << " ";
}

int main() {
	auto bt = BinaryTree<int>();
	bt.generate_test_tree_c();
	deleteSubtreeX<int>(bt,2);
	bt.levelTraversal(visit);
	return 0;
}