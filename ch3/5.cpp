#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::cout;
using std::endl;
constexpr int max_size = 5;
template<class T>
class shared_stack{
public:
	shared_stack(): top1_(-1),top2_(max_size){}
	bool full(int which) const{
		verify_which(which); 
		return top1_ == top2_ - 1;
	}
	bool empty(int which) const{
		verify_which(which);
		if (which == 1) {
			return top1_ == -1;
		} else {
			return top2_ == max_size; 
		}
	}
	void push(int which, const T& elem) {
		verify_which(which);
		if (full(which)) {
			throw runtime_error("stack is full");
		}
		if (which == 1) {
			array_[++top1_] = elem;
		} else {
			array_[--top2_] = elem;
		}
	}
	void pop(int which) {
		verify_which(which);
		if (empty(which)) {
			throw runtime_error("stack is empty");
		}
		if (which == 1) top1_--;
		else top2_++;
	}
	T top(int which) {
		verify_which(which);
		if (which == 1) return array_[top1_];
		else return array_[top2_];
	}
	void show(int which) {
		verify_which(which);
		cout << "stack " << which << endl;
		if (which == 1) {
			for (int i = top1_; i >= 0; i--) {
				cout << array_[i] << endl;
				cout << "---------" << endl;
			}
		} else {
			for (int i = top2_; i < max_size; i++) {
				cout << array_[i] << endl;
				cout << "---------" << endl;
			}
		}
	}
private:
	void verify_which(int which) const{
		if (which != 1 && which != 2) {
			throw runtime_error("invalid stack id,valid id 1, 2");
		}
	}
	int top1_,top2_;
	T array_[max_size] = {};
};

int main() {
	shared_stack<char> s;
	s.push(1,'r');
	s.push(2,'u');
	s.push(1,'o');
	s.push(2,'k');
	s.show(1);
	s.show(2);
	s.pop(1);
	s.pop(1);
	s.show(1);
	s.pop(1);
	return 0;
}