#include <iostream>
#include <vector>
using namespace std;
template <class T>
T kthElem(vector<T> &v,int low,int high,int k) {
	if (low > high){
		// error handling
	}
	T pivot = v[low];
	int i = low;
	for (int j = low+1; j <= high; j++) {
		if (v[j] < pivot) {
			swap(v[++i],v[j]);
		}
	}
	swap(v[i],v[low]);
	int num = i - low + 1;
	if (num == k) return v[i];
	else if (num < k) return kthElem(v,i+1,high,k-num);
	else return kthElem(v,low,i-1,k);
} 
int main() {
	vector<int> a = {1,2,3,4,5,6};
	cout << kthElem(a,0,a.size()-1,3) << endl;
	cout << kthElem(a,0,a.size()-1,5) << endl;
	return 0;
}