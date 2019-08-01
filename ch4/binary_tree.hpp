#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using std::istream;
using std::ostream;
using std::queue;
using std::vector;
using std::stack;

#define WEIGHT
#define COUNT

template <class T>
struct BinTreeNode {
	BinTreeNode(T x,BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr)
		: data(x),leftChild(l),rightChild(r) {} 
	T data;
	BinTreeNode<T> *leftChild,*rightChild;
#ifdef WEIGHT
	int weight; 
#endif
#ifdef COUNT
	int subnode_cnt;
#endif
};

template <class T>
class BinaryTree {
public:
	BinaryTree():root(nullptr) {}
	BinaryTree(T value):RefValue(value),root(nullptr) {}
	~BinaryTree() { destroy(root); }
	bool IsEmpty() { return root == nullptr; }
	BinTreeNode<T> *getRoot() const { return root; }
	void setRoot(BinTreeNode<T>* r) { 
		if (root != r)
			destroy(root);
		root = r; 
	} 
	void levelTraversal(void (*visit)(BinTreeNode<T> *p));
	void generate_test_tree();
	void generate_test_tree_b();
	void generate_test_tree_c();
	void generate_test_BST();
	void generate_test_AVL();
	vector<T> getPreSequence();
protected:
	void destroy(BinTreeNode<T>* subTree);
	void CreateBinTree(istream& in,BinTreeNode<T> *&subTree);
	BinTreeNode<T> *root;
	T RefValue;	// eof for input stream
	friend istream& operator >> (istream& in, BinaryTree<T>& Tree);
//	friend ostream& operator << (ostream& out,const BinaryTree<T>& Tree);
};

template <class T>
vector<T> BinaryTree<T>::getPreSequence() {
	vector<T> v;
	if (!root) return v;
	stack<BinTreeNode<T>*> s;
	s.push(root);
	while (!s.empty()) {
		auto top = s.top();
		s.pop();
		v.push_back(top->data);
		if (top->rightChild) {
			s.push(top->rightChild);
		}
		if (top->leftChild) {
			s.push(top->leftChild);
		}
	}
	return v;
}

template <class T>
void BinaryTree<T>::levelTraversal(void (*visit)(BinTreeNode<T> *p)) {
	queue<BinTreeNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		auto front = q.front();
		visit(front);
		q.pop();
		if (front->leftChild)
			q.push(front->leftChild);
		if (front->rightChild)
			q.push(front->rightChild);
	}
}

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
	destroy(root);
	root = new BinTreeNode<int>(1);
	root->leftChild = new BinTreeNode<int>(2);
	root->rightChild = new BinTreeNode<int>(3);
	root->leftChild->leftChild = new BinTreeNode<int>(4);
	root->leftChild->rightChild = new BinTreeNode<int>(5);
	root->leftChild->rightChild->leftChild = new BinTreeNode<int>(7);
	root->rightChild->rightChild = new BinTreeNode<int>(6);
#ifdef WEIGHT
	root->leftChild->leftChild->weight = 4;
	root->leftChild->rightChild->leftChild->weight = 7;
	root->rightChild->rightChild->weight = 6;
#endif
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
template <>
void BinaryTree<int>::generate_test_BST() {
	destroy(root);
	root = new BinTreeNode<int>(6);
	root->rightChild = new BinTreeNode<int>(8);
	root->leftChild = new BinTreeNode<int>(2);
	root->leftChild->leftChild = new BinTreeNode<int>(1);
	root->leftChild->rightChild = new BinTreeNode<int>(4);
	root->leftChild->rightChild->leftChild = new BinTreeNode<int>(3);
#ifdef COUNT
	root->subnode_cnt = 5;
	root->rightChild->subnode_cnt = 0;
	root->leftChild->subnode_cnt = 3;
	root->leftChild->leftChild->subnode_cnt = 0;
	root->leftChild->rightChild->subnode_cnt = 1;
	root->leftChild->rightChild->leftChild->subnode_cnt = 0;
#endif
}

/*		6
 *	   / \
 *    2   8  
 *   / \ 
 *  1   4
 */

template <>
void BinaryTree<int>::generate_test_AVL() {
	destroy(root);
	root = new BinTreeNode<int>(6);
	root->rightChild = new BinTreeNode<int>(8);
	root->leftChild = new BinTreeNode<int>(2);
	root->leftChild->leftChild = new BinTreeNode<int>(1);
	root->leftChild->rightChild = new BinTreeNode<int>(4);
}
/*
 *			 1
 *		   /   \
 *		  2     3
 *		 / \   /
 *		4   5 6  
 *		 
 */

template<>
void BinaryTree<int>::generate_test_tree_b() {
	destroy(root);
	root = new BinTreeNode<int>(1);
	root->leftChild = new BinTreeNode<int>(2);
	root->rightChild = new BinTreeNode<int>(3);
	root->leftChild->leftChild = new BinTreeNode<int>(4);
	root->leftChild->rightChild = new BinTreeNode<int>(5);
	root->rightChild->leftChild = new BinTreeNode<int>(6);
#ifdef WEIGHT
	root->leftChild->leftChild->weight = 4;
	root->leftChild->rightChild->weight = 5;
	root->rightChild->leftChild->weight = 6;
#endif
}
/*
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
template<>
void BinaryTree<int>::generate_test_tree_c() {
	destroy(root);
	root = new BinTreeNode<int>(1);
	root->leftChild = new BinTreeNode<int>(2);
	root->rightChild = new BinTreeNode<int>(3);
	root->leftChild->leftChild = new BinTreeNode<int>(4);
	root->leftChild->rightChild = new BinTreeNode<int>(5);
	root->rightChild->leftChild = new BinTreeNode<int>(6);
	root->rightChild->leftChild->leftChild = new BinTreeNode<int>(2);
	root->rightChild->leftChild->leftChild->leftChild = new BinTreeNode<int>(3);
	root->rightChild->leftChild->rightChild = new BinTreeNode<int>(1);
	root->rightChild->leftChild->rightChild->rightChild = new BinTreeNode<int>(2);
#ifdef WEIGHT
	root->leftChild->leftChild->weight = 4;
	root->leftChild->rightChild->weight = 5;
	root->rightChild->leftChild->leftChild->leftChild->weight = 3;
	root->rightChild->leftChild->rightChild->rightChild->weight = 2;
#endif
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