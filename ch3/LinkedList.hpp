#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_set>
#include <type_traits>
using std::vector;
using std::endl;
using std::ostream;
using std::runtime_error;
using std::cout;
using std::unordered_set;
using std::enable_if;
using std::is_base_of;

template<class ElemType>
struct LNode {
public:
	LNode* next;
	ElemType data;
	LNode(ElemType data):data(data),next(nullptr) {}
};

template<class ElemType>
void print_linked_list(LNode<ElemType>* L) {
	bool flag = false;
	while (L != nullptr) {
		cout <<(flag ? "->":"")<< L->data;
		L = L->next;
		flag = true;
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
public:
	DoubleLNode* prev;
	DoubleLNode* next;
	ElemType data;
	DoubleLNode(ElemType data):data(data),next(nullptr),prev(nullptr) {}
};

template<template <class...> class Node, class ElemType>
class LinkedListBase{
public:
	using NodeType = Node<ElemType>;
	LinkedListBase(bool has_dummy_head = true, bool is_cyclic = false):has_dummy_head_(has_dummy_head),is_cyclic_(is_cyclic) {
		if (has_dummy_head_) {
			head_ = generate_dummy_head();
		} else {
			head_ = nullptr;
		}
	}
	void init(const vector<ElemType> &v) {
		NodeType* last_node = list_set_up(v);
		if (is_cyclic_) {
			cyclic_set_up(last_node);
		}
	}
	NodeType* get_head() const{
		return head_;
	}
	void set_head(NodeType* new_head) {
		if (new_head == nullptr) has_dummy_head_ = false;
		head_ = new_head;
	}
	virtual ~LinkedListBase() {
		auto p = head_;
		if (!is_cyclic_) {
			while (p != nullptr) {
				auto next_p = p->next;
				delete p;
				p = next_p;
			}
		} else {
			if (!p) return;
			p = head_->next;
			if (p == nullptr) {
				delete head_;
				return;
			}
			do{
				auto next_p = p->next;
				delete p;
				p = next_p;
			}while (p != head_);
			delete head_;
		}
	}

protected:
	NodeType* generate_dummy_head() const {
		auto dummy_head = new NodeType(ElemType());
		return dummy_head;
	}
	virtual NodeType* list_set_up(const vector<ElemType> &v) {
		NodeType* node;
		if (has_dummy_head_) {
			head_ = generate_dummy_head();
			auto p = head_;
			for (auto &item : v) {
				node = new NodeType(item);
				p->next = node;
				p = p->next;
			}
		} else {
			head_ = new NodeType(v[0]);
			auto p = head_;
			for (auto it = v.begin()+1; it != v.end(); it++) {
				node = new NodeType(*it);
				p->next = node;
				p = p->next;
			}
		}
		// return the last node for cyclic set up
		return node;
	}
	virtual void cyclic_set_up(NodeType* node) {
		node->next = head_;
	}
	friend ostream& operator<<(ostream& os, const LinkedListBase& linked_list) {
		auto p = (linked_list.has_dummy_head_ ? linked_list.head_->next : linked_list.head_);
		if (p == nullptr) {
			os << "empty linked list" << endl;
			return os;
		}
		bool flag = false;
		if (!linked_list.is_cyclic_) {
			while (p != nullptr) {
				os << (flag ? "->" : "") << p->data;
				p = p->next;
				flag = true;
			}
		} else {
			do {
				os << (flag ? "->" : "") << p->data;
				p = p->next;
				flag = true;
			} while (p != linked_list.head_);
		}
		os << endl;
		return os;
	}
	bool is_cyclic_;
	bool has_dummy_head_;
	NodeType* head_;
};

template<template <class...> class Node, class ElemType,class = void>
class LinkedList:public LinkedListBase<Node,ElemType>{
public:
	LinkedList() = delete;
};

template<template <class...> class Node, class ElemType>
class LinkedList<Node,ElemType,typename enable_if<is_base_of<LNode<ElemType>,Node<ElemType>>::value>::type>:public LinkedListBase<Node,ElemType>{
public:
	LinkedList(bool has_dummy_head = true, bool is_cyclic = false):LinkedListBase<Node,ElemType>(has_dummy_head,is_cyclic){}
};

template<template <class...> class Node, class ElemType>
class LinkedList<Node,ElemType,typename enable_if<is_base_of<DoubleLNode<ElemType>,Node<ElemType>>::value>::type>:public LinkedListBase<Node,ElemType>{
public:
	using NodeType = Node<ElemType>;
	LinkedList(bool has_dummy_head = true, bool is_cyclic = false):LinkedListBase<Node,ElemType>(has_dummy_head,is_cyclic){}
private:	
	virtual NodeType* list_set_up(const vector<ElemType> &v) override{
		NodeType* node;
		if (this->has_dummy_head_) {
			auto p = this->head_;
			for (auto &item : v) {
				node = new NodeType(item);
				p->next = node;
				node->prev = p;
				p = p->next;
			}
		} else {
			this->head_ = new NodeType(v[0]);
			auto p = this->head_;
			for (auto it = v.begin()+1; it != v.end(); it++) {
				node = new NodeType(*it);
				p->next = node;
				node->prev = p;
				p = p->next;
			}
		}
		// return the last node for cyclic set up
		return node;
	}
	virtual void cyclic_set_up(NodeType* node) override{
		this->head_->prev = node;
		node->next = this->head_;
	}
};

