#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int partition(vector<int> &v) {
	int half_size = v.size()/2;
	int s1 = 0,s2 = 0,low = 0, high = v.size()-1;
	while (1) {
		int pivot = v[low];
		int i = low;
		for (int j = low+1; j <= high; j++) {
			if (v[j] < pivot) {
				swap(v[++i],v[j]);
			}
		}
		swap(v[i],v[low]);
		if (i == half_size) {
			// finish
			break;
		} else if (i < half_size) {
			low = i+1;
		} else {
			high = i-1;
		}
	}
	for (int i = 0; i < half_size; i++) {
		s1 += v[i];
	}
	for (int i = half_size; i < v.size(); i++) {
		s2 += v[i];
	}
	return abs(s2 - s1);
}
int main() {
	vector<int> v = {1,2,3,4,5,6,7};
	cout << partition(v) << endl;
	vector<int> v2 = {3,1,2,5,4,7,6};
	cout << partition(v2) << endl;
	return 0;
}