#include<iostream>
#include<queue>
using namespace std;
queue<int> dispatch(queue<int> &car_a,queue<int> &car_b) {
	queue<int> ret;
	while (ret.size() != 10) {
		for (int i = 0;i<4&&!car_a.empty();i++){
			ret.push(car_a.front());
			car_a.pop();
		}
		if (!car_b.empty()) {
			ret.push(car_b.front());
			car_b.pop();
		}
	}
	return ret;
}
int main() {
// 	queue<int> a({1,2,3,4,5});
// 	queue<int> b({-1,-2,-3,-4,-5});

 	queue<int> a({1,2,3,4,5,6,7,8,9});
 	queue<int> b({-1});
	auto ret = dispatch(a,b);
	while (!ret.empty()) {
		cout << ret.front() << " ";
		ret.pop();
	}
	return 0;
}