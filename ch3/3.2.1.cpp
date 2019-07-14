#include <iostream>
using std::cout;
using std::endl;
#define MAXSIZE 5
typedef int ElementType ;
struct recur_queue{
	int front,rear;
	int data[MAXSIZE];
	int tag;
	recur_queue():tag(0),front(0),rear(0) {};
};

bool Enqueue(recur_queue& Q,ElementType x) {
	if (Q.front == Q.rear && Q.tag == 1) {
		std::cout << "Queue is full" << std::endl;
		// full
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear+1) % MAXSIZE;
	Q.tag = 1;
	return true;
}

bool Dequeue(recur_queue& Q,ElementType& ret) {
	if (Q.front == Q.rear && Q.tag == 0) {
		std::cout << "Queue is empty" << std::endl;
		// empty
		return false;
	}
	ret = Q.data[Q.front];
	Q.front = (Q.front+1) % MAXSIZE;
	Q.tag = 0;
	return true;
}

int main() {
	recur_queue r;
	ElementType x;
	Dequeue(r,x);
	Enqueue(r,1);
	Enqueue(r,2);
	Enqueue(r,3);
	Enqueue(r,4);
	Enqueue(r,5);
	Enqueue(r,6);
	Dequeue(r,x);
	Dequeue(r,x);
	Dequeue(r,x);
	Dequeue(r,x);
	Dequeue(r,x);
	Dequeue(r,x);
	return 0;
}