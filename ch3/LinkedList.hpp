#include <iostream>
#include <stdexcept>
#include <vector>
using std::vector;
using std::endl;
using std::ostream;
using std::runtime_error;
using std::cout;
template<class ElemType>
struct LNode {
	LNode* next;
	ElemType data;
	LNode(ElemType data):data(data),next(nullptr) {}
};

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
		auto p = has_dummy_head_ ? head_->next : head_;
		while (p != nullptr) {
			auto next_p = p->next;
			delete p;
			p = next_p;
		}
	}
private:
	NodeType* generate_dummy_head() {
		auto dummy_head = new NodeType({});
		return dummy_head;
	}
	bool has_dummy_head_;
	NodeType* head_;
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
		auto p = has_dummy_head_ ? head_->next : head_;
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
		NodeType* dummy_head = new NodeType({});
		return dummy_head;
	}
	bool has_dummy_head_;
	NodeType* head_;
};