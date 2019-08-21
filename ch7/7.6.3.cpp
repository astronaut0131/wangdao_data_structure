#include <iostream>
#include <vector>
using namespace std;
vector<int> count_sort(const vector<int> &v){
	vector<int> result(v.size());
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] < v[i]) cnt++;
		}
		result[cnt] = v[i];
	}
	return result;
}
int main() {
	vector<int> a = {3,1,5,4,2,6,8,7,9};
	auto ret = count_sort(a);
	for (auto i : ret){
		cout << i << " ";
	}
	return 0;
}