#include "binary_tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

template <class T>
string getExpr(BinTreeNode<T> *root,bool is_root = true) {
	if (!root) return "";
	string s;
	if ((root->leftChild || root->rightChild)&&!is_root)
		s += "(";
	s += getExpr(root->leftChild,false)+root->data+getExpr(root->rightChild,false);
	if ((root->leftChild || root->rightChild)&&!is_root)
		s += ")";
	return s;
}

int main() {
	auto bt = BinaryTree<char>();
	bt.setRoot(new BinTreeNode<char>('*'));
	auto root = bt.getRoot();
	root->leftChild = new BinTreeNode<char>('+');
	root->rightChild = new BinTreeNode<char>('*');
	root->leftChild->leftChild = new BinTreeNode<char>('a');
	root->leftChild->rightChild = new BinTreeNode<char>('b');
	root->rightChild->leftChild = new BinTreeNode<char>('c');
	root->rightChild->rightChild = new BinTreeNode<char>('-');
	root->rightChild->rightChild->rightChild = new BinTreeNode<char>('d');
	cout << getExpr(root) << endl;
	bt.setRoot(new BinTreeNode<char>('+'));
	root = bt.getRoot();
	root->leftChild = new BinTreeNode<char>('*');
	root->leftChild->leftChild = new BinTreeNode<char>('a');
	root->leftChild->rightChild = new BinTreeNode<char>('b');
	root->rightChild = new BinTreeNode<char>('-');
	root->rightChild->rightChild = new BinTreeNode<char>('-');
	root->rightChild->rightChild->leftChild = new BinTreeNode<char>('c');
	root->rightChild->rightChild->rightChild = new BinTreeNode<char>('d');
	cout << getExpr(root) << endl;
	return 0;
}