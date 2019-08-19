#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template <class T>
int partition(vector<T>& a,int low,int high) {
	int pivotpos = rand() % (high-low+1) + low;
	T pivot = a[pivotpos];
	swap(a[pivotpos],a[low]);
	int i = low;
	for (int j = low + 1; j <= high; j++) {
		if (a[j] < pivot) {
			swap(a[++i],a[j]);
		}
	}
	swap(a[i],a[low]);
	return i;
}

template <class T>
void quick_sort(vector<T>& v,int low,int high) {
	if (low < high) {
		int pivotpos = partition(v,low,high);
		quick_sort(v,low,pivotpos-1);
		quick_sort(v,pivotpos+1,high);
	}
}
int main() {
	vector<int> a = {3,2,1,-1,5,4,7,6,8,9};
	quick_sort(a,0,a.size()-1);
	for (auto i : a) {
		cout << i << " ";
	}
	return 0;
}