#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_set>
using std::vector;
using std::endl;
using std::ostream;
using std::runtime_error;
using std::cout;
using std::unordered_set;
template<class ElemType>
struct LNode {
	LNode* next;
	ElemType data;
	LNode(ElemType data):data(data),next(nullptr) {}
};

template<class ElemType>
void print_linked_list(LNode<ElemType>* L) {
	while (L != nullptr) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}

template<class ElemType>
void free_linked_list(LNode<ElemType>* L) {
	while (L != nullptr) {
		auto next_L = L->next;
		delete L;
		L = next_L;
	}
	cout << endl;
}

template<class ElemType>
LNode<ElemType>* generate_dummy_head() {
	auto dummy_head = new LNode<ElemType>(ElemType());
	return dummy_head;
}

template<class ElemType>
struct DoubleLNode {
	DoubleLNode* prev;
	DoubleLNode* next;
	ElemType data;
	DoubleLNode(ElemType data):data(data),next(nullptr),prev(nullptr) {}
};

template<class ElemType>
class LinkedList{
public:
	using NodeType = LNode<ElemType>;
	// get an empty linked list with a dummy head
	LinkedList(bool has_dummy_head = true):has_dummy_head_(has_dummy_head) {
		if (has_dummy_head)
			head_ = generate_dummy_head();
		else
			head_ = nullptr;
	}
	LinkedList(vector<ElemType>& v, bool has_dummy_head = true):has_dummy_head_(has_dummy_head) {
		if (v.size() == 0) throw runtime_error("empty vector...");
		if (has_dummy_head) {
			head_ = generate_dummy_head();
			auto p = head_;
			for (auto &item : v) {
				auto node = new NodeType(item);
				p->next = node;
				p = p->next;
			}
		} else {
			head_ = new NodeType(v[0]);
			auto p = head_;
			for (auto it = v.begin()+1; it != v.end(); it++) {
				auto node = new NodeType(*it);
				p->next = node;
				p = p->next;
			}
		}
	}
	NodeType* get_head() {
		return head_;
	}
	void set_head(NodeType* new_head) {
		head_ = new_head;
	}
	LinkedList& concatenate(LinkedList& other) {
		auto p = has_dummy_head_ ? head_->next : head_;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = other.has_dummy_head_ ? other.get_head()->next : other.get_head();
		p = p->next;
		while (p != nullptr) {
			node_shared_.insert(p);
			p = p->next;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, LinkedList& linked_list) {
		auto p = (linked_list.has_dummy_head_ ? linked_list.head_->next : linked_list.head_);
		if (p == nullptr) {
			os << "empty linked list" << endl;
			return os;
		}
		while (p != nullptr) {
			os << p->data << " ";
			p = p->next;
		}
		os << endl;
		return os;
	}
	~LinkedList() {
		auto p = head_;
		while (p != nullptr) {
			auto next_p = p->next;
			if (node_shared_.find(p) == node_shared_.end()) {
				delete p;
			}
			p = next_p;
		}
	}
private:
	NodeType* generate_dummy_head() {
		auto dummy_head = new NodeType(ElemType());
		return dummy_head;
	}
	bool has_dummy_head_;
	NodeType* head_;
	unordered_set<NodeType*> node_shared_;
};

template<class ElemType>
class DoubleLinkedList{
	using NodeType = DoubleLNode<ElemType>;
public:
	DoubleLinkedList(vector<ElemType>& v, bool has_dummy_head = true):has_dummy_head_(has_dummy_head) {
		if (v.size() == 0) throw runtime_error("empty vector...");
		if (has_dummy_head) {
			head_ = generate_dummy_head();
			auto p = head_;
			for (auto &item : v) {
				auto node = new NodeType(item);
				p->next = node;
				p = p->next;
			}
		} else {
			head_ = new NodeType(v[0]);
			auto p = head_;
			for (auto it = v.begin()+1; it != v.end(); it++) {
				auto node = new NodeType(*it);
				p->next = node;
				p = p->next;
			}
		}
	}
	NodeType* get_head() const{
		return head_;
	}
	void set_head(NodeType* new_head) {
		head_ = new_head;
	}
	friend ostream& operator<<(ostream& os, DoubleLinkedList& linked_list) {
		auto p = linked_list.has_dummy_head_ ? linked_list.head_->next : linked_list.head_;
		if (p == nullptr) {
			os << "empty linked list" << endl;
			return os;
		}
		os << p->data << " ";
		p = p->next;
		while (p != linked_list.head_) {
			os << p->data << " ";
			p = p->next;
		}
		os << endl;
		return os;
	}
	~DoubleLinkedList() {
		auto p = head_;
		if (p == nullptr) return;
		auto next_p = p->next;
		delete p;
		p = next_p;
		while (p != head_) {
			next_p = p->next;
			delete p;
			p = next_p;
		}
	}
private:
	NodeType* generate_dummy_head() {
		NodeType* dummy_head = new NodeType(ElemType());
		return dummy_head;
	}
	bool has_dummy_head_;
	NodeType* head_;
};
