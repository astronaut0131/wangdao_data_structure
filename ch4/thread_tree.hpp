#include <iostream>
template <class T>
struct ThreadNode{
	int ltag,rtag;
	ThreadNode<T> *leftChild,*rightChild;
	T data;
	ThreadNode(const T item):data(item),
	leftChild(nullptr),rightChild(nullptr),ltag(0),rtag(0){}
};

template <class T>
class ThreadTree{
protected:
	ThreadNode<T> *root;
	void createInThread(ThreadNode<T>* current,ThreadNode<T>* &pre);
	ThreadNode<T>* parent(ThreadNode<T> *t);
	void destroy(ThreadNode<T>* root) {
		if (root!=nullptr) {
			if (root->ltag == 0)
				destroy(root->leftChild);
			if (root->rtag == 0)
				destroy(root->rightChild);
			delete root;
		}
	}
public:
	ThreadTree():root(nullptr){}
	void createInThread();
	// first in order node
	ThreadNode<T> *First(ThreadNode<T> *current);
	// last in order node
	ThreadNode<T> *Last(ThreadNode<T> *current);
	// next in order node
	ThreadNode<T> *Next(ThreadNode<T> *current);
	// prior in order node
	ThreadNode<T> *Prior(ThreadNode<T> *current);
	void Inorder(void (*visit)(ThreadNode<T> *p)); // in order traversal
	void Preorder(void (*visit)(ThreadNode<T> *p)); // pre order traversal
	void Postorder(void (*visit)(ThreadNode<T> *p)); // post order traversal	
	void generate_test_tree();
	~ThreadTree() { destroy(root); }
};

template <>
void ThreadTree<int>::generate_test_tree() {
	destroy(root);
	root = new ThreadNode<int>(1);
	root->leftChild = new ThreadNode<int>(2);
	root->rightChild = new ThreadNode<int>(3);
	root->leftChild->leftChild = new ThreadNode<int>(4);
	root->leftChild->rightChild = new ThreadNode<int>(5);
	root->leftChild->rightChild->leftChild = new ThreadNode<int>(7);
	root->rightChild->rightChild = new ThreadNode<int>(6);
}
template <class T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T>* current) {
	auto p = current;
	while(p->ltag == 0) p = p->leftChild;
	return p;
}


template <class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T>* current) {
	auto p = current;
	while(p->rtag == 0) p = p->rightChild;
	return p;
}

template <class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T>* current) {
	if (current->rtag == 1) return current->rightChild;
	return First(current->rightChild);
}


template <class T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T>* current) {
	if (current->ltag == 1) return current->leftChild;
	return Last(current->leftChild);
}

template <class T>
void ThreadTree<T>::Inorder(void (*visit)(ThreadNode<T> *p)) {
	for (auto p = First(root); p != nullptr; p = Next(p)) visit(p);
}

template <class T>
void ThreadTree<T>::createInThread() {
	ThreadNode<T> *pre = nullptr;
	if (root != nullptr) {
		createInThread(root,pre);
		pre->rightChild = nullptr;
		pre->rtag = 1;
	}
}

template <class T>
void ThreadTree<T>::createInThread(ThreadNode<T>* current,ThreadNode<T>*& pre) {
	if (current == nullptr) return;
	createInThread(current->leftChild,pre);
	if (current->leftChild == nullptr) {
		current->leftChild = pre;
		current->ltag = 1;
	}
	if (pre != nullptr && pre->rightChild == nullptr) {
		pre->rightChild = current;
		pre->rtag = 1;
	}
	pre = current;
	createInThread(current->rightChild,pre);
}

template <class T>
void ThreadTree<T>::Preorder(void (*visit)(ThreadNode<T> *p)) {
	auto p = root;
	while(p != nullptr) {
		visit(p);
		// next node is left child
		if (p->ltag == 0) p = p->leftChild;
		// next node is right child
		else if (p->rtag == 0) p = p->rightChild;
		// leaf node, search its ancestors util the one that has right subtree
		else {
			while (p != nullptr && p->rtag == 1)
				p = p->rightChild;
			if (p != nullptr) p = p->rightChild;
		}
	}
}

template <class T>
ThreadNode<T>* ThreadTree<T>::parent(ThreadNode<T> *t) {
	if (t == root) return nullptr;
	auto p = t;
	for (;p->ltag==0;p = p->leftChild);
	if (p->leftChild) {
		for (p = p->leftChild; p != nullptr && p->leftChild != t && p->rightChild != t; p = p->rightChild)
		;
	}
	if (p == nullptr || !p->leftChild) {
		for (p = t;p->rtag == 0; p = p->rightChild)
		;
		for (p = p->rightChild; p != nullptr && p->leftChild != t && p->rightChild != t; p = p->leftChild)
		;
	}
	return p;
}

template <class T>
void ThreadTree<T>::Postorder(void (*visit)(ThreadNode<T> *p)) {
	ThreadNode<T> *t = root;
	while (t->ltag == 0 || t->rtag == 0) {
		if (t->ltag == 0) t = t->leftChild;
		else if (t->rtag == 0) t = t->rightChild;
	}
	visit(t);
	auto p = t;

	while ((p = parent(t)) != nullptr) {
		// t is right child of p
		// or t is left child of p but p don't have a right child
		if (p->rightChild == t || p->rtag == 1) {
			t = p;
		} else {
			t = p->rightChild;
			while (t->ltag == 0 || t->rtag == 0) {
				if (t->ltag == 0) t = t->leftChild;
				else if (t->rtag == 0) t = t->rightChild;
			}
		}
		visit(t);
	}
}
