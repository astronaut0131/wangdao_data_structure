#include <iostream>
#include <stack>

using std::istream;
using std::ostream;

template <class T>
struct BinTreeNode {
	BinTreeNode(T x,BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr)
		: data(x),leftChild(l),rightChild(r) {} 
	T data;
	BinTreeNode<T> *leftChild,*rightChild;
};

template <class T>
class BinaryTree {
public:
	BinaryTree():root(nullptr) {}
	BinaryTree(T value):RefValue(value),root(nullptr) {}
	~BinaryTree() { destroy(root); }
	bool IsEmpty() { return root == nullptr; }
	BinTreeNode<T> *getRoot() const { return root; }
	BinTreeNode<T> setRoot(BinTreeNode<T>* r) { root = r; } 
	void generate_test_tree();
protected:
	void destroy(BinTreeNode<T>* subTree);
	void CreateBinTree(istream& in,BinTreeNode<T> *&subTree);
	BinTreeNode<T> *root;
	T RefValue;	// eof for input stream
	friend istream& operator >> (istream& in, BinaryTree<T>& Tree);
//	friend ostream& operator << (ostream& out,const BinaryTree<T>& Tree);
};

template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T>* subTree) {
	if (subTree) {
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}

/*
 *			1
 *		   / \
 *		  2   3
 *		 / \   \
 *		4   5   6
 *		   /
 *		  7
 *
 * level order 1 2 3 4 5 6 7
 * pre order 1 2 4 5 7 3 6
 * in order 4 2 7 5 1 3 6
 * post order 4 7 5 2 6 3 1
 */

template <>
void BinaryTree<int>::generate_test_tree() {
	root = new BinTreeNode<int>(1);
	root->leftChild = new BinTreeNode<int>(2);
	root->rightChild = new BinTreeNode<int>(3);
	root->leftChild->leftChild = new BinTreeNode<int>(4);
	root->leftChild->rightChild = new BinTreeNode<int>(5);
	root->leftChild->rightChild->leftChild = new BinTreeNode<int>(7);
	root->rightChild->rightChild = new BinTreeNode<int>(6);
}

/*
template <class T>
void BinaryTree<T>::CreateBinTree(istream& in,BinTreeNode<T> *&subTree) {
	stack<BinTreeNode<T>*> s;
	subTree = nullptr;
	BinTreeNode<T> *p,*t;
	int k;
	char ch;
	in >> ch;
	while (ch != RefValue) {
		switch(ch) {
			case '(': s.push(p); k = 1; break;
			case ')': t = s.top(); s.pop(); break;
			case ',': k = 2;
		}
	}
}
*/

// template <class T>
// istream& operator >> (istream& in, BinaryTree<T>& Tree) {
// 	CreateBinTree<char>(in,Tree.root);
// 	return in;
// }