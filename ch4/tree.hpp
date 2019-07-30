#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::cout;
using std::endl;

template <class T>
struct CommonTreeNode {
	T data;
	vector<CommonTreeNode<T>*> children;
	CommonTreeNode(T value = 0):data(value) {}
};

template <class T>
class CommonTree {
private:
	CommonTreeNode<T>* root;
	void destroy(CommonTreeNode<T>* root) {
		if (root) {
			for (auto p : root->children) {
				destroy(p);
			}
			delete root;
			root = nullptr;
		}
	}
public:
	void build_test_tree();
	CommonTreeNode<T>* getRoot() const { return root; }
	CommonTree():root(nullptr) {}
	CommonTree(CommonTree<T>* r):root(r) {}
	~CommonTree() { destroy(root); }
	vector<CommonTreeNode<T>*> getLevelSeq() const;
};

template <class T>
struct TreeNode {
	T data;
	TreeNode<T> *firstChild, *nextSibling;
	TreeNode(T value = 0, TreeNode<T> *fc = nullptr, TreeNode<T> *ns = nullptr):
	data(value),firstChild(fc),nextSibling(ns){}
};

template <class T>
class Tree{
private:
	TreeNode<T> *root;
	void destroy(TreeNode<T>* root) {
		if (root) {
			destroy(root->firstChild);
			destroy(root->nextSibling);
			delete root;
			root = nullptr;
		}
	}
	bool is_same(TreeNode<T> *a,TreeNode<T>* b) const {
		if (!a && !b) return true;
		if (a&&b) {
			return a->data == b->data && is_same(a->firstChild,b->firstChild) 
		&& is_same(a->nextSibling,b->nextSibling);
		}
		return false;
	}
public:
	void build_test_tree();
	TreeNode<T>* getRoot() const { return root; }
	Tree():root(nullptr) {}
	Tree(TreeNode<T>* r):root(r) {}
	~Tree() { destroy(root); }
	bool is_same(TreeNode<T> *other) const;
};

template <class T>
class Forest{
private:
	TreeNode<T> *root;
	void destroy(TreeNode<T>* root) {
		if (root) {
			destroy(root->firstChild);
			destroy(root->nextSibling);
			delete root;
			root = nullptr;
		}
	}
public:
	void build_test_forest();
	TreeNode<T>* getRoot() const { return root; }
	Forest():root(nullptr) {}
	Forest(TreeNode<T>* r):root(r) {}
	~Forest() { destroy(root); }
};

/*				 R
 *			  /     \
 *           A       C    	        R          C
 *          / \     / \			   /		  /
 *         D   E   F   K		  A          F         K
 *                / \			 / \        / \
 *               G   H  		D   E      G   H
 *
 *
 *			R           C
 *		   / \         / \
 *		  A   E       F   H        K
 *        |           |
 *		  D           G
 */
template <>
void Forest<char>::build_test_forest() {
	using TreeNode = TreeNode<char>;
	root = new TreeNode('R');
	root->firstChild = new TreeNode('A');
	root->nextSibling = new TreeNode('C');
	root->firstChild->firstChild = new TreeNode('D');
	root->firstChild->nextSibling = new TreeNode('E');
	root->nextSibling->firstChild = new TreeNode('F');
	root->nextSibling->nextSibling = new TreeNode('K');
	root->nextSibling->firstChild->firstChild = new TreeNode('G');
	root->nextSibling->firstChild->nextSibling = new TreeNode('H');
}

/*				 R
 *			  /  |  \
 *           A   B   C
 *          / \      |
 *         D   E     F
 *                 / | \
 *                G  H  K
 *
 *
 */
template <class T>
vector<CommonTreeNode<T>*> CommonTree<T>::getLevelSeq() const{
	vector<CommonTreeNode<T>*> v;
	if (!root) {
		return v;
	}
	queue<decltype(root)> q;
	q.push(root);
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		v.push_back(front);
		for(auto p:front->children)
			q.push(p);
	}
	return v;
}

template <>
void CommonTree<char>::build_test_tree() {
	using CommonTreeNode = CommonTreeNode<char>;
	root = new CommonTreeNode('R');
	auto A = new CommonTreeNode('A');
	auto B = new CommonTreeNode('B');
	auto C = new CommonTreeNode('C');
	auto D = new CommonTreeNode('D');
	auto E = new CommonTreeNode('E');
	auto F = new CommonTreeNode('F');
	auto G = new CommonTreeNode('G');
	auto H = new CommonTreeNode('H');
	auto K = new CommonTreeNode('K');
	root->children = {A,B,C};
	A->children = {D,E};
	C->children = {F};
	F->children = {G,H,K};
}

template <class T>
bool Tree<T>::is_same(TreeNode<T>* other) const {
	return is_same(root,other);
}
/*				 R
 *			  /  |  \
 *           A   B   C
 *          / \      |
 *         D   E     F
 *                 / | \
 *                G  H  K
 *
 *
 */

template <>
void Tree<char>::build_test_tree() {
	using TreeNode = TreeNode<char>;
	root = new TreeNode('R');
	root->firstChild = new TreeNode('A');
	root->firstChild->firstChild = new TreeNode('D');
	root->firstChild->nextSibling = new TreeNode('B');
	root->firstChild->firstChild->nextSibling = new TreeNode('E');
	root->firstChild->nextSibling->nextSibling = new TreeNode('C');
	root->firstChild->nextSibling->nextSibling->firstChild = new TreeNode('F');
	root->firstChild->nextSibling->nextSibling->firstChild->firstChild = new TreeNode('G');
	root->firstChild->nextSibling->nextSibling->firstChild->firstChild->nextSibling = new TreeNode('H');
	root->firstChild->nextSibling->nextSibling->firstChild->firstChild->nextSibling->nextSibling
	 = new TreeNode('K');
}