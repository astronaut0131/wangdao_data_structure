#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
int binary_search(const vector<T> v,int low, int high, const T target) {
	if (low > high) return -1;
	int mid = (low+high)/2;
	if (target == v[mid-1]) return mid-1;
	else if (target > v[mid-1]) return binary_search(v,mid+1,high,target);
	else return binary_search(v,low,mid-1,target);
}
int main() {
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	cout << binary_search(v,1,v.size(),0) << endl;
	cout << binary_search(v,1,v.size(),9) << endl;
	cout << binary_search(v,1,v.size(),10) << endl;
	return 0;
}