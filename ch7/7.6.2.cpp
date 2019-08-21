#include <iostream>
using namespace std;
// time complexity O(m+n)
// space complexity O(m+n)
void merge(int *p,int m,int n) {
	int *copy = new int[m+n];
	for (int i = 0; i < m+n; i++){
		copy[i] = p[i];
	}
	int p1 = 0,p2 = m;
	int i = 0;
	while (p1 < m && p2 < m+n) {
		p[i++] = copy[p1] < copy[p2] ? copy[p1++] : copy[p2++];
	}
	while (p1 < m) {
		p[i++] = copy[p1++];
 	}
 	while (p2 < m+n) {
 		p[i++] = copy[p2++];
 	}
 	delete[] copy;
}

int main() {
	int a[] = {1,3,5,8,2,4,6,7};
	merge(a,4,4);
	for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
		cout << a[i] << " ";
	}
	return 0;
}