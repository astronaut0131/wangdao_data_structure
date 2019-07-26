#include "thread_tree.hpp"
using namespace std;
template <class T>
void visit(ThreadNode<T>* node) {
	cout << node->data << " ";
}
int main() {
	auto thread_tree = ThreadTree<int>();
	thread_tree.generate_test_tree();
	thread_tree.createInThread();
	thread_tree.Preorder(visit);
	cout << endl;
	thread_tree.Inorder(visit);
	cout << endl;
	thread_tree.Postorder(visit);
	return 0;
}